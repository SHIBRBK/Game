#include <DxLib.h>
#include<EffekseerForDXLib.h>
#include "AssetManager.h"
#include<vector>
const std::string AssetManager::PATH_MODEL = "Asset/Model/";
//const std::string AssetManager::PATH_SOUND = "Asset/Sound/";
const std::string AssetManager::PATH_TEXTURE = "Asset/Texture/";
const std::string AssetManager::PATH_EFFECT = "Asset/Effect/";


int AssetManager::LoadModel(const std::string& filePath)
{
    int modelHandle = MV1LoadModel(filePath.c_str());
    if (modelHandle == -1)
    {
        MessageBox(NULL, (LPCSTR)("モデルの読み込みに失敗しました: " + filePath).c_str(), "エラー", MB_OK | MB_ICONERROR);
        exit(EXIT_FAILURE);
    }
    return modelHandle;
}

void AssetManager::ReleaseModel(int modelHandle)
{
    MV1DeleteModel(modelHandle);
}

void AssetManager::ReleaseAllModels()
{
    MV1InitModel();
}

int AssetManager::LoadSound(const std::string& filePath)
{
    int soundHandle = LoadSoundMem(filePath.c_str());
    if (soundHandle == -1)
    {
        MessageBox(NULL, (LPCSTR)("サウンドの読み込みに失敗しました: " + filePath).c_str(), "エラー", MB_OK | MB_ICONERROR);
        exit(EXIT_FAILURE);
    }
    return soundHandle;
}

void AssetManager::ReleaseSound(int soundHandle)
{
    DeleteSoundMem(soundHandle);
}

void AssetManager::ReleaseAllSounds()
{
    InitSoundMem();
}

int AssetManager::LoadTexture(const std::string& filePath)
{
    int textureHandle = LoadGraph(filePath.c_str());

    if (textureHandle == -1) {
        // テクスチャの読み込みに失敗した場合はエラーを表示して終了
        MessageBox(NULL, (LPCSTR)("テクスチャの読み込みに失敗しました: " + filePath).c_str(), "エラー", MB_OK | MB_ICONERROR);
        exit(EXIT_FAILURE);
    }

    return textureHandle;
}

void AssetManager::ReleaseTexture(int textureHandle)
{
    DeleteGraph(textureHandle);
}

void AssetManager::ReleaseAllTextures()
{
    InitGraph();
}

int AssetManager::LoadEffect(const std::string& filePath)
{
    int effectHandle = LoadEffekseerEffect(filePath.c_str());
    if (effectHandle == -1)
    {
        // テクスチャの読み込みに失敗した場合はエラーを表示して終了
        MessageBox(NULL, (LPCSTR)("テクスチャの読み込みに失敗しました: " + filePath).c_str(), "エラー", MB_OK | MB_ICONERROR);
        exit(EXIT_FAILURE);
    }

}

void AssetManager::ReleaseEffect(int textureHandle)
{
    DeleteEffekseerEffect(textureHandle);
}

void AssetManager::ReleaseAllEffect()
{
    Effkseer_End();
}


void AssetManager::LoadModelsInFolder(const std::string& folderPath, std::vector<int>& modelHandles)
{
    HANDLE hFind;
    WIN32_FIND_DATA fd;
    std::string filter = folderPath + "*.mv1";

    hFind = FindFirstFile(filter.c_str(), &fd);
    if (hFind == INVALID_HANDLE_VALUE) {
        // ファイルが見つからなかった場合は何もしない
        return;
    }

    do {
        if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
            std::string filePath = folderPath + fd.cFileName;
            int modelHandle = LoadModel(filePath);
            modelHandles.push_back(modelHandle);
        }
    } while (FindNextFile(hFind, &fd) != 0);

    FindClose(hFind);
}