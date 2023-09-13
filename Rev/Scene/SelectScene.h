#pragma once
#include "BaseScene.h"
class SelectScene :
    public BaseScene
{
public:
	SelectScene();
	~SelectScene()override;
	bool Init()override;
	void Update()override;
	void Draw()override;
private:
};

