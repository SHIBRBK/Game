#include<DxLib.h>
#include "SelectScene.h"
#include "GameScene.h"
#include "Manager/InputManager.h"
#include"Manager/SceneManager.h"
SelectScene::SelectScene(SceneManager& manager) :BaseScene(manager)
{
}


void SelectScene::Update(InputManager& input)
{
	if (input.IsTriggered("next"))
	{
		sceneManager_.ChangeScene(std::make_shared<GameScene>(sceneManager_));
	}
}

void SelectScene::Draw()
{
	DrawString(50, 50, "Select Scene", 0xffffff, true);
}
