#pragma once
#include"BaseScene.h"
class ResultScene :
    public BaseScene
{
public:
    ResultScene(SceneManager& manager);
    void Update(InputManager& input)override;
    void Draw()override;
protected:

};

