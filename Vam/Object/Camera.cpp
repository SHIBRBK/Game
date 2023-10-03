#include "../Common/Transform.h"
#include "Camera.h"
Camera* Camera::instance_ = nullptr;

void Camera::CreateInstance(void)
{
    if (instance_ == nullptr)
    {
        instance_ = new Camera();
    }
    instance_->Init();
}

Camera& Camera::GetInstance(void)
{
    if (instance_ == nullptr)
    {
        Camera::CreateInstance();
    }
    return *instance_;
}

Camera::Camera(void)
{
    rotationAngle = VECTOR();
    pos_ = VECTOR();
    targetPos_ = VECTOR();
    angles_ = VECTOR();
    cameraUp_ = VECTOR();
    mSyncTransform = nullptr;

}

Camera::~Camera(void)
{

}

void Camera::Init()
{
    ChangeMode(MODE::FREE);

}

void Camera::SetDefault(void)
{
    pos_ = DEFAULT_CAMERA_POS;
    targetPos_ = { 0.0f,0.0f,0.0f };
    rotationAngle.x = DegToRad(10.0f);
    rotationAngle.y = 0.0f;
    rotationAngle.z = 0.0f;
    cameraUp_ = { 0.0f,1.0f,0.0f };
    quaRot_ = Quaternion();

}

void Camera::SetBeforeDraw()
{
    SetCameraNearFar(CAMERA_NEAR, CAMERA_FAR);
    //(this->*p_Update)();

    switch (mode_)
    {
    case Camera::MODE::FREE:
        SetBeforeDrawFree();
        break;
    case Camera::MODE::FOLLOW:
        SetBeforeDrawFollow();
        break;
    case Camera::MODE::ZOOM:
        SetBeforeDrawZoom();
        break;
    }




    SetCameraPositionAndTargetAndUpVec(
        pos_,
        targetPos_,
        cameraUp_);
}

void Camera::SetBeforeDrawZoom()
{
}

void Camera::SetBeforeDrawFree()
{
}

void Camera::Update()
{

}

void Camera::Draw()
{
    SetDrawScreen(DX_SCREEN_BACK);
    ClearDrawScreen();
    // カメラ設定
    SetBeforeDraw();

    DrawFormatString(0, 210, 0xffffffff, "FPS=%f", GetFPS());

}

void Camera::Release()
{

}

void Camera::ProcessRot(void)
{

}

VECTOR Camera::GetPos(void) const
{
    return pos_;
}

VECTOR Camera::GetAngles(void) const
{
    return angles_;
}

VECTOR Camera::GetTargetPos(void) const
{
    return targetPos_;
}

Quaternion Camera::GetQuaRot(void) const
{
    return quaRot_;
}

Quaternion Camera::GetQuaRotOutX(void) const
{
    return quaRotOutX_;
}

VECTOR Camera::GetDir(void) const
{
    return VNorm(VSub(targetPos_, pos_));
}

void Camera::ChangeMode(MODE mode)
{
    SetDefault();
    mode_ = mode;
    switch (mode_)
    {
    case Camera::MODE::FOLLOW:
        break;
    case Camera::MODE::ZOOM:
        break;
    case Camera::MODE::FREE:
        break;
    }
}

float Camera::DegToRad(float deg)
{
    return deg * (DX_PI_F / 180.0f);
}

VECTOR Camera::Turn(double targetAngle, const VECTOR& axis)
{
    float rad = DegToRad(targetAngle);
    Quaternion  axisQ = Quaternion::AngleAxis(rad, axis);
    quaRot_ = quaRot_.Mult(axisQ);

    return targetPos_;
}

void Camera::SetPlayerPos(const Transform* target)
{
    target_ = target;
}

void Camera::SetTransform(Transform* transform)
{
    mSyncTransform = transform;
}

void Camera::SetBeforeDrawFollow()
{
    GetMousePoint(&mouseX, &mouseY);
    int deltaX = mouseX - prevMouseX;
    int deltaY = mouseY - prevMouseY;
    prevMouseX = mouseX;
    prevMouseY = mouseY;



    if (deltaX > 0)
    {
        rotationAngle.y += DegToRad(1.0f);

    }
    else if (deltaX < 0)
    {
        rotationAngle.y -= DegToRad(1.0f);

    }
    else
    {
        rotationAngle.y += 0.0f;
    }


    if (deltaY > 0)
    {
        //3Dアクションにあったね。制限かけるやつ
        rotationAngle.x -= DegToRad(0.5f);

    }
    else if (deltaY < 0)
    {
        rotationAngle.x += DegToRad(0.5f);

    }
    else
    {
        rotationAngle.x += 0.0f;
    }
    deltaX = 0;
    deltaY = 0;
    VECTOR targetPos = target_->pos; //プレイヤー→   同期先の位置ともいう

    Quaternion anotherQua = target_->quaRot;

    VECTOR axisX = { 1.0f, 0.0f, 0.0f };  // X軸回転なので(1, 0, 0)
    VECTOR axisY = { 0.0f, 1.0f, 0.0f };  // Y軸回転なので(0, 1, 0)

    //カメラ回転用のクォータのAngleAxisに対してマウスの座標の差分をもとに加算を行う。
    //うーんと、こいつが算出されたクォータニオンくさいな
    quaRotOutX_ = anotherQua.Mult(Quaternion::AngleAxis(rotationAngle.y, axisY));
    quaRot_ = quaRotOutX_.Mult(Quaternion::AngleAxis(rotationAngle.x, axisX));
    //cameraRotQua = cameraRotQua.Mult(cameraRotQua);

    //算出されたクォータニオンを元に
    VECTOR localPos;
    localPos = quaRotOutX_.PosAxis(RELATIVE_TARGET_POS);//注視点の相対ベクトル
    targetPos_ = VAdd(targetPos, localPos);
    localPos = quaRot_.PosAxis(RELATIVE_CAMERA_POS_FOLLOW);//カメラの初期相対ベクトルとプレイヤー
    //あとは注視点を作るだけ   プレイヤーの座標からカメラの正方向。で、最後は、注視点の距離。
    pos_ = VAdd(targetPos, localPos);
    cameraUp_ = anotherQua.GetUp();

    //----------------先週までの追従カメラ-----------------------
    //VECTOR targetPos = target_->pos;
    //VECTOR cameraPos = VTransform(RELATIVE_CAMERA_POS_FOLLOW, target_->matRot);
    //// カメラの注視点をプレイヤーの位置に設定する（注視点はプレイヤーの少し前方に設定することで追従感を出す）

    //VECTOR CtargetPos = VTransform(RELATIVE_TARGET_POS, target_->matRot);
    //targetPos_ = targetPos;
    //pos_ = VAdd(targetPos, cameraPos);
}

