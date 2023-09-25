#include "SceneManager.h"
#include "Scene.h"
#include "../Input.h"

void SceneManager::ChangeScene(std::shared_ptr<Scene> scene)
{//今持ってるシーンを実行
	if (scenes_.empty())
	{
		scenes_.push_front(scene);
	}
	else 
	{
		scenes_.front() = scene;//フロントを入れ替える
	}
}

void SceneManager::PushScene(std::shared_ptr<Scene> scene)
{
	scenes_.push_front(scene);
}

void SceneManager::PopScene()
{
	scenes_.pop_front();
}

void SceneManager::Update(Input& input)
{//今現在の持ってるシーンを実行
	if (!scenes_.empty())
	{
		scenes_.front()->Update(input);
	}
}

void SceneManager::Draw()
{
	auto rit = scenes_.rbegin();
	for (;rit != scenes_.rend(); rit++)
	{
		(*rit)->Draw();
	}

}
