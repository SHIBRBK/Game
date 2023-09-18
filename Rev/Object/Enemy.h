#pragma once
#include "EnemyBase.h"
class Enemy :
    public EnemyBase
{
public:
	Enemy();
	~Enemy()override;
	bool Init()override;
	void Update()override;
	void Draw()override;
private:
};

