#pragma once
#include"BaseScene.h"

class PauseScene :
	public BaseScene
{
public:
	PauseScene();
	virtual bool Init()override;
	virtual void Update()override;
	virtual void Draw()override;
	virtual void Release()override;
private:
};

