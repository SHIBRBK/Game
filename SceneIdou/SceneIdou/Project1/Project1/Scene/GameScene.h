#pragma once
#include "Scene.h"
class GameScene :
    public Scene
{
public:
    GameScene(SceneManager& manager);
    virtual void Update(Input& input)override;
    virtual void Draw()override;
private:
    //float fps;
protected:

};

