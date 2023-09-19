#pragma once
#include "Scene.h"

/// <summary>
/// キーコンフィグのためのシーン
/// </summary>
class KeyConfigScene :
    public Scene
{
public:
    KeyConfigScene(SceneManager& manager);
    ~KeyConfigScene() {}//これ実は大事;
    virtual void Update(Input& input)override;
    virtual void Draw()override;
private:
    InputTable_t InputTable_;
};

