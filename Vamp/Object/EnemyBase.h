#pragma once
#include<memory>
#include"ActorBase.h"

class EnemyBase;
using uniqueEnemys = std::unique_ptr<EnemyBase>;

class EnemyBase :
	public ActorBase
{
public:
	EnemyBase();
	virtual bool Init() override;
	virtual void Update()override;
	virtual void Draw()override;
	virtual void Release()override;


private:

protected:

};

