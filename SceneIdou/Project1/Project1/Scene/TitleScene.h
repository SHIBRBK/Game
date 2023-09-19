#pragma once
#include "Scene.h"
class TitleScene:
	public Scene
{
public:
	TitleScene(SceneManager& manager);
	virtual void Update(Input& input)override;
	virtual void Draw()override;

protected:

};

