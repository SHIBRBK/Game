#pragma once
#include "BaseScene.h"
class SelectScene :
    public BaseScene
{
public:
	SelectScene(SceneManager& manager);
	~SelectScene()override;
	bool Init()override;
	void Update(InputManager& input)override;
	void Draw()override;
private:
};

