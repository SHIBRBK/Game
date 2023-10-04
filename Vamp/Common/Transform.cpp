#include <DxLib.h>
#include "Transform.h"

Transform::Transform(void)
{
	modelId = -1;

	scl = { 1.0f,1.0f,1.0f };
	rot = { 0.0f,0.0f,0.0f };
	pos = { 0.0f,0.0f,0.0f };
	localPos = { 0.0f,0.0f,0.0f };

	matScl = MGetIdent();
	matRot = MGetIdent();
	matPos = MGetIdent();
	quaRot = Quaternion();
	quaRotLocal = Quaternion();

}

Transform::Transform(int model)
{
	modelId = model;

	scl = {1.0f,1.0f,1.0f};
	rot = { 0.0f,0.0f,0.0f };
	pos = { 0.0f,0.0f,0.0f };
	localPos = { 0.0f,0.0f,0.0f };

	matScl = MGetIdent();
	matRot = MGetIdent();
	matPos = MGetIdent();
	quaRot = Quaternion();
	quaRotLocal = Quaternion();

}

Transform::~Transform(void)
{
}

void Transform::Update(void)
{

	// �傫��
	matScl = MGetScale(scl);

	// ��]
	rot = quaRot.ToEuler();
	matRot = quaRot.ToMatrix();

	// �ʒu
	matPos = MGetTranslate(pos);

	// �s��̍���
	MATRIX mat = MGetIdent();
	mat = MMult(mat, matScl);
	Quaternion q = quaRot.Mult(quaRotLocal);
	mat = MMult(mat, q.ToMatrix());
	mat = MMult(mat, matPos);

	// �s������f���ɔ���
	if (modelId != -1)
	{
		MV1SetMatrix(modelId, mat);
	}


}

//void Transform::Release(void)
//{
//	//if (collider != nullptr)
//	//{
//	//	delete collider;
//	//}
//}

void Transform::SetModel(int model)
{
	modelId = model;
}


VECTOR Transform::GetForward(void) const
{
	return GetDir(VGet(0.0f,0.0f,1.0f));
}

VECTOR Transform::GetBack(void) const
{
	return GetDir(VGet(0.0f, 0.0f, -1.0f));
}

VECTOR Transform::GetRight(void) const
{
	return GetDir(VGet(1.0f, 0.0f, 0.0f));
}

VECTOR Transform::GetLeft(void) const
{
	return GetDir(VGet(-1.0f, 0.0f, 0.0f));
}

VECTOR Transform::GetUp(void) const
{
	return GetDir(VGet(0.0f, 1.0f, 0.0f));
}

VECTOR Transform::GetDown(void) const
{
	return GetDir(VGet(0.0f, 1.0f, 0.0f));
}

VECTOR Transform::GetDir(const VECTOR& vec) const
{
	return quaRot.PosAxis(vec);
}
