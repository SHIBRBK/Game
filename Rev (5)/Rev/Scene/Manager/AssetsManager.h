#pragma once
#include<string>
#include<unordered_map>
#include <vector>
#include <list>
#include <memory>

class AssetsManager;
using shared_Asset=std::shared_ptr<AssetsManager>;

enum class AssetType
{
	Texture,
	Sound,
	Model,
};

// アセット情報
struct AssetInfo {
	AssetType type;
	std::string filePath;
	// 他のアセット情報を格納する必要がある場合、ここに追加します
};



using AssetsTable_t = std::unordered_map<std::string, std::vector<AssetInfo>>;

class AssetsManager
{
public:
	AssetsManager();
	/// <summary>
/// オブジェクト情報を更新する(舞フレーム呼ばれる)
/// </summary>
	void Update();
	void LoadAsset(const std::string& assetKey, const AssetInfo& assetInfo);
	void LoadTexture(const std::string& assetKey, const std::string& filePath);
	void LoadSound(const std::string& assetKey, const std::string& filePath);
	int LoadModel(const std::string& filePath);
	int DrawModel(int filePath);

	int UnloadAsset(int assetKey);
	void UnloadAllAssets();

	const AssetsTable_t&
		GetAssetsTable()const;
	

private:
	/// <summary>
	/// ゲーム中の"意味(セマンティクス)"と実際のキーコードのペア
	/// </summary>

	AssetsTable_t assetsTable_;

	AssetType assetID_;

	//値の代入とコピーの禁止
	AssetsManager(const AssetsManager&) = delete;
	void operator=(const AssetsManager&) = delete;

	

	std::list<AssetType> scenes_;


};

