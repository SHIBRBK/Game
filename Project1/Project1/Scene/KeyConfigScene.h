#pragma once
#include "Scene.h"

/// <summary>
/// �L�[�R���t�B�O�̂��߂̃V�[��
/// </summary>
class KeyConfigScene :
    public Scene
{
public:
    KeyConfigScene(SceneManager& manager);
    ~KeyConfigScene() {}//������͑厖;
    virtual void Update(Input& input)override;
    virtual void Draw()override;
private:
    InputTable_t InputTable_;
};

