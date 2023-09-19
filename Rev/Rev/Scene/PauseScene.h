#pragma once
#include "BaseScene.h"
class PauseScene :
    public BaseScene
{
public:
	PauseScene(SceneManager& manager);
	~PauseScene()override;
	bool Init()override;
	void Update(InputManager& input)override;
	void Draw()override;
private:
};

