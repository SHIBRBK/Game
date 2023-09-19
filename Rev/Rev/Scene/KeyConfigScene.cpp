#include "KeyConfigScene.h"
#include"Manager/InputManager.h"
#include <DxLib.h>

KeyConfigScene::KeyConfigScene(SceneManager& manager) :BaseScene(manager)
{

}


void KeyConfigScene::Update(InputManager& input)
{
	if (InputTable_.empty())
	{
		InputTable_ = input.GetInputTable();
	}

	if (input.IsTriggered("keyconfig"))
	{
		sceneManager_.PopScene();
	}
	else
	{
		if (input.IsPressed("keyconfig"))
		{
			return;
		}
	}
	char keycode[256] = {};
	GetHitKeyStateAll(keycode);
	int pad = GetJoypadInputState(DX_INPUT_PAD1);
	int mouse = GetMouseInput();
	int pressedKeyCode = -1;
	for (int i = 0; i < 255; i++)
	{
		if (keycode[i])
		{
			pressedKeyCode = i;
			break;
		}
	}
	if (pressedKeyCode)
	{
		InputInfo info = { InputType::keyboard,pressedKeyCode };
		input.RewriteInput("jump", info);
	}
	else if (pad)
	{
		InputInfo info = { InputType::gamepad,pad };
		input.RewriteInput("jump", info);
	}
	else if (mouse)
	{
		InputInfo info = { InputType::mouse,mouse };
		input.RewriteInput("jump", info);
	}
}


void KeyConfigScene::Draw()
{
	DrawBox(0, 0, 640, 480, 0x008800, true);

	DrawBox(0, 0, 640, 480, 0xffffff, true);

	DrawString(30, 30, "キーコンフィグ", 0xffffff);



}

