#include <memory>
#include "../Application.h"
#include "Player.h"
#include "Enemy.h"

Enemy::Enemy() :EnemyBase()
{

}


bool Enemy::Init()
{
    tra_.modelId = MV1LoadModel((Application::PATH_MODEL+"Enemy/Enemy.mv1").c_str());
    for (int i = 0; i < MAX_ENEMY; i++) {
        // 敵座標は原点付近にランダム
        EnemyPos[i].x = GetRand(100) - 15;
        EnemyPos[i].y = 0.0f;
        EnemyPos[i].z = GetRand(100) - 15;
        // 向きもランダム
        EnemyAngle[i] = VGet(0.0f, DegToRadF(GetRand(360)), 0.0f);
    }
    return true;
}

void Enemy::Update(Player& player)
{
    float angle = 0.0f;
    auto& tPos = player;//tank_->GetTransform().pos;
    VECTOR sub = VSub(tPos.GetTransform().pos, tra_.pos);
    auto dir = VNorm(sub);//ベクトルの求め方 ベクトルの基本情報
    auto qua = Quaternion::LookRotation(dir);//向き
    tra_.pos = VAdd(tra_.pos, VScale(dir, 4.0f));
}

void Enemy::Draw()
{
    // 敵モデルの描画
    for (int i = 0; i < MAX_ENEMY; i++) 
    {
        MV1SetPosition(tra_.modelId, EnemyPos[i]);
        MV1SetRotationXYZ(tra_.modelId, EnemyAngle[i]);
        MV1DrawModel(tra_.modelId);
    }
}

void Enemy::Release()
{
    MV1DeleteModel(tra_.modelId);
}

void Enemy::ChasePlayer()
{
}

double Enemy::DegToRad(double deg)
{
    return deg * (DX_PI_F / 180.0f);
}

float Enemy::DegToRadF(float deg)
{
    return deg * (DX_PI_F / 180.0f);
}