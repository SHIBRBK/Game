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
		MessageBox(NULL, (LPCSTR)("���f���̓ǂݍ��݂Ɏ��s���܂���: " + filePath).c_str(), "�G���[", MB_OK | MB_ICONERROR);
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

	// �������܂��񂪁A�ǂ����Ă��g����������
	using RES = Resource;
	using RES_T = RES::TYPE;

	Resource* res;

	// �^�C�g���摜
	res = new RES(RES_T::IMG, PATH_IMAGE + "Title.png");
	resourcesMap_.emplace(SRC::TITLE, res);

	// PushSpace
	res = new RES(RES_T::IMG, PATH_IMAGE + "PushSpace.png");
	resourcesMap_.emplace(SRC::PUSH_SPACE, res);

	// �����o��
	res = new RES(RES_T::IMG, PATH_IMAGE + "SpeechBalloon.png");
	resourcesMap_.emplace(SRC::SPEECH_BALLOON, res);

	// �v���C���[
	res = new RES(RES_T::MODEL, PATH_MODEL + "Player/Player.mv1");
	resourcesMap_.emplace(SRC::PLAYER, res);

	// �v���C���[�e
	res = new RES(RES_T::IMG, PATH_IMAGE + "Shadow.png");
	resourcesMap_.emplace(SRC::PLAYER_SHADOW, res);

	// �X�J�C�h�[��
	res = new RES(RES_T::MODEL, PATH_MODEL + "SkyDome/SkyDome.mv1");
	resourcesMap_.emplace(SRC::SKY_DOME, res);

	// �ŏ��̘f��
	res = new RES(RES_T::MODEL, PATH_MODEL + "Planet/MainPlanet.mv1");
	resourcesMap_.emplace(SRC::MAIN_PLANET, res);

	// ���Ƃ����̘f��
	res = new RES(RES_T::MODEL, PATH_MODEL + "Planet/FallPlanet.mv1");
	resourcesMap_.emplace(SRC::FALL_PLANET, res);

	// ���R�Șf��01
	res = new RES(RES_T::MODEL, PATH_MODEL + "Planet/FlatPlanet01.mv1");
	resourcesMap_.emplace(SRC::FLAT_PLANET_01, res);

	// ���R�Șf��02
	res = new RES(RES_T::MODEL, PATH_MODEL + "Planet/FlatPlanet02.mv1");
	resourcesMap_.emplace(SRC::FLAT_PLANET_02, res);

	// �Ō�̘f��
	res = new RES(RES_T::MODEL, PATH_MODEL + "Planet/LastPlanet.mv1");
	resourcesMap_.emplace(SRC::LAST_PLANET, res);

	// ���ʂȘf��
	res = new RES(RES_T::MODEL, PATH_MODEL + "Planet/RoadPlanet.mv1");
	resourcesMap_.emplace(SRC::SPECIAL_PLANET, res);

	// ����
	res = new RES(RES_T::EFFEKSEER, PATH_EFFECT + "Smoke/Smoke.efkefc");
	resourcesMap_.emplace(SRC::FOOT_SMOKE, res);

	// ���[�v�X�^�[���f��
	res = new RES(RES_T::MODEL, PATH_MODEL + "Star/star.mv1");
	resourcesMap_.emplace(SRC::WARP_STAR, res);

	// ���[�v�X�^�[�p��]�G�t�F�N�g
	res = new RES(RES_T::EFFEKSEER, PATH_EFFECT + "StarDust/StarDust.efkefc");
	resourcesMap_.emplace(SRC::WARP_STAR_ROT_EFF, res);

	// ���[�v�̋O�Ր�
	res = new RES(RES_T::EFFEKSEER, PATH_EFFECT + "Warp/WarpOrbit.efkefc");
	resourcesMap_.emplace(SRC::WARP_ORBIT, res);

	// �u���b�N�z�[��
	res = new RES(RES_T::EFFEKSEER, PATH_EFFECT + "BlackHole/BlackHole.efkefc");
	resourcesMap_.emplace(SRC::BLACK_HOLE, res);

	// �S�[��
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

	// ���[�h�ς݃`�F�b�N
	const auto& lPair = loadedMap_.find(src);
	if (lPair != loadedMap_.end())
	{
		return *resourcesMap_.find(src)->second;
	}

	// ���\�[�X�o�^�`�F�b�N
	const auto& rPair = resourcesMap_.find(src);
	if (rPair == resourcesMap_.end())
	{
		// �o�^����Ă��Ȃ�
		return dummy_;
	}

	// ���[�h����
	rPair->second->Load();

	// �O�̂��߃R�s�[�R���X�g���N�^
	loadedMap_.emplace(src, *rPair->second);

	return *rPair->second;

}
