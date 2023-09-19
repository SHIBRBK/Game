#pragma once
#include "BaseScene.h"
class ResultScene :
    public BaseScene
{
public:
	ResultScene(SceneManager& manager);
	~ResultScene()override;
	bool Init()override;
	void Update(InputManager& input)override;
	void Draw()override;
private:
};

