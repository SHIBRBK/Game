#pragma once
#include<memory>
#include"../Manager/InputManager.h"
#include"../Manager/SceneManager.h"

class ResourceManager;

class BaseScene;
using uniqueScene = std::unique_ptr<BaseScene>;


class BaseScene
{
public:
	BaseScene();
	virtual ~BaseScene() {};
	// ‰Šú‰»ˆ—
	virtual bool Init(void) = 0;
	virtual void Update()=0;
	virtual void Draw()=0;
private:

protected:
	// ƒŠƒ\[ƒXŠÇ—
	ResourceManager& resMng_;

};

