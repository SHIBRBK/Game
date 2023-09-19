#pragma once
#include "BaseScene.h"
class TitleScene :
    public BaseScene
{
public:
	TitleScene(SceneManager& manager);
	~TitleScene()override;
	bool Init()override;
	void Update(InputManager& input)override;
	void Draw()override;
private:

protected:
	SceneManager* sceneManager;
};

