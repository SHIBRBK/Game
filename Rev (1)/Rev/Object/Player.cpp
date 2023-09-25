#include "Player.h"
Player::Player()
{
}

Player::~Player()
{
}

bool Player::Init()
{
    handle = model->LoadModel("../Assets/Player/Knight.mv1");
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
