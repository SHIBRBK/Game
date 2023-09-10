#pragma once
#include "BaseScene.h"
class GameScene :
    public BaseScene
{
public:
	GameScene();
	~GameScene();
	bool Init()override;
	void Update()override;
	void Draw()override;
	void Release()override;
private:
};

