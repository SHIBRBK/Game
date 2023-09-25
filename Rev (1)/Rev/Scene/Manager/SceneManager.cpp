#include "SceneManager.h"
#include "../BaseScene.h"
#include "InputManager.h"

void SceneManager::ChangeScene(std::shared_ptr<BaseScene> scene)
{
	if (scenes_.empty())
	{
		scenes_.push_front(scene);
	}
	else
	{
		scenes_.front() = scene;//フロントを入れ替える
	}
}

void SceneManager::PushScene(std::shared_ptr<BaseScene> scene)
{
	scenes_.push_front(scene);
}

void SceneManager::PopScene()
{
	scenes_.pop_front();
}

void SceneManager::Update(InputManager& input)
{
	//今現在の持ってるシーンを実行
	scenes_.front()->Update(input);
}

void SceneManager::Draw()
{
	auto rit = scenes_.rbegin();
	for (; rit != scenes_.rend(); rit++)
	{
		(*rit)->Draw();
	}
}
