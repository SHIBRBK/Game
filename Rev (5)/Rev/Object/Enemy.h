#pragma once
#include<memory>
#include "EnemyBase.h"
class Enemy;
using uniqueEnemy = std::unique_ptr<Enemy>;

class Enemy :
    public EnemyBase
{
public:
	Enemy();
	virtual ~Enemy()override {};
	virtual bool Init()override;
	virtual void Update()override;
	virtual void Draw()override;
private:
};

