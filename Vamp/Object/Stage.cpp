#include<DxLib.h>
#include "Stage.h"
#include "../Manager/ResourceManager.h"
#include "../AssetManager.h"
#include "../Application.h"
//#include"../Assets/Model/Stage/"

Stage::Stage() :ObjectBase()
{
}



bool Stage::Init()
{
    tra_.modelId = MV1LoadModel((Application::PATH_MODEL+"Stage/MainPlanet.mv1").c_str());
    tra_.scl = VGet(SCALE, SCALE, SCALE);
    tra_.quaRot = Quaternion();
    tra_.quaRotLocal =
        Quaternion::Euler(
            0.0f,
            DegToRadF(0.0f),
            0.0f
        );

    tra_.pos = { 0.0f,0.0f,0.0f };

    return true;
}

void Stage::Update()
{
}

void Stage::Draw()
{

    MV1DrawModel(tra_.modelId);
    DrawFormatString(0, 30, 0xffffff, "x=%f,y=%f,z=%f",
        tra_.pos.x,
        tra_.pos.y,
        tra_.pos.z);

}

void Stage::Release()
{
    MV1DrawModel(tra_.modelId);
}

float Stage::DegToRadF(float deg)
{
    return deg * (DX_PI_F / 180.0f);
}
