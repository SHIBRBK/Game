#include "SceneManager.h"
#include<DxLib.h>
SceneManager* SceneManager::instance_ = nullptr;

void SceneManager::CreateInstance(void)
{
	if (instance_ == nullptr)
	{
		instance_ = new SceneManager();
	}
	instance_->Init();
}

SceneManager& SceneManager::GetInstance(void)
{
	return *instance_;
}

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::Run()
{
	//ゲームループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		Update();

		Draw();
	}
}

void SceneManager::Init()
{

}

void SceneManager::Update()
{
}

void SceneManager::Draw()
{
}

void SceneManager::Release()
{
}
