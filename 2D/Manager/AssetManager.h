#pragma once
class AssetManager
{
public:
	virtual ~AssetManager();
	virtual void Init();
	virtual void Update();
	virtual void Draw();
	virtual void Release();

private:
	AssetManager();
};

