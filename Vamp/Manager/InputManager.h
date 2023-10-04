#pragma once
#include<string>
#include<unordered_map>

enum class InputType
{
	keyboard,
	gamepad,
	mouse
};


//登録される入力情報(一つ当たり)
struct InputInfo
{
	InputType type;//入力種別
	//実際に調べる値(PADやマウスならビットを表してる)
	int inputID;
};

struct InputState
{
	std::string key;//対象の入力を表す文字
	bool isPressed = false;
};

//このキーを押してるかどうかを保持する
using InputState_t = std::unordered_map<std::string, bool>;
using InputTable_t = std::unordered_map<std::string, std::vector<InputInfo>>;


class InputManager
{
public:
	// インスタンスを明示的に生成
	static void CreateInstance(void);

	// インスタンスの取得
	static InputManager& GetInstance(void);

	InputManager();
	/// <summary>
	/// 入力情報を更新する(舞フレーム呼ばれる)
	/// </summary>
	void Update();
	/// <summary>
	/// 今推した瞬間かどうかを返す(押しっぱなしはfalse)
	/// </summary>
	/// <param name="Input">入力識別文字列("next"や"pause"など)</param>
	/// <returns>推した瞬間ならtrue</returns>
	bool IsTriggered(const std::string& Input)const;
	/// <summary>
	/// 今推しているかどうかを返す
	/// </summary>
	/// <param name="Input">入力識別文字列("next"や"pause"など)</param>
	/// <returns></returns>
	bool IsPressed(const std::string& Input)const;

	/// <summary>
	/// 入力テーブルの書き換え
	/// </summary>
	/// <param name="key">命令文字列</param>
	/// <param name="inputInfo">機器からの入力情報(ハード)</param>
	void RewriteInput(const std::string& key,
		const InputInfo& inputInfo);

	const InputTable_t&
		GetInputTable()const;


private:
	// シングルトン用インスタンス
	static InputManager* instance_;
	/// <summary>
	/// ゲーム中の"意味(セマンティクス)"と実際のキーコードのペア
	/// </summary>

	InputTable_t inputTable_;
	InputState_t currentState = {};
	InputState_t lastState = {};
	int currentPadState_;

	//値の代入とコピーの禁止
	InputManager(const InputManager&) = delete;
	void operator=(const InputManager&) = delete;

	//現在そのキーが押されているか
	bool GetCurrentInput(const std::string& Input)const;
	//直前にそのキーが押されてるか
	bool GetLastInput(const std::string& Input)const;
};

