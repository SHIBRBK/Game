#pragma once
#include "BaseScene.h"
class SelectScene :
	public BaseScene
{
public:
	SelectScene(SceneManager& manager);
	virtual void Update(InputManager& input)override;
	virtual void Draw()override;

protected:

};

