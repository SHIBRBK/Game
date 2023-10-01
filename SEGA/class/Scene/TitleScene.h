#pragma once
#include"BaseScene.h"

class TitleScene :
	public BaseScene
{
public:
	TitleScene();
	virtual bool Init()override;
	virtual void Update()override;
	virtual void Draw()override;
	virtual void Release()override;
private:
};

