#pragma once
#include "EnemyBase.h"
class Enemy :
    public EnemyBase
{
public:
	Enemy();
	virtual ~Enemy()override {};
	virtual bool Init()override;
	virtual void Update()override;
	virtual void Draw()override;
	virtual void Release()override;
private:
};

