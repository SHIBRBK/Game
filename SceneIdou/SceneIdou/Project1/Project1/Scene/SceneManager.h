#pragma once
#include<memory>
#include<list>
class Scene;
class Input;

class SceneManager
{
public:
	/// <summary>
	/// 先頭の(Updateが呼ばれる)シーン切り替え
	/// </summary>
	/// <param name="scene">切り替え先のシーン</param>
	void ChangeScene(std::shared_ptr<Scene> scene);//現在のシーンを実行

	/// <summary>
	/// シーンをプッシュする。スタックの数が増える。
	/// </summary>
	/// <param name="scene">上に積むシーン</param>
	void PushScene(std::shared_ptr<Scene> scene);//現在のシーンを実行

	/// <summary>
	/// スタックの頭のシーンを削除する
	/// ただし、スタック上にシーンが1つしかない場合は
	/// 削除しない
	/// </summary>
	void PopScene();//現在のシーンを実行

	/// <summary>
	/// 持っているシーンスタックの先頭のUpdateを呼び出す
	/// </summary>
	/// <param name="input_">入力IOパラメータ</param>
	void Update(Input& input);

	/// <summary>
	/// 持っているシーンすべてを描画する。
	/// ただし、描画順は下から描画されます。
	/// </summary>
	void Draw();

private:
	std::list<std::shared_ptr<Scene> > scenes_;
};

