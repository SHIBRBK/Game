#pragma once
#include "BaseScene.h"
class ResultScene :
    public BaseScene
{
public:
	ResultScene();
	~ResultScene();
	bool Init()override;
	void Update()override;
	void Draw()override;
	void Release()override;
private:
};

