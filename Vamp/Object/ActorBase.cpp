#include "ActorBase.h"

ActorBase::ActorBase() :ObjectBase()
{
}

bool ActorBase::Init()
{
    return false;
}

void ActorBase::Update()
{
}

void ActorBase::Draw()
{
}

void ActorBase::Release()
{
}

double ActorBase::DegToRad(double deg)
{
    return deg * (DX_PI_F / 180.0f);
}

float ActorBase::DegToRadF(float deg)
{
    return deg * (DX_PI_F / 180.0f);
}

