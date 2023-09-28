#pragma once
#include<string>
#include<unordered_map>

enum class ObjectType
{
	Player,
	Enemy,
	Stage,
	Weapon,
	Item
};

class ObjectManager
{
public:
	ObjectManager();
	/// <summary>
/// �I�u�W�F�N�g�����X�V����(���t���[���Ă΂��)
/// </summary>
	void Update();
	

private:

	//�l�̑���ƃR�s�[�̋֎~
	ObjectManager(const ObjectManager&) = delete;
	void operator=(const ObjectManager&) = delete;

};

