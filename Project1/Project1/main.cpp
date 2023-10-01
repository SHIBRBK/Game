#include<DxLib.h>
#include"Input.h"
#include"Scene/SceneManager.h"
#include"Scene/TitleScene.h"
using namespace std;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	ChangeWindowMode(true);
	if (DxLib_Init() == -1)
	{
		return -1;
	}
	SetDrawScreen(DX_SCREEN_BACK);

	SceneManager sceneManager;
	sceneManager.ChangeScene(make_shared<TitleScene>(sceneManager));

	Input input;

	while(ProcessMessage()!=-1)
	{
		ClearDrawScreen();
		input.Update();

		sceneManager.Update(input);
		sceneManager.Draw();


		ScreenFlip();
	}
	DxLib_End();
	return -1;
}