#pragma once
#include"BaseScene.h"
#include<list>
#include<functional>

class PauseScene :
	public BaseScene
{
public:
	PauseScene(SceneManager& manager);
	~PauseScene() {};
	virtual void Update(InputManager& input)override;
	virtual void Draw()override;
private:
	using UpdateFunc_t = void(PauseScene::*)(InputManager& input);

	//Update�֐��Ŏ��s�����֐����w�������|�C���^
	UpdateFunc_t updateFunc_;


	void BeginUpdate(InputManager& input);//�|�[�Y�\���܂ł̍X�V
	void NormalUpdate(InputManager& input);//�ʏ�X�V
	void EndUpdate(InputManager& input);//�|�[�Y�����̍X�V

	using DrawFunc_t = void(PauseScene::*)();

	DrawFunc_t drawFunc_;
	void BeginDraw();
	void NormalDraw();
	void EndDraw();

	std::list<std::function<void(void)>> commandList_;

	int frame_ = 0;
};

