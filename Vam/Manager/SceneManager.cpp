#include "SceneManager.h"
#include "../Scene/BaseScene.h"
#include "../Scene/TitleScene.h"
#include "../Scene/SelectScene.h"
#include "../Scene/GameScene.h"
#include "../Scene/ResultScene.h"
#include "InputManager.h"

SceneManager* SceneManager::instance_ = nullptr;

void SceneManager::CreateInstance(void)
{
	if (instance_ == nullptr)
	{
		instance_ = new SceneManager();
	}
	instance_->Init();
}

SceneManager& SceneManager::GetInstance(void)
{
	return *instance_;
}

void SceneManager::ChangeScene(SCENE_ID nextId)
{
	// シーンを変更する
	sceneId_ = nextId;
	//if (scenes_.empty())
	//{
	//	scenes_.push_front(scene);
	//}
	//else
	//{
	//	scenes_.front() = scene;//フロントを入れ替える
	//}
	switch (sceneId_)
	{
	case SCENE_ID::TITLE:
		scene_ = std::make_unique<TitleScene>();
		break;
	case SCENE_ID::SELECT:
		scene_ = std::make_unique<SelectScene>();
		break;
	case SCENE_ID::GAME:
		scene_ = std::make_unique<GameScene>();
		break;
	case SCENE_ID::GAMEOVER:
		scene_ = std::make_unique<ResultScene>();
		break;

	}
}

//void SceneManager::PushScene(std::shared_ptr<BaseScene> scene)
//{
//	//scenes_.push_front(scene);
//}

void SceneManager::PopScene()
{
	//scenes_.pop_front();
}

void SceneManager::Init()
{
	ChangeScene(SCENE_ID::TITLE);
	// カメラ
	camera_ = std::make_unique<Camera>();
	camera_->Init();
	Init3D();
}

void SceneManager::Init3D(void)
{
	SetBackgroundColor(0, 139, 139);

	SetUseZBuffer3D(true);
}

void SceneManager::Update()
{
	//今現在の持ってるシーンを実行
	//scenes_.front()->Update(input);
	SCENE_ID sceneID = scene_->Update();
	if (sceneID != scene_->GetSceneID())
	{
		ChangeScene(sceneID);
	}
}

void SceneManager::Draw()
{
	SetDrawScreen(DX_SCREEN_BACK);
	ClearDrawScreen();
	camera_->SetBeforeDraw();
	scene_->Draw();
	ScreenFlip();
	//auto rit = scenes_.rbegin();
	//for (; rit != scenes_.rend(); rit++)
	//{
	//	(*rit)->Draw();
	//}
}

uniqueConsterCamera SceneManager::GetCamera(void)
{
	return std::move(camera_);
}

SceneManager::SceneManager(void)
{

}

SceneManager::~SceneManager(void)
{
}
