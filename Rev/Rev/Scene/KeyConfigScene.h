#pragma once
#include "BaseScene.h"

/// <summary>
/// キーコンフィグのためのシーン
/// </summary>
class KeyConfigScene :
    public BaseScene
{
public:
    KeyConfigScene(SceneManager& manager);
    ~KeyConfigScene() {}//これ実は大事;
    virtual void Update(InputManager& input)override;
    virtual void Draw()override;
private:
    InputTable_t InputTable_;
};

