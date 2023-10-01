#include "ResultScene.h"
#include<DxLib.h>
#include"Manager/InputManager.h"
#include"TitleScene.h"
#include"Manager/SceneManager.h"

ResultScene::ResultScene(SceneManager& manager) :BaseScene(manager)
{

}
void ResultScene::Update(InputManager& input)
{
	if (input.IsTriggered("next"))
	{
		sceneManager_.ChangeScene(std::make_shared<TitleScene>(sceneManager_));
	}
}

void ResultScene::Draw()
{
	DrawString(50, 50, "GameOver Scene", 0xffffff, true);
}
