#pragma once
#include "BaseScene.h"
#include"../Object/Player.h"
#include"../Object/EnemyBase.h"
#include"../Object/Camera.h"
#include"../Object/Stage.h"
#include"../Object/SkyDome.h"

class Player;
class EnemyBase;

class GameScene :
    public BaseScene
{
public:
	GameScene();
	virtual bool Init()override;
	virtual void Update(InputManager& input)override;
	virtual void Draw()override;
	void Release();
private:

	sharedPlay player_;
	sharedEnemys enemy_;
	uniqueCamera camera_;
	uniqueStage stage_;
	// スカイドーム
	//std::unique_ptr <SkyDome> skyDome_;
};

