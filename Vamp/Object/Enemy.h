#pragma once
#include "EnemyBase.h"
#include "../Common/Transform.h"

class Player;

class Enemy :
	public EnemyBase
{
public:
	static constexpr int MAX_ENEMY = 20.0f;
	Enemy();
	virtual bool Init()override;
	virtual void Update(Player& player)override;
	virtual void Draw()override;
	virtual void Release()override;
	void ChasePlayer();
private:
	Transform tra_;
	VECTOR EnemyPos[MAX_ENEMY];
	VECTOR EnemyAngle[MAX_ENEMY];
	double DegToRad(double deg);
	float DegToRadF(float deg);
};

