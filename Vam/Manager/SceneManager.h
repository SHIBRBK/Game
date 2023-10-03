#pragma once
#include"../Scene/BaseScene.h"
#include<memory>
#include"../Object/Camera.h"

enum SCENE_ID;
class BaseScene;
class InputManager;

class SceneManager
{
public:

	// �C���X�^���X�̐���
	static void CreateInstance(void);

	// �C���X�^���X�̎擾
	static SceneManager& GetInstance(void);

	void ChangeScene(SCENE_ID nextId);
	//void PushScene(std::shared_ptr<BaseScene> scene);
	void PopScene();//���݂̃V�[�������s
	void Init();
	void Init3D(void);
	void Update();
	void Draw();

	uniqueConsterCamera GetCamera();
private:
	//std::list<std::shared_ptr<BaseScene>> scenes_;
	SceneManager(void);
	~SceneManager(void);
	std::unique_ptr<BaseScene> scene_;
	uniqueCamera camera_;
	SCENE_ID sceneId_;
	SCENE_ID waitSceneId_;
	// �ÓI�C���X�^���X
	static SceneManager* instance_;
};

