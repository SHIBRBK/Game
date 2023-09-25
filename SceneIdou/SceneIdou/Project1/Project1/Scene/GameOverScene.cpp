#include "GameOverScene.h"
#include<DxLib.h>
#include"../Input.h"
#include"TitleScene.h"
#include"SceneManager.h"

GameOverScene::GameOverScene(SceneManager& manager):Scene(manager)
{

}
void GameOverScene::Update(Input& input)
{
	if (input.IsTriggered("next"))
	{
		sceneManager_.ChangeScene(std::make_shared<TitleScene>(sceneManager_));
	}
}

void GameOverScene::Draw()
{
	DrawString(50, 50, "GameOver Scene", 0xffffff, true);
}
