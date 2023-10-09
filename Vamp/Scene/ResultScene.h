#pragma once
#include "BaseScene.h"
class ResultScene :
    public BaseScene
{
public:
	ResultScene();
	virtual bool Init()override;
	virtual void Update(InputManager& input)override;
	virtual void Draw()override;
private:
	
};

