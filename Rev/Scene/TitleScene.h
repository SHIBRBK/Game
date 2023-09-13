#pragma once
#include "BaseScene.h"
class TitleScene :
    public BaseScene
{
public:
	TitleScene();
	~TitleScene()override;
	bool Init()override;
	void Update()override;
	void Draw()override;
private:
};

