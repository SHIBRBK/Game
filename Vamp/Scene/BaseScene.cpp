#include "../Manager/ResourceManager.h"
#include "BaseScene.h"

BaseScene::BaseScene() : resMng_(ResourceManager::GetInstance())
{
}

