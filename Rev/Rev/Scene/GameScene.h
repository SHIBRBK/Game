#pragma once
#include "BaseScene.h"
class GameScene :
    public BaseScene
{
public:
	 GameScene(SceneManager& manager);
	 ~GameScene()override;
	 bool Init()override;
	 void Update(InputManager& input)override;
	 void Draw()override;
private:

protected:
	SceneManager* sceneManager;
};

