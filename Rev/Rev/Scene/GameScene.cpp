#include<DxLib.h>
#include "GameScene.h"
#include "ResultScene.h"
#include"Manager/SceneManager.h"
#include"Manager/InputManager.h"
#include"PauseScene.h"
GameScene::GameScene(SceneManager& manager) :BaseScene(manager)
{
}

GameScene::~GameScene()
{
}

bool GameScene::Init()
{
    return true;
}

void GameScene::Update(InputManager& input)
{
	if (input.IsTriggered("next"))
	{
		sceneManager_.ChangeScene(std::make_shared<ResultScene>(sceneManager));
	}
	else if (input.IsTriggered("pause"))
	{
		sceneManager_.PushScene(std::make_shared<PauseScene>(sceneManager));
	}
}

void GameScene::Draw()
{
}
