#pragma once
class Actor
{
public:
	virtual ~Actor() = 0;
	virtual bool Init()=0;
	virtual void Update()=0;
	virtual void Draw()=0;
	virtual void Release()=0;
private:

protected:
	Actor();
};

