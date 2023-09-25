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

	//Update関数で実行される関数を指し示すポインタ
	UpdateFunc_t updateFunc_;


	void BeginUpdate(InputManager& input);//ポーズ表示までの更新
	void NormalUpdate(InputManager& input);//通常更新
	void EndUpdate(InputManager& input);//ポーズ解除の更新

	using DrawFunc_t = void(PauseScene::*)();

	DrawFunc_t drawFunc_;
	void BeginDraw();
	void NormalDraw();
	void EndDraw();

	std::list<std::function<void(void)>> commandList_;

	int frame_ = 0;
};

