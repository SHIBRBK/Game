#include <DxLib.h>
#include "ObjectBase.h"
#include "../Manager/ResourceManager.h"
#include "../Manager/SceneManager.h"


ObjectBase::ObjectBase() 
    : resMng_(ResourceManager::GetInstance()),
scnMng_(SceneManager::GetInstance())
{
}

