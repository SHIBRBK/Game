#pragma once
class SceneManager
{
public:
	// 静的インスタンス
	static SceneManager* instance_;
	// インスタンスの生成
	static void CreateInstance(void);
	// インスタンスの取得
	static SceneManager& GetInstance(void);
	void Run();
	void Init();
	void Update();
	void Draw();
	void Release();
private:
	SceneManager();
	~SceneManager();
};

