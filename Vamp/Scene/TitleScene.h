#pragma once
#include <memory>
#include "BaseScene.h"
class TitleScene :
    public BaseScene
{
public:
	TitleScene();
	bool Init(void) override;
	void Update() override;
	virtual void Draw()override;
private:
};

