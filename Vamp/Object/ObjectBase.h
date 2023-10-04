#pragma once
#include<string>
class ResourceManager;
class SceneManager;

class ObjectBase
{
public:
	ObjectBase();
	virtual ~ObjectBase() {};
	virtual bool Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Release() = 0;

private:

protected:
	// �V���O���g���Q��
	ResourceManager& resMng_;
	SceneManager& scnMng_;
};

