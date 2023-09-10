#pragma once
#include"Actor.h"
class Player:
	public Actor
{
public:
	Player();
	~Player()override;
	bool Init()override;
	void Update()override;
	void Draw()override;
	void Release()override;
};

