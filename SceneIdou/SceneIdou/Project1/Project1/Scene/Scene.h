#pragma once
#include"../Input.h"
#include"SceneManager.h"
class Input;
class SceneManager;
/// <summary>
/// �V�[���̊��N���X(���ۃN���X)
/// </summary>
class Scene
{
public:
	Scene(SceneManager& manager);
	virtual	~Scene() {};//������͑厖

	virtual void Update(Input& input)=0;//�h���N���X�ł͐�΍��
	virtual void Draw()=0;
protected:
	SceneManager& sceneManager_;//���܂��낵���Ȃ�
};

