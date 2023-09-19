#pragma once
#include "EnemyBase.h"
class Boss :
    public EnemyBase
{
public:
	Boss();
	~Boss()override;
	bool Init()override;
	void Update()override;
	void Draw()override;
private:
};

