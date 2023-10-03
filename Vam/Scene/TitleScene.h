#pragma once
#include "BaseScene.h"
class TitleScene :
    public BaseScene
{
public:
	TitleScene();
	virtual SCENE_ID Update()override;
	virtual void Draw()override;
private:
	SCENE_ID sceneID_;
};

