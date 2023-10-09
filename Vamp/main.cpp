#define _CRTDBG_MAP_ALLOC
#include<crtdbg.h>
#include<memory>
#include <DxLib.h>
#include "Application.h"

#include "Manager/InputManager.h"


// WinMain�֐�
//---------------------------------
int WINAPI WinMain(
	_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{

	// �C���X�^���X�̐���
	Application::CreateInstance();

	// �C���X�^���X�̎擾
	Application& instance = Application::GetInstance();

	if (instance.IsInitFail())
	{
		// ���������s
		return -1;
	}
	InputManager& input = InputManager::GetInstance();
	// ���s
	instance.Run(input);

	// ���
	instance.Destroy();

	return 0;

}
