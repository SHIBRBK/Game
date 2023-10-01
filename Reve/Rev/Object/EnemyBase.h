#pragma once
#include<memory>
#include"ActorBase.h"

class EnemyBase;
using uniqueEnemys=std::unique_ptr<EnemyBase>;

class EnemyBase:
	public ActorBase
{
public:
	EnemyBase();
	virtual ~EnemyBase()override = 0;
	virtual bool Init() override=0;
	virtual void Update()override = 0;
	virtual void Draw()override = 0;
	virtual void Release()override = 0;


private:

protected:

};

