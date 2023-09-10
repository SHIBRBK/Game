#pragma once
#include"BaseScene.h"

class GameScene
	:public BaseScene
{
public:
    GameScene();
    ~GameScene();
    void Init(int screenSizeX, int screenSizeY)override;
    void Update()override;
    void Draw()override;
    void Release()override;
private:

};

