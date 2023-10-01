#pragma once
#include "BaseScene.h"
#include"../Object/ObjectBase.h"
#include"../Object/ActorBase.h"
#include"../Object/Player.h"
#include"../Object/Enemy.h"
#include"../Object/EnemyBase.h"
#include"../Object/Camera.h"
#include"../Object/Stage.h"
class GameScene :
    public BaseScene
{
public:
    GameScene(SceneManager& manager);
    bool Init();
    virtual void Update(InputManager& input)override;
    virtual void Draw()override;
    virtual void Release();
private:
    //float fps;
    uniquePlay player_;
   std::vector<uniqueEnemys> enemys_;
    uniqueActor actor_;
    uniqueObj object_;
    uniqueCamera camera_;
    uniqueStage stage_;
protected:

};

