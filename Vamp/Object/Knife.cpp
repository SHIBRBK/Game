#include "Knife.h"
#include "Player.h"
#include "../Application.h"
#include "../Manager/SceneManager.h"

Knife::Knife(const Player& player): WeaponBase(player)
{

}

bool Knife::Init()
{
   
    tra_.modelId = MV1LoadModel((Application::PATH_MODEL+"Weapon/knife.mv1").c_str());
    tra_.scl = VGet(0.5f, 0.5f, 0.5f);
    tra_.pos = VGet(0.0f, 0.0f, 0.0f);
 
    MV1SetScale(tra_.modelId, tra_.scl);
   // tra_.pos = player_->GetTransform().pos;
    return true;
}

void Knife::Update(Player& player)
{
    SceneManager::GetInstance().GetDeltaTime();
    tra_.pos = player.GetTransform().pos;
    MV1SetPosition(tra_.modelId, tra_.pos);
}

void Knife::UpdateAttack()
{
   // tra_.pos= player_.GetTransform().pos;
}

void Knife::Draw()
{
    MV1DrawModel(tra_.modelId);
    DrawFormatString(0,60,0xffffff,"weapon=%d",tra_.modelId);
    DrawFormatString(0,70,0xffffff,"weaponPos=%f,%f,%f", tra_.pos.x,
        tra_.pos.y,
        tra_.pos.z);
}

void Knife::Release()
{
    MV1DeleteModel(tra_.modelId);
}

