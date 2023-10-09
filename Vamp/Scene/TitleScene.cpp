#include<DxLib.h>
#include "TitleScene.h"
#include "SelectScene.h"
#include "../Manager/SceneManager.h"

TitleScene::TitleScene() :BaseScene()
{

}

bool TitleScene::Init(void)
{

    return true;
}
void TitleScene::Update(InputManager& input)
{
    // ƒV[ƒ“‘JˆÚ
    //InputManager& input = InputManager::GetInstance();
    if (input.IsTriggered("next"))
    {
        SceneManager::GetInstance().ChangeScene(SceneManager::SCENE_ID::SELECT);
    }
}

void TitleScene::Draw()
{
    DrawString(50, 50, "Title Scene", 0xffffff, true);
}
