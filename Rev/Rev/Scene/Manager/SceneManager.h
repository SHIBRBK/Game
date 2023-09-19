#pragma once
#include"../BaseScene.h"
#include<memory>
#include<list>
class BaseScene;
class InputManager;

class SceneManager
{
public:
	void ChangeScene(std::shared_ptr<BaseScene> scene);
	void PushScene(std::shared_ptr<BaseScene> scene);
	void PopScene();//Œ»İ‚ÌƒV[ƒ“‚ğÀs
	void Update(InputManager& input);
	void Draw();

private:
	std::list<std::shared_ptr<BaseScene>> scenes_;


};

