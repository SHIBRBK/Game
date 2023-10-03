#pragma once
#include<memory>

class BaseScene;
using uniqueScene = std::unique_ptr<BaseScene>;
enum SCENE_ID
{
	NONE,
	TITLE,
	SELECT,
	GAME,
	GAMEOVER
};

class BaseScene
{
public:
	BaseScene();
	virtual ~BaseScene() {};
	virtual SCENE_ID Update()=0;
	virtual void Draw()=0;
	SCENE_ID GetSceneID();
private:
	SCENE_ID sceneID_;
};

