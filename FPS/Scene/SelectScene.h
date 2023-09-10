#pragma once
#include "BaseScene.h"
class SelectScene :
    public BaseScene
{
public:
	SelectScene();
	~SelectScene();
	bool Init()override;
	void Update()override;
	void Draw()override;
	void Release()override;
private:
};

