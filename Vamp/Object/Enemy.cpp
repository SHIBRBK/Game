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
        // �G���W�͌��_�t�߂Ƀ����_��
        EnemyPos[i].x = GetRand(100) - 15;
        EnemyPos[i].y = 0.0f;
        EnemyPos[i].z = GetRand(100) - 15;
        // �����������_��
        EnemyAngle[i] = VGet(0.0f, DegToRadF(GetRand(360)), 0.0f);
    }
    return true;
}

void Enemy::Update(Player& player)
{
    float angle = 0.0f;
    auto& tPos = player;//tank_->GetTransform().pos;
    VECTOR sub = VSub(tPos.GetTransform().pos, tra_.pos);
    auto dir = VNorm(sub);//�x�N�g���̋��ߕ� �x�N�g���̊�{���
    auto qua = Quaternion::LookRotation(dir);//����
    tra_.pos = VAdd(tra_.pos, VScale(dir, 4.0f));
}

void Enemy::Draw()
{
    // �G���f���̕`��
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