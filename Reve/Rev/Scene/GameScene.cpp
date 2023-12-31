#include "GameScene.h"
#include<DxLib.h>
#include"Manager/InputManager.h"
#include"ResultScene.h"
#include"Manager/SceneManager.h"
#include"PauseScene.h"
GameScene::GameScene(SceneManager& manager) :BaseScene(manager)
{
	camera_ = std::make_unique<Camera>();
}

bool GameScene::Init()
{
	player_ = std::make_unique<Player>();
	player_->Init();

	stage_ = std::make_unique<Stage>();
	stage_->Init();

//	actor_.push_front(std::make_unique<Enemy>());
	sceneManager_.GetCamera()->SetPlayerPos(&player_->GetTransform());
	sceneManager_.GetCamera()->ChangeMode(Camera::MODE::FOLLOW);
	return true;
}

void GameScene::Update(InputManager& input)
{
	//fps = GetFPS();
	if (input.IsTriggered("next"))
	{
		sceneManager_.ChangeScene(std::make_shared<ResultScene>(sceneManager_));
	}
	else if (input.IsTriggered("pause"))
	{
		sceneManager_.PushScene(std::make_shared<PauseScene>(sceneManager_));
	}

	/*for (const auto& o : actor_)
	{
		o->Update();
	}*/

	player_->Update();
	stage_->Update();
}

void GameScene::Draw()
{
	//DrawFormatString(50, 50, 0xffffff, "fps");
	DrawString(50, 50, "Game Scene", 0xffffff, true);
	/*for (const auto& o : actor_)
	{
		o->Draw();
	}*/
	player_->Draw();
	stage_->Draw();

}

void GameScene::Release()
{
	player_->Release();
	stage_->Release();
}
