#pragma once
#include "EnemyBase.h"
class Boss :
    public EnemyBase
{
public:
	Boss();
	virtual ~Boss()override {};
	virtual bool Init()override;
	virtual void Update()override;
	virtual void Draw()override;
private:
};

