#include "GameScene.h"
#include<DxLib.h>
#include"../Input.h"
#include"GameOverScene.h"
#include"SceneManager.h"
#include"PauseScene.h"
GameScene::GameScene(SceneManager& manager):Scene(manager)
{

}

void GameScene::Update(Input& input)
{
	//fps = GetFPS();
	if (input.IsTriggered("next"))
	{
		sceneManager_.ChangeScene(std::make_shared<GameOverScene>(sceneManager_));
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
