#pragma once
#include"../Input.h"
#include"SceneManager.h"
class Input;
class SceneManager;
/// <summary>
/// シーンの基底クラス(抽象クラス)
/// </summary>
class Scene
{
public:
	Scene(SceneManager& manager);
	virtual	~Scene() {};//これ実は大事

	virtual void Update(Input& input)=0;//派生クラスでは絶対作る
	virtual void Draw()=0;
protected:
	SceneManager& sceneManager_;//あまりよろしくない
};

