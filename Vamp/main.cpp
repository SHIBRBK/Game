#define _CRTDBG_MAP_ALLOC
#include<crtdbg.h>
#include<memory>
#include <DxLib.h>
#include "Application.h"

#include "Manager/InputManager.h"


// WinMain関数
//---------------------------------
int WINAPI WinMain(
	_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{

	// インスタンスの生成
	Application::CreateInstance();

	// インスタンスの取得
	Application& instance = Application::GetInstance();

	if (instance.IsInitFail())
	{
		// 初期化失敗
		return -1;
	}
	InputManager& input = InputManager::GetInstance();
	// 実行
	instance.Run(input);

	// 解放
	instance.Destroy();

	return 0;

}
