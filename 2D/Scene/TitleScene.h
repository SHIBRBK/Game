#pragma once
#include "BaseScene.h"

class TitleScene :
    public BaseScene
{
public:
    TitleScene();
    ~TitleScene();
    void Init(int screenSizeX, int screenSizeY)override;
    void Update()override;
    void Draw()override;
    void Release()override;
private:

};

