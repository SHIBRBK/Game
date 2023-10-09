#include "Player.h"
#include "../Manager/ResourceManager.h"
#include "../AssetManager.h"
#include"../Application.h"
#include "../Manager/InputManager.h"
#include "WeaponBase.h"
#include"Knife.h"

Player::Player() :ActorBase()
{
    weapon_ = std::make_shared<Knife>(*this);
}



bool Player::Init()
{
    tra_.modelId =MV1LoadModel((Application::PATH_MODEL + "Player/Knight.mv1").c_str());
    tra_.scl = VGet(SCALE, SCALE, SCALE);
    tra_.pos = { 0.0f, 30.0f, 0.0f };
    tra_.quaRot = Quaternion();
    tra_.quaRotLocal =
        Quaternion::Euler(
            0.0f,
            DegToRadF(180.0f),
            0.0f
        );

    tra_.Update();
    weapon_->Init();

    return true;
}

void Player::Update()
{

}

void Player::UpdatePlay(InputManager& input)
{
    VECTOR dir = { 0.0f,0.0f,0.0f };
    if (input.IsPressed("up"))
    {
        VECTOR dir = { 0.0f,0.0f,1.0f };
        tra_.pos = VAdd(tra_.pos, VScale(dir, 5.0f));
    }
    else if (input.IsPressed("down"))
    {
        VECTOR dir = { 0.0f,0.0f,-1.0f };
        tra_.pos = VAdd(tra_.pos, VScale(dir, 5.0f));
    }

    if (input.IsPressed("left"))
    {
        VECTOR dir = { -1.0f,0.0f,0.0f };
        tra_.pos = VAdd(tra_.pos, VScale(dir, 5.0f));
    }

    else if (input.IsPressed("right"))
    {
        VECTOR dir = { 1.0f,0.0f,0.0f };
        tra_.pos = VAdd(tra_.pos, VScale(dir, 5.0f));
    }
    tra_.Update();
    weapon_->Update(*this);
}

void Player::Draw()
{
    MV1DrawModel(tra_.modelId);
    tra_.Update();
    DrawFormatString(0, 15, 0xffffff, "x=%f,y=%f,z=%f",
        tra_.pos.x,
        tra_.pos.y,
        tra_.pos.z);

    DrawFormatString(0, 45, 0xffffff, "model=%d",
        tra_.modelId);
    weapon_->Draw();
}

void Player::Release()
{
    //MV1DeleteModel(tra_.modelId);
}

void Player::Move()
{
}

const Transform& Player::GetTransform(void) const
{
    return tra_;
}

double Player::DegToRad(double deg)
{
    return deg * (DX_PI_F / 180.0f);
}

float Player::DegToRadF(float deg)
{
    return deg * (DX_PI_F / 180.0f);
}
