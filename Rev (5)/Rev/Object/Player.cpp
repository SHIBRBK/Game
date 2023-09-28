#include "Player.h"
Player::Player() :ActorBase()
{
}

Player::~Player()
{
}

bool Player::Init()
{
    transform_.modelId = model->LoadModel("../Assets/Player/Knight.mv1");
    transform_.scl = VGet(SCALE, SCALE, SCALE);
    transform_.quaRot = Quaternion();
    transform_.quaRotLocal =
        Quaternion::Euler(
            0.0f,
            DegToRad(180.0f),
            0.0f
        );

    transform_.pos = { 0.0f,0.0f,0.0f };

    return true;
}

void Player::Update()
{
}

void Player::Draw()
{
    model->DrawModel(handle);
}

void Player::Release()
{
    model->UnloadAsset(handle);
}

const Transform& Player::GetTransform(void) const
{
   return transform_;
}

double Player::DegToRad(double deg)
{
    return deg * (DX_PI_F / 180.0f);
}

float Player::DegToRadF(float deg)
{
    return deg * (DX_PI_F / 180.0f);
}
