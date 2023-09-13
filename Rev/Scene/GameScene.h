#pragma once
#include "BaseScene.h"
class GameScene :
    public BaseScene
{
public:
	 GameScene();
	 ~GameScene()override;
	 bool Init()override;
	 void Update()override;
	 void Draw()override;
private:
};

