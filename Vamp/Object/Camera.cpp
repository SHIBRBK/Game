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
	pos_ = { 0.0f,0.0f,0.0f };
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

	// �N���b�v������ݒ肷��(SetDrawScreen�Ń��Z�b�g�����)
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

	// �J�����̐ݒ�(�ʒu�ƒ����_�ɂ�鐧��)
	SetCameraPositionAndTargetAndUpVec(
		pos_,
		targetPos_,
		cameraUp_
	);

	// DX���C�u�����̃J������Effekseer�̃J�����𓯊�����B
	Effekseer_Sync3DSetting();

}

void Camera::Draw(void)
{
	DrawFormatString(0,0,0xffffff,"x=%f,y=%f,z=%f",
	pos_.x,
	pos_.y,
	pos_.z);
}

void Camera::SetFollow(weakConsterTra follow)
{
	followTransform_ = follow.lock();
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

	// �J�����̏����ݒ�
	SetDefault();

	// �J�������[�h�̕ύX
	mode_ = mode;

	// �ύX���̏���������
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

	// �J�����̏����ݒ�
	pos_ = DEFAULT_CAMERA_POS;

	// �����_
	targetPos_ = {0.0f,0.0f,0.0f};

	// �J�����̏����
	cameraUp_ = { 0.0f,1.0f,0.0f };

	angles_.x = DegToRad(30.0f);
	angles_.y = 0.0f;
	angles_.z = 0.0f;

	rot_ = Quaternion();

}

void Camera::SyncFollow(void)
{

	// ������̈ʒu
	VECTOR pos = followTransform_->pos;

	// �d�͂̕�������ɏ]��
	// ���ʂ���ݒ肳�ꂽY�����A��]������
	rotOutX_ = Quaternion::AngleAxis(angles_.y, {0.0f,1.0f,0.0f});

	// ���ʂ���ݒ肳�ꂽX�����A��]������
	rot_ = rotOutX_.Mult(Quaternion::AngleAxis(angles_.x, { 1.0f,0.0f,0.0f }));

	VECTOR localPos;

	// �����_(�ʏ�d�͂ł����Ƃ����Y�l��Ǐ]�ΏۂƓ����ɂ���)
	localPos = rotOutX_.PosAxis(LOCAL_F2T_POS);
	targetPos_ = VAdd(pos, localPos);

	// �J�����ʒu
	localPos = rot_.PosAxis(LOCAL_F2C_POS);
	pos_ = VAdd(pos, localPos);

	// �J�����̏����
	cameraUp_ = {0.0f,1.0f,0.0f};

}

//void Camera::ProcessRot(void)
//{
//
//	auto& ins = InputManager::GetInstance();
//
//	float movePow = 5.0f;
//
//	// �J������]
//	if (ins.IsNew(KEY_INPUT_RIGHT))
//	{
//		// �E��]
//		angles_.y += AsoUtility::Deg2RadF(1.0f);
//	}
//	if (ins.IsNew(KEY_INPUT_LEFT))
//	{
//		// ����]
//		angles_.y += AsoUtility::Deg2RadF(-1.0f);
//	}
//
//	// ���]
//	if (ins.IsNew(KEY_INPUT_UP))
//	{
//		angles_.x += AsoUtility::Deg2RadF(1.0f);
//		if (angles_.x > LIMIT_X_UP_RAD)
//		{
//			angles_.x = LIMIT_X_UP_RAD;
//		}
//	}
//
//	// ����]
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
	// �������Ȃ�
}

void Camera::SetBeforeDrawFollow(void)
{


	// �Ǐ]�ΏۂƂ̑��Έʒu�𓯊�
	SyncFollow();

}

void Camera::SetBeforeDrawSelfShot(void)
{
}

float Camera::DegToRad(float deg)
{
	return deg * (DX_PI_F / 180.0f);
}