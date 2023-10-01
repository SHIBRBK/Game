#pragma once
#include<memory>
#include<array>
#include<list>
class ObjectBase;
//using uniqueObj = std::array<std::unique_ptr<ObjectBase>,2>;

using uniqueObj = std::unique_ptr<ObjectBase>;

class ObjectBase
{
public:
	ObjectBase();
	virtual ~ObjectBase() = 0;
	virtual bool Init()=0;
	virtual void Update()=0;
	virtual void Draw()=0;
	virtual void Release()=0;


private:
};

