#pragma once
#include"../BaseScene.h"
#include<memory>
#include<list>
#include"../../Object/Camera.h"
class BaseScene;
class InputManager;

class SceneManager
{
public:
	void ChangeScene(std::shared_ptr<BaseScene> scene);
	void PushScene(std::shared_ptr<BaseScene> scene);
	void PopScene();//現在のシーンを実行
	void Update(InputManager& input);
	void Draw();

	Camera* GetCamera()const;
private:
	std::list<std::shared_ptr<BaseScene>> scenes_;
	uniqueCamera camera_;

};

