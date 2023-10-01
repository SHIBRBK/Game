#pragma once
#include "BaseScene.h"
class TitleScene :
	public BaseScene
{
public:
	TitleScene(SceneManager& manager);
	virtual void Update(InputManager& input)override;
	virtual void Draw()override;

protected:

};

