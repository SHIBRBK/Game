#pragma once
#include<memory>

class BaseScene;
using uniqueScene = std::unique_ptr<BaseScene>;

class BaseScene
{
public:
	virtual ~BaseScene()=0;
	virtual bool Init()=0;
	virtual void Update()=0;
	virtual void Draw() = 0;
private:

protected:
	BaseScene();
};

