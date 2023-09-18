#pragma once
#include "BaseScene.h"
class PauseScene :
    public BaseScene
{
public:
	PauseScene();
	~PauseScene()override;
	bool Init()override;
	void Update()override;
	void Draw()override;
private:
};

