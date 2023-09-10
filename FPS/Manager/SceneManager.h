#pragma once
class SceneManager
{
public:
	enum SCENE_ID
	{
		TITLE,
		SELECT,
		GAME,
		RESULT
	};
	// �ÓI�C���X�^���X
	static SceneManager* instance_;
	// �C���X�^���X�̐���
	static void CreateInstance(void);
	// �C���X�^���X�̎擾
	static SceneManager& GetInstance(void);
	void Run();
	void Init();
	void Update();
	void Draw();
	void Release();


private:
	SceneManager();
	~SceneManager();

	static SceneManager* instance_;
protected:
	
};

