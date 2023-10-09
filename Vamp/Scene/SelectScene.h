#pragma once
#include "BaseScene.h"
class SelectScene :
    public BaseScene
{
public:
	SelectScene();
	virtual bool Init()override;
	virtual void Update(InputManager& input)override;
	virtual void Draw()override;
private:

};

