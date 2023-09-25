#include "GameScene.h"
#include<DxLib.h>
#include"Manager/InputManager.h"
#include"ResultScene.h"
#include"Manager/SceneManager.h"
#include"PauseScene.h"
GameScene::GameScene(SceneManager& manager) :BaseScene(manager)
{

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
}

void GameScene::Draw()
{
	//DrawFormatString(50, 50, 0xffffff, "fps");
	DrawString(50, 50, "Game Scene", 0xffffff, true);
}
