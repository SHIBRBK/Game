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
	// 初期化処理
	virtual bool Init(void) = 0;
	virtual void Update(InputManager& input)=0;
	virtual void Draw()=0;
private:

protected:
	// リソース管理
	ResourceManager& resMng_;

};

