#define _CRTDBG_MAP_ALLOC
#include<crtdbg.h>
#include<memory>
#include <DxLib.h>
#include "Application.h"


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

	// ���s
	instance.Run();

	// ���
	instance.Destroy();

	return 0;

}