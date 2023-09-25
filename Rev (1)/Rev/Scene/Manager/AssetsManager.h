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

// �A�Z�b�g���
struct AssetInfo {
	AssetType type;
	std::string filePath;
	// ���̃A�Z�b�g�����i�[����K�v������ꍇ�A�����ɒǉ����܂�
};



using AssetsTable_t = std::unordered_map<std::string, std::vector<AssetInfo>>;

class AssetsManager
{
public:
	AssetsManager();
	/// <summary>
/// �I�u�W�F�N�g�����X�V����(���t���[���Ă΂��)
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
	/// �Q�[������"�Ӗ�(�Z�}���e�B�N�X)"�Ǝ��ۂ̃L�[�R�[�h�̃y�A
	/// </summary>

	AssetsTable_t assetsTable_;

	AssetType assetID_;

	//�l�̑���ƃR�s�[�̋֎~
	AssetsManager(const AssetsManager&) = delete;
	void operator=(const AssetsManager&) = delete;

	

	std::list<AssetType> scenes_;


};

