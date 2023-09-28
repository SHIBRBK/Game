#include <DxLib.h>
#include "AssetsManager.h"

AssetsManager::AssetsManager()
{

}

void AssetsManager::Update()
{
}

//const AssetsTable_t& AssetsManager::GetAssetsTable() const
//{
//	// TODO: return ステートメントをここに挿入します
//}

void AssetsManager::LoadAsset(const std::string& assetKey, const AssetInfo& assetInfo)
{
	
}

void AssetsManager::LoadTexture(const std::string& assetKey, const std::string& filePath)
{
}

void AssetsManager::LoadSound(const std::string& assetKey, const std::string& filePath)
{
}

int AssetsManager::LoadModel(const std::string& filePath)
{
	return MV1LoadModel(filePath.c_str());
}

int AssetsManager::DrawModel(int filePath)
{
	return MV1DrawModel(filePath);
}

int AssetsManager::UnloadAsset(int assetKey)
{
	return MV1DeleteModel(assetKey);
}

void AssetsManager::UnloadAllAssets()
{

}
