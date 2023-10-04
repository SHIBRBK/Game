#pragma once
#include "BaseScene.h"
#include"../Object/Player.h"
#include"../Object/Enemy.h"
#include"../Object/EnemyBase.h"
#include"../Object/Camera.h"
#include"../Object/Stage.h"
#include"../Object/SkyDome.h"
class GameScene :
    public BaseScene
{
public:
	GameScene();
	virtual bool Init()override;
	virtual void Update()override;
	virtual void Draw()override;
	void Release();
private:
	sharedPlay player_;
	uniqueCamera camera_;
	uniqueStage stage_;
	// スカイドーム
	//std::unique_ptr <SkyDome> skyDome_;
};

