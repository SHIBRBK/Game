#pragma once
#include"ActorBase.h"
class EnemyBase:
	public ActorBase
{
public:
	EnemyBase();
	virtual ~EnemyBase()override = 0;
	virtual bool Init() override=0;
	virtual void Update()override = 0;
	virtual void Draw()override = 0;

private:

protected:

};

