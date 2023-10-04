#include <DxLib.h>
#include "Resource.h"
#include "ResourceManager.h"
ResourceManager* ResourceManager::instance_ = nullptr;

const std::string ResourceManager::PATH_IMAGE = "../Assets/Texture/";
const std::string ResourceManager::PATH_MODEL = "../Assets/Model/";
const std::string ResourceManager::PATH_EFFECT = "../Assets/Effect/";

int ResourceManager::LoadModel(const std::string& filePath)
{
	int modelHandle = MV1LoadModel(filePath.c_str());
	if (modelHandle == -1)
	{
		MessageBox(NULL, (LPCSTR)("モデルの読み込みに失敗しました: " + filePath).c_str(), "エラー", MB_OK | MB_ICONERROR);
		exit(EXIT_FAILURE);
	}
	return modelHandle;
}

void ResourceManager::ReleaseModel(int modelHandle)
{
	MV1DeleteModel(modelHandle);
}

void ResourceManager::CreateInstance(void)
{
	if (instance_ == nullptr)
	{
		instance_ = new ResourceManager();
	}
	instance_->Init();
}

ResourceManager& ResourceManager::GetInstance(void)
{
	return *instance_;
}

void ResourceManager::Init(void)
{

	// 推奨しませんが、どうしても使いたい方は
	using RES = Resource;
	using RES_T = RES::TYPE;

	Resource* res;

	// タイトル画像
	res = new RES(RES_T::IMG, PATH_IMAGE + "Title.png");
	resourcesMap_.emplace(SRC::TITLE, res);

	// PushSpace
	res = new RES(RES_T::IMG, PATH_IMAGE + "PushSpace.png");
	resourcesMap_.emplace(SRC::PUSH_SPACE, res);

	// 吹き出し
	res = new RES(RES_T::IMG, PATH_IMAGE + "SpeechBalloon.png");
	resourcesMap_.emplace(SRC::SPEECH_BALLOON, res);

	// プレイヤー
	res = new RES(RES_T::MODEL, PATH_MODEL + "Player/Player.mv1");
	resourcesMap_.emplace(SRC::PLAYER, res);

	// プレイヤー影
	res = new RES(RES_T::IMG, PATH_IMAGE + "Shadow.png");
	resourcesMap_.emplace(SRC::PLAYER_SHADOW, res);

	// スカイドーム
	res = new RES(RES_T::MODEL, PATH_MODEL + "SkyDome/SkyDome.mv1");
	resourcesMap_.emplace(SRC::SKY_DOME, res);

	// 最初の惑星
	res = new RES(RES_T::MODEL, PATH_MODEL + "Planet/MainPlanet.mv1");
	resourcesMap_.emplace(SRC::MAIN_PLANET, res);

	// 落とし穴の惑星
	res = new RES(RES_T::MODEL, PATH_MODEL + "Planet/FallPlanet.mv1");
	resourcesMap_.emplace(SRC::FALL_PLANET, res);

	// 平坦な惑星01
	res = new RES(RES_T::MODEL, PATH_MODEL + "Planet/FlatPlanet01.mv1");
	resourcesMap_.emplace(SRC::FLAT_PLANET_01, res);

	// 平坦な惑星02
	res = new RES(RES_T::MODEL, PATH_MODEL + "Planet/FlatPlanet02.mv1");
	resourcesMap_.emplace(SRC::FLAT_PLANET_02, res);

	// 最後の惑星
	res = new RES(RES_T::MODEL, PATH_MODEL + "Planet/LastPlanet.mv1");
	resourcesMap_.emplace(SRC::LAST_PLANET, res);

	// 特別な惑星
	res = new RES(RES_T::MODEL, PATH_MODEL + "Planet/RoadPlanet.mv1");
	resourcesMap_.emplace(SRC::SPECIAL_PLANET, res);

	// 足煙
	res = new RES(RES_T::EFFEKSEER, PATH_EFFECT + "Smoke/Smoke.efkefc");
	resourcesMap_.emplace(SRC::FOOT_SMOKE, res);

	// ワープスターモデル
	res = new RES(RES_T::MODEL, PATH_MODEL + "Star/star.mv1");
	resourcesMap_.emplace(SRC::WARP_STAR, res);

	// ワープスター用回転エフェクト
	res = new RES(RES_T::EFFEKSEER, PATH_EFFECT + "StarDust/StarDust.efkefc");
	resourcesMap_.emplace(SRC::WARP_STAR_ROT_EFF, res);

	// ワープの軌跡線
	res = new RES(RES_T::EFFEKSEER, PATH_EFFECT + "Warp/WarpOrbit.efkefc");
	resourcesMap_.emplace(SRC::WARP_ORBIT, res);

	// ブラックホール
	res = new RES(RES_T::EFFEKSEER, PATH_EFFECT + "BlackHole/BlackHole.efkefc");
	resourcesMap_.emplace(SRC::BLACK_HOLE, res);

	// ゴール
	res = new RES(RES_T::MODEL, PATH_MODEL + "GoalStar/GoalStar.mv1");
	resourcesMap_.emplace(SRC::GOAL_STAR, res);

	// Clear
	res = new RES(RES_T::IMG, PATH_IMAGE + "Congratulations.png");
	resourcesMap_.emplace(SRC::CLEAR, res);

}

void ResourceManager::Release(void)
{
	for (auto& p : loadedMap_)
	{
		p.second.Release();
	}

	loadedMap_.clear();
}

void ResourceManager::Destroy(void)
{
	Release();
	for (auto& res : resourcesMap_)
	{
		res.second->Release();
		delete res.second;
	}
	resourcesMap_.clear();
	delete instance_;
}

const Resource& ResourceManager::Load(SRC src)
{
	Resource& res = _Load(src);
	if (res.type_ == Resource::TYPE::NONE)
	{
		return dummy_;
	}
	return res;
}

int ResourceManager::LoadModelDuplicate(SRC src)
{
	Resource& res = _Load(src);
	if (res.type_ == Resource::TYPE::NONE)
	{
		return -1;
	}

	int duId = MV1DuplicateModel(res.handleId_);
	res.duplicateModelIds_.push_back(duId);

	return duId;
}

ResourceManager::ResourceManager(void)
{
}

Resource& ResourceManager::_Load(SRC src)
{

	// ロード済みチェック
	const auto& lPair = loadedMap_.find(src);
	if (lPair != loadedMap_.end())
	{
		return *resourcesMap_.find(src)->second;
	}

	// リソース登録チェック
	const auto& rPair = resourcesMap_.find(src);
	if (rPair == resourcesMap_.end())
	{
		// 登録されていない
		return dummy_;
	}

	// ロード処理
	rPair->second->Load();

	// 念のためコピーコンストラクタ
	loadedMap_.emplace(src, *rPair->second);

	return *rPair->second;

}
