#include<DxLib.h>
#include "TitleScene.h"
#include"SelectScene.h"
#include "KeyConfigScene.h"
#include "Manager/InputManager.h"
#include"Manager/SceneManager.h"
TitleScene::TitleScene(SceneManager& manager) :BaseScene(manager)
{

}

void TitleScene::Update(InputManager& input)
{
	if (input.IsTriggered("next"))
	{
		sceneManager_.ChangeScene(std::make_shared<SelectScene>(sceneManager_));
	}
	else if (input.IsTriggered("keyconfig"))
	{
		sceneManager_.PushScene(std::make_shared<KeyConfigScene>(sceneManager_));
	}
}

void TitleScene::Draw()
{
	DrawString(50, 50, "Title Scene", 0xffffff, true);
}
