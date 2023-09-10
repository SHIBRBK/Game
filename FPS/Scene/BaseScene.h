#pragma once
class BaseScene
{
public:
	static constexpr int SCREEN_SIZE_X = 1024;
	static constexpr int SCREEN_SIZE_Y = 640;

	virtual ~BaseScene();
	virtual bool Init()=0;
	virtual void Update()=0;
	virtual void Draw()=0;
	virtual void Release()=0;


private:


protected:
	BaseScene();
	int screenID_;
};

