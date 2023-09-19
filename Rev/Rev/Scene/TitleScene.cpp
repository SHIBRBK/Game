#include<DxLib.h>
#include "TitleScene.h"
#include "GameScene.h"
//#include "KeyConfigScene.h"
#include "Manager/InputManager.h"
#include"Manager/SceneManager.h"
TitleScene::TitleScene(SceneManager& manager) :BaseScene(manager)
{
}

TitleScene::~TitleScene()
{
}

bool TitleScene::Init()
{
    return true;
}

void TitleScene::Update(InputManager& input)
{
	if (input.IsTriggered("next"))
	{
		sceneManager_.ChangeScene(std::make_shared<GameScene>(sceneManager));
	}
	//else if (input.IsTriggered("keyconfig"))
	//{
	//	sceneManager_.PushScene(std::make_shared<KeyConfigScene>(sceneManager));
	//}
}

void TitleScene::Draw()
{
}
