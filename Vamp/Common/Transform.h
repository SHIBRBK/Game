#pragma once
#include <DxLib.h>
#include "Quaternion.h"

class Transform;
using uniqueTra = std::unique_ptr<Transform>;
using sharedTra = std::shared_ptr<Transform>;
using weakTra = std::weak_ptr<Transform>;
//���|��������O�R���X�g//���|��������O�R���X�g
using uniqueConsterTra = std::unique_ptr<const Transform>;
//���|��������O�R���X�g
using sharedConsterTra = std::shared_ptr<const Transform>;
//���|��������O�R���X�g
using weakConsterTra = std::weak_ptr<const Transform>;

/// <summary>
/// ���f������̊�{���
/// �傫���FVECTOR�
/// ��]�@�FQuaternion�
/// �ʒu�@�FVECTOR�
/// </summary>
class Transform
{

public:

	// �R���X�g���N�^
	Transform(void);
	Transform(int model);

	// �f�X�g���N�^
	~Transform(void);

	// ���f���̃n���h��ID
	int modelId;

	// �傫��
	VECTOR scl;
	// ��]
	VECTOR rot;
	// �ʒu
	VECTOR pos;
	VECTOR localPos;

	MATRIX matScl;
	MATRIX matRot;
	MATRIX matPos;

	// ��]
	Quaternion quaRot;

	// ���[�J����]
	Quaternion quaRotLocal;



	/// <summary>
	/// ���f������̊�{���X�V
	/// </summary>
	/// <param name=""></param>
	void Update(void);

	//void Release(void);

	void SetModel(int modelHId);


	// �O���������擾
	VECTOR GetForward(void) const;

	// ����������擾
	VECTOR GetBack(void) const;

	// �E�������擾
	VECTOR GetRight(void) const;

	// ���������擾
	VECTOR GetLeft(void) const;

	// ��������擾
	VECTOR GetUp(void) const;

	// ���������擾
	VECTOR GetDown(void) const;

	// �Ώە������擾
	VECTOR GetDir(const VECTOR& vec) const;

};
