#pragma once
#include"Scene.h"
class GameOverScene :
    public Scene
{
public:
    GameOverScene(SceneManager& manager);
    void Update(Input& input)override;
    void Draw()override;
protected:

};

