#pragma once
#include<memory>
#include<DxLib.h>

class Player;

class WeaponBase
{
public:
	WeaponBase(const Player& player);
	virtual ~WeaponBase(){};
	virtual bool Init() = 0;
	virtual void Update(Player& player) = 0;
	virtual void Draw() = 0;
	virtual void Release()=0;
private:

protected:
	const Player& player_;
};

