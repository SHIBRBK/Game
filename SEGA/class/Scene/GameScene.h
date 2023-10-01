#pragma once
#include"BaseScene.h"

class GameScene :
	public BaseScene
{
public:
	GameScene();
	virtual bool Init()override;
	virtual void Update()override;
	virtual void Draw()override;
	virtual void Release()override;
private:
};

