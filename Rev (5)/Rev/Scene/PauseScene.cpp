#include <DxLib.h>
#include "PauseScene.h"
#include "KeyConfigScene.h"
#include"Manager/InputManager.h"
#include"Manager/SceneManager.h"

constexpr int change_interval = 30;
constexpr int pause_width = 400;
constexpr int pause_height = 300;

PauseScene::PauseScene(SceneManager& manager) :BaseScene(manager)
{
	updateFunc_ = &PauseScene::BeginUpdate;
	drawFunc_ = &PauseScene::BeginDraw;

}

void PauseScene::Update(InputManager& input)
{
	//現在の更新関数を呼び出します。
	(this->*updateFunc_)(input);
	//ここより下に処理を書かないでください
}

void PauseScene::Draw()
{
	(this->*drawFunc_)();
}

void PauseScene::BeginUpdate(InputManager& input)
{

	if (++frame_ >= change_interval)
	{
		updateFunc_ = &PauseScene::NormalUpdate;
		drawFunc_ = &PauseScene::NormalDraw;
		commandList_.push_back([]() {
			DrawString(300, 300, "ChangeState to Normal", 0xffffff);
			});
	}
}

void PauseScene::NormalUpdate(InputManager& input)
{
	if (input.IsTriggered("pause"))
	{
		updateFunc_ = &PauseScene::EndUpdate;
		drawFunc_ = &PauseScene::EndDraw;
		frame_ = 0;
		commandList_.push_back([]() {
			DrawString(300, 320, "ChangeState to End", 0xffffff);
			});
	}
	else if (input.IsTriggered("keyconfig"))
	{
		sceneManager_.PushScene(std::make_shared<KeyConfigScene>(sceneManager_));
	}
}

void PauseScene::EndUpdate(InputManager& input)
{
	if (++frame_ >= change_interval)
	{
		sceneManager_.PopScene();
	}
}

void PauseScene::BeginDraw()
{
	float rate = static_cast<float>(frame_) / static_cast<float>(change_interval);
	DrawBox(90, 90, 90 + pause_width, 90 + pause_height * rate,
		0xffffff, false);

}

void PauseScene::NormalDraw()
{
	DrawBox(90, 90, 90 + pause_width, 90 + pause_height,
		0xffffff, false);
	DrawString(100, 100, "Pause Scene", 0xffffff, true);
}

void PauseScene::EndDraw()
{
	float rate = static_cast<float>(frame_) / static_cast<float>(change_interval);
	DrawBox(90, 90, 90 + pause_width, 90 + pause_height * (1.0f - rate),
		0xffffff, false);
	DrawString(100, 100, "Scene", 0xffffff, true);
	for (auto& cmd : commandList_)
	{
		cmd();
	}
}
