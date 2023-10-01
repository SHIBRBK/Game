#pragma once
#include<string>
#include<unordered_map>

enum class ObjectType
{
	Player,
	Enemy,
	Stage,
	Weapon,
	Item
};

class ObjectManager
{
public:
	ObjectManager();
	/// <summary>
/// オブジェクト情報を更新する(舞フレーム呼ばれる)
/// </summary>
	void Update();
	

private:

	//値の代入とコピーの禁止
	ObjectManager(const ObjectManager&) = delete;
	void operator=(const ObjectManager&) = delete;

};

