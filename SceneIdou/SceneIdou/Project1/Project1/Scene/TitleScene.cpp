#include<DxLib.h>
#include "TitleScene.h"
#include "GameScene.h"
#include "KeyConfigScene.h"
#include "../Input.h"
#include"SceneManager.h"

TitleScene::TitleScene(SceneManager& manager):Scene(manager)
{

}

void TitleScene::Update(Input& input)
{
	if (input.IsTriggered("next"))
	{
		sceneManager_.ChangeScene(std::make_shared<GameScene>(sceneManager_));
	}
	else if (input.IsTriggered("keyconfig"))
	{
		sceneManager_.PushScene(std::make_shared<KeyConfigScene>(sceneManager_));
	}
}

void TitleScene::Draw()
{
	DrawString(50, 50, "Title Scene", 0xffffff,true);
}
