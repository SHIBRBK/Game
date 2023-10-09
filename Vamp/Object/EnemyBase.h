#pragma once
#include<memory>
#include"ActorBase.h"

class EnemyBase;
using sharedEnemys = std::shared_ptr<EnemyBase>;

class Player;


class EnemyBase
{
public:
	EnemyBase();
	virtual bool Init()=0;
	virtual void Update(Player& player) = 0;
	virtual void Draw() = 0;
	virtual void Release() = 0;


private:

protected:

};

