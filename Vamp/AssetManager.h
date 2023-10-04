#pragma once
#include<vector>
#include<string>
#include<map>


class AssetManager
{
public:

    static const std::string PATH_MODEL;
    static const std::string PATH_SOUND;
    static const std::string PATH_TEXTURE;
    static const std::string PATH_EFFECT;
    static const std::string PATH_SHADER;

    static int LoadModel(const std::string& filePath);
    static void ReleaseModel(int modelHandle);
    static void ReleaseAllModels();

    static int LoadSound(const std::string& filePath);
    static void ReleaseSound(int soundHandle);
    static void ReleaseAllSounds();

    static int LoadTexture(const std::string& filePath);
    static void ReleaseTexture(int textureHandle);
    static void ReleaseAllTextures();

    static int LoadEffect(const std::string& filePath);
    static void ReleaseEffect(int textureHandle);
    static void ReleaseAllEffect();

    static void LoadModelsInFolder(const std::string& folderPath, std::vector<int>& modelHandles);
};

