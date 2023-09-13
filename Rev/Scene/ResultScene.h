#pragma once
#include "BaseScene.h"
class ResultScene :
    public BaseScene
{
public:
	ResultScene();
	~ResultScene()override;
	bool Init()override;
	void Update()override;
	void Draw()override;
private:
};

