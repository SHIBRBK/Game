#pragma once
#include<string>
#include<unordered_map>

enum class InputType
{
	keyboard,
	gamepad,
	mouse
};


//�o�^�������͏��(�������)
struct InputInfo
{
	InputType type;//���͎��
	//���ۂɒ��ׂ�l(PAD��}�E�X�Ȃ�r�b�g��\���Ă�)
	int inputID;
};

struct InputState
{
	std::string key;//�Ώۂ̓��͂�\������
	bool isPressed = false;
};

//���̃L�[�������Ă邩�ǂ�����ێ�����
using InputState_t = std::unordered_map<std::string, bool>;
using InputTable_t = std::unordered_map<std::string, std::vector<InputInfo>>;


class InputManager
{
public:
	// �C���X�^���X�𖾎��I�ɐ���
	static void CreateInstance(void);

	// �C���X�^���X�̎擾
	static InputManager& GetInstance(void);

	InputManager();
	/// <summary>
	/// ���͏����X�V����(���t���[���Ă΂��)
	/// </summary>
	void Update();
	/// <summary>
	/// ���������u�Ԃ��ǂ�����Ԃ�(�������ςȂ���false)
	/// </summary>
	/// <param name="Input">���͎��ʕ�����("next"��"pause"�Ȃ�)</param>
	/// <returns>�������u�ԂȂ�true</returns>
	bool IsTriggered(const std::string& Input)const;
	/// <summary>
	/// �������Ă��邩�ǂ�����Ԃ�
	/// </summary>
	/// <param name="Input">���͎��ʕ�����("next"��"pause"�Ȃ�)</param>
	/// <returns></returns>
	bool IsPressed(const std::string& Input)const;

	/// <summary>
	/// ���̓e�[�u���̏�������
	/// </summary>
	/// <param name="key">���ߕ�����</param>
	/// <param name="inputInfo">�@�킩��̓��͏��(�n�[�h)</param>
	void RewriteInput(const std::string& key,
		const InputInfo& inputInfo);

	const InputTable_t&
		GetInputTable()const;


private:
	// �V���O���g���p�C���X�^���X
	static InputManager* instance_;
	/// <summary>
	/// �Q�[������"�Ӗ�(�Z�}���e�B�N�X)"�Ǝ��ۂ̃L�[�R�[�h�̃y�A
	/// </summary>

	InputTable_t inputTable_;
	InputState_t currentState = {};
	InputState_t lastState = {};
	int currentPadState_;

	//�l�̑���ƃR�s�[�̋֎~
	InputManager(const InputManager&) = delete;
	void operator=(const InputManager&) = delete;

	//���݂��̃L�[��������Ă��邩
	bool GetCurrentInput(const std::string& Input)const;
	//���O�ɂ��̃L�[��������Ă邩
	bool GetLastInput(const std::string& Input)const;
};

