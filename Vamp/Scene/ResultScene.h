#pragma once
#include "BaseScene.h"
class ResultScene :
    public BaseScene
{
public:
	ResultScene();
	virtual bool Init()override;
	virtual void Update()override;
	virtual void Draw()override;
private:
	
};

