#pragma once
#include "../Scene/Manager/AssetsManager.h"

class Player
{
public:
	Player();
	~Player();
	bool Init();
	void Update();
	void Draw();
	void Release();
	void Move();
private:
	shared_Asset model;
	int handle;
};

