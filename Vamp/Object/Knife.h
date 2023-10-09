#pragma once
#include "WeaponBase.h"
#include"../Common/Transform.h"

class Player;

class Knife :
    public WeaponBase
{
public:
    Knife(const Player& player_);
    virtual bool Init()override;
    virtual void Update(Player& player)override;
    void UpdateAttack();
    virtual void Draw()override;
    virtual void Release()override;
private:
    
    Transform tra_;
};

