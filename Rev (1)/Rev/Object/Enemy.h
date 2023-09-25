#pragma once
#include "EnemyBase.h"
class Enemy :
    public EnemyBase
{
public:
	Enemy();
	~Enemy()override {};
	virtual bool Init()override;
	virtual void Update()override;
	virtual void Draw()override;
private:
};

