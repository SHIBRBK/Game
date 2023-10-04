#include "Player.h"
#include "../Manager/ResourceManager.h"
#include "../Manager/InputManager.h"
#include "../AssetManager.h"
Player::Player() :ActorBase()
{
}



bool Player::Init()
{
    tra_.modelId =MV1LoadModel("../Assets/Model/Player/Mike.mv1");
    tra_.scl = VGet(SCALE, SCALE, SCALE);
    tra_.quaRot = Quaternion();
    tra_.quaRotLocal =
        Quaternion::Euler(
            0.0f,
            DegToRadF(180.0f),
            0.0f
        );

    tra_.pos = { 0.0f,0.0f,0.0f };

    return true;
}

void Player::Update()
{
    VECTOR dir = {0.0f,0.0f,0.0f};
    InputManager& input = InputManager::GetInstance();
    if (input.IsTriggered("up"))
    {
        VECTOR dir = { 0.0f,0.0f,1.0f };
        tra_.pos = VScale(dir, 5.0f);
    }
    else if (input.IsTriggered("down"))
    {
        VECTOR dir = { 0.0f,0.0f,-1.0f };
        tra_.pos = VScale(dir, 5.0f);
    }

    if (input.IsTriggered("left"))
    {
        VECTOR dir = { 1.0f,0.0f,0.0f };
        tra_.pos = VScale(dir, 5.0f);
    }

    else if (input.IsTriggered("right"))
    {
        VECTOR dir = { -1.0f,0.0f,0.0f };
        tra_.pos = VScale(dir, 5.0f);
    }
    tra_.Update();
}

void Player::Draw()
{
    MV1DrawModel(tra_.modelId);
    DrawFormatString(0, 15, 0xffffff, "x=%f,y=%f,z=%f",
        tra_.pos.x,
        tra_.pos.y,
        tra_.pos.z);
}

void Player::Release()
{
    MV1DeleteModel(tra_.modelId);
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
