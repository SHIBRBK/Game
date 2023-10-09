#include "GameScene.h"
#include "ResultScene.h"
#include "../Object/WeaponBase.h"
#include"../Object/Enemy.h"

GameScene::GameScene() :BaseScene()
{
    player_ = std::make_shared<Player>();
    enemy_ = std::make_shared<Enemy>();
    stage_ = std::make_unique<Stage>();
    //skyDome_ = std::make_unique<SkyDome>(player_->GetTransform());
}


bool GameScene::Init()
{
    player_->Init();
    enemy_->Init();
    stage_->Init();

    //skyDome_->Init();

    SceneManager::GetInstance().GetCamera()->SetFollow(&player_->GetTransform());
    SceneManager::GetInstance().GetCamera()->ChangeMode(Camera::MODE::FOLLOW);
    
    return true;
}

void GameScene::Update(InputManager& input)
{
    //// ƒV[ƒ“‘JˆÚ
    //InputManager& input = InputManager::GetInstance();
    if (input.IsTriggered("next"))
    {
        SceneManager::GetInstance().ChangeScene(SceneManager::SCENE_ID::RESULT);
    }
   // skyDome_->Update();
    stage_->Update();
    player_->UpdatePlay(input);
    enemy_->Update(*player_);
}

void GameScene::Draw()
{
   // skyDome_->Draw();
    stage_->Draw();
    player_->Draw();
    enemy_->Draw();
    DrawString(50, 50, "Game Scene", 0xffffff, true);
}

void GameScene::Release()
{
    //skyDome_->Release();
    stage_->Release();
    player_->Release();
    enemy_->Release();
}
