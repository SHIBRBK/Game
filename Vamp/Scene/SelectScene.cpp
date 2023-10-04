#include "SelectScene.h"
#include "GameScene.h"
SelectScene::SelectScene() :BaseScene()
{
   
}

bool SelectScene::Init()
{
    return true;
}

void SelectScene::Update()
{
    // ƒV[ƒ“‘JˆÚ
    InputManager& input = InputManager::GetInstance();
    if (input.IsTriggered("next"))
    {
        SceneManager::GetInstance().ChangeScene(SceneManager::SCENE_ID::GAME);
    }
}

void SelectScene::Draw()
{
    DrawString(50, 50, "Select Scene", 0xffffff, true);
}