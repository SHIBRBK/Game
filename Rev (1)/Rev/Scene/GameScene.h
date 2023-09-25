#pragma once
#include "BaseScene.h"
class GameScene :
    public BaseScene
{
public:
    GameScene(SceneManager& manager);
    bool Init();
    virtual void Update(InputManager& input)override;
    virtual void Draw()override;
private:
    //float fps;
protected:

};

