#include <math.h>
#include <DxLib.h>
#include <EffekseerForDXLib.h>
#include "../Manager/InputManager.h"
#include "Camera.h"

Camera::Camera(void)
{
	angles_ = VECTOR();
	cameraUp_ = VECTOR();
	mode_ = MODE::NONE;
	pos_ = { 0.0f,50.0f,0.0f };
	targetPos_ = { 0.0f,0.0f,0.0f };
	//followTransform_ = nullptr;
}

Camera::~Camera(void)
{
}

void Camera::Init(void)
{

	ChangeMode(MODE::FIXED_POINT);

}

void Camera::Update(void)
{
}

void Camera::SetBeforeDraw(void)
{

	// クリップ距離を設定する(SetDrawScreenでリセットされる)
	SetCameraNearFar(CAMERA_NEAR, CAMERA_FAR);

	switch (mode_)
	{
	case Camera::MODE::FIXED_POINT:
		SetBeforeDrawFixedPoint();
		break;
	case Camera::MODE::FOLLOW:
		SetBeforeDrawFollow();
		break;
	}

	// カメラの設定(位置と注視点による制御)
	SetCameraPositionAndTargetAndUpVec(
		pos_,
		targetPos_,
		cameraUp_
	);

	// DXライブラリのカメラとEffekseerのカメラを同期する。
	Effekseer_Sync3DSetting();

}

void Camera::Draw(void)
{
	DrawFormatString(0,0,0xffffff,"CameraPos x=%f,y=%f,z=%f",
	pos_.x,
	pos_.y,
	pos_.z);
}


void Camera::SetFollow(const Transform* target)
{
	target_ = target;
}


void Camera::SetFollow(std::shared_ptr<const Transform> follow)
{
	followTransform_ = follow;
}

void Camera::SetPlayerPos(const Transform* target)
{
	target_ = target;
}

void Camera::SetPlayerPos(sharedConsterTra target)
{
	followTransform_ = target;
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
	return rot_;
}

Quaternion Camera::GetQuaRotOutX(void) const
{
	return rotOutX_;
}

VECTOR Camera::GetForward(void) const
{
	return VNorm(VSub(targetPos_, pos_));
}

void Camera::ChangeMode(MODE mode)
{

	// カメラの初期設定
	SetDefault();

	// カメラモードの変更
	mode_ = mode;

	// 変更時の初期化処理
	switch (mode_)
	{
	case Camera::MODE::FIXED_POINT:
		break;
	case Camera::MODE::FOLLOW:
		break;
	}

}

void Camera::SetDefault(void)
{

	// カメラの初期設定
	pos_ = DEFAULT_CAMERA_POS;

	// 注視点
	targetPos_ = {0.0f,0.0f,0.0f};

	// カメラの上方向
	cameraUp_ = { 0.0f,1.0f,0.0f };

	angles_.x = DegToRad(30.0f);
	angles_.y = 0.0f;
	angles_.z = 0.0f;

	rot_ = Quaternion();

}

void Camera::SyncFollow(void)
{

	// 同期先の位置
	VECTOR pos = target_->pos;

	// 重力の方向制御に従う
	// 正面から設定されたY軸分、回転させる
	rotOutX_ = Quaternion::AngleAxis(angles_.y, {0.0f,1.0f,0.0f});

	// 正面から設定されたX軸分、回転させる
	rot_ = rotOutX_.Mult(Quaternion::AngleAxis(angles_.x, { 1.0f,0.0f,0.0f }));

	VECTOR localPos;

	// 注視点(通常重力でいうところのY値を追従対象と同じにする)
	localPos = rotOutX_.PosAxis(LOCAL_F2T_POS);
	targetPos_ = VAdd(pos, localPos);

	// カメラ位置
	localPos = rot_.PosAxis(LOCAL_F2C_POS);
	pos_ = VAdd(pos, localPos);

	// カメラの上方向
	cameraUp_ = {0.0f,1.0f,0.0f};

}

//void Camera::ProcessRot(void)
//{
//
//	auto& ins = InputManager::GetInstance();
//
//	float movePow = 5.0f;
//
//	// カメラ回転
//	if (ins.IsNew(KEY_INPUT_RIGHT))
//	{
//		// 右回転
//		angles_.y += AsoUtility::Deg2RadF(1.0f);
//	}
//	if (ins.IsNew(KEY_INPUT_LEFT))
//	{
//		// 左回転
//		angles_.y += AsoUtility::Deg2RadF(-1.0f);
//	}
//
//	// 上回転
//	if (ins.IsNew(KEY_INPUT_UP))
//	{
//		angles_.x += AsoUtility::Deg2RadF(1.0f);
//		if (angles_.x > LIMIT_X_UP_RAD)
//		{
//			angles_.x = LIMIT_X_UP_RAD;
//		}
//	}
//
//	// 下回転
//	if (ins.IsNew(KEY_INPUT_DOWN))
//	{
//		angles_.x += AsoUtility::Deg2RadF(-1.0f);
//		if (angles_.x < -LIMIT_X_DW_RAD)
//		{
//			angles_.x = -LIMIT_X_DW_RAD;
//		}
//	}
//
//}

void Camera::SetBeforeDrawFixedPoint(void)
{
	// 何もしない
}

void Camera::SetBeforeDrawFollow(void)
{


	// 追従対象との相対位置を同期
	SyncFollow();

}

void Camera::SetBeforeDrawSelfShot(void)
{
}

float Camera::DegToRad(float deg)
{
	return deg * (DX_PI_F / 180.0f);
}