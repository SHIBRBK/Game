#pragma once
#include "BaseScene.h"

/// <summary>
/// �L�[�R���t�B�O�̂��߂̃V�[��
/// </summary>
class KeyConfigScene :
    public BaseScene
{
public:
    KeyConfigScene(SceneManager& manager);
    ~KeyConfigScene() {}//������͑厖;
    virtual void Update(InputManager& input)override;
    virtual void Draw()override;
private:
    InputTable_t InputTable_;
};

