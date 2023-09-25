#include "KeyConfigScene.h"
#include"SceneManager.h"
#include <DxLib.h>

KeyConfigScene::KeyConfigScene(SceneManager& manager):Scene(manager)
{

}


void KeyConfigScene::Update(Input& input)
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

		char keycode[256] = {};
		GetHitKeyStateAll(keycode);
		int pad = GetJoypadInputState(DX_INPUT_PAD1);
		int mouse = GetMouseInput();
		int pressedKeyCode = -1;
		for (int i = 0; i < 256; i++)
		{
			if (keycode[i])
			{
				pressedKeyCode = i;
				break;
			}
		}
		if (pressedKeyCode!=-1)
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
}


void KeyConfigScene::Draw()
{
	DrawBox(0, 0, 640, 480, 0x008800, true);

	DrawBox(0, 0, 640, 480, 0xffffff, false);

	DrawString(10, 10, "キーコンフィグ", 0xffffff,false);

	int y = 30;
	for (const auto& record : InputTable_)
	{
		y += 20;
	}

}

