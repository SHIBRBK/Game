#pragma once
#include<memory>
#include<list>
class Scene;
class Input;

class SceneManager
{
public:
	/// <summary>
	/// �擪��(Update���Ă΂��)�V�[���؂�ւ�
	/// </summary>
	/// <param name="scene">�؂�ւ���̃V�[��</param>
	void ChangeScene(std::shared_ptr<Scene> scene);//���݂̃V�[�������s

	/// <summary>
	/// �V�[�����v�b�V������B�X�^�b�N�̐���������B
	/// </summary>
	/// <param name="scene">��ɐςރV�[��</param>
	void PushScene(std::shared_ptr<Scene> scene);//���݂̃V�[�������s

	/// <summary>
	/// �X�^�b�N�̓��̃V�[�����폜����
	/// �������A�X�^�b�N��ɃV�[����1�����Ȃ��ꍇ��
	/// �폜���Ȃ�
	/// </summary>
	void PopScene();//���݂̃V�[�������s

	/// <summary>
	/// �����Ă���V�[���X�^�b�N�̐擪��Update���Ăяo��
	/// </summary>
	/// <param name="input_">����IO�p�����[�^</param>
	void Update(Input& input);

	/// <summary>
	/// �����Ă���V�[�����ׂĂ�`�悷��B
	/// �������A�`�揇�͉�����`�悳��܂��B
	/// </summary>
	void Draw();

private:
	std::list<std::shared_ptr<Scene> > scenes_;
};

