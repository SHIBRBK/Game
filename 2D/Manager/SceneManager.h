#pragma once


class SceneManager
{
public:
	static SceneManager* GetInstance()
	{
		if (!instance)
		{
			instance = new SceneManager();
		}
		return instance;
	}
	SceneManager(const SceneManager&) = delete;
	SceneManager& operator=(const SceneManager&) = delete;

private:
	SceneManager();
	~SceneManager();

	static SceneManager* instance;

protected:
	void Run();
	void Init();
	void Update();
	void Draw();
	void Release();

};

