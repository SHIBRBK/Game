#pragma once
#include"BaseScene.h"

class GameOverScene:
	public BaseScene
{
public:
	GameOverScene();
	virtual bool Init()override;
	virtual void Update()override;
	virtual void Draw()override;
	virtual void Release()override;
private:
};

