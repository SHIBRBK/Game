#include<DxLib.h>
#include "Stage.h"
Stage::Stage()
{
}

Stage::~Stage()
{
}

bool Stage::Init()
{
    modelID=tra_->modelId = MV1LoadModel("../Assets/Stage/Bridge.mv1");
    MV1SetScale(modelID,VECTOR(5.0f,5.0f,5.0f));
    MV1SetPosition(modelID, VECTOR(0.0f, 0.0f, 0.0f));
    MV1SetupCollInfo(modelID);
    
    
    return true;
}

void Stage::Update()
{
}

void Stage::Draw()
{
    MV1DrawModel(modelID);
}

void Stage::Release()
{
    MV1DrawModel(modelID);
}
