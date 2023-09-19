#pragma once
#include"Manager/InputManager.h"
#include"Manager/SceneManager.h"

class InputManager;
class SceneManager;

class BaseScene
{
public:
	BaseScene(SceneManager& manager);
	virtual ~BaseScene()=0;
	virtual bool Init()=0;
	virtual void Update(InputManager& input)=0;
	virtual void Draw() = 0;
private:

protected:
	SceneManager& sceneManager_;//‚ ‚Ü‚è‚æ‚ë‚µ‚­‚È‚¢
};

