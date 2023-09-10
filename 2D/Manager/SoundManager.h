#pragma once
#include "AssetManager.h"
class SoundManager :
    public AssetManager
{
public:
    SoundManager();
    ~SoundManager();
    void Init()override;
    void Update()override;
    int LoadSound();
    void PlaySound();
    void Release()override;
};

