#pragma once
class BaseScene
{
public:
	BaseScene();
	virtual ~BaseScene() {};
	virtual bool Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Release() = 0;
};

