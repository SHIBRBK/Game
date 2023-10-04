#include "GameScene.h"
#include "ResultScene.h"

GameScene::GameScene() :BaseScene()
{
    player_ = std::make_unique<Player>();
    stage_ = std::make_unique<Stage>();
    //skyDome_ = std::make_unique<SkyDome>(player_->GetTransform());
}


bool GameScene::Init()
{
    player_->Init();

    stage_->Init();

    //skyDome_->Init();

    SceneManager::GetInstance().GetCamera()->SetPlayerPos(&player_->GetTransform());
    SceneManager::GetInstance().GetCamera()->ChangeMode(Camera::MODE::FIXED_POINT);
    
    return true;
}

void GameScene::Update()
{
    // ƒV[ƒ“‘JˆÚ
    InputManager& input = InputManager::GetInstance();
    if (input.IsTriggered("next"))
    {
        SceneManager::GetInstance().ChangeScene(SceneManager::SCENE_ID::RESULT);
    }
   // skyDome_->Update();
    stage_->Update();
    player_->Update();
}

void GameScene::Draw()
{
   // skyDome_->Draw();
    stage_->Draw();
    player_->Draw();
    DrawString(50, 50, "Game Scene", 0xffffff, true);
}

void GameScene::Release()
{
    //skyDome_->Release();
    stage_->Release();
    player_->Release();
}
