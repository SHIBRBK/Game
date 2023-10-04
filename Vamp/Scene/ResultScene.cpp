#include "ResultScene.h"
#include"TitleScene.h"

ResultScene::ResultScene() :BaseScene()
{
    
}

bool ResultScene::Init()
{
    return true;
}

void ResultScene::Update()
{
    // ƒV[ƒ“‘JˆÚ
    InputManager& input = InputManager::GetInstance();
    if (input.IsTriggered("next"))
    {
        SceneManager::GetInstance().ChangeScene(SceneManager::SCENE_ID::TITLE);
    }
}

void ResultScene::Draw()
{
    DrawString(50, 50, "Result Scene", 0xffffff, true);
}