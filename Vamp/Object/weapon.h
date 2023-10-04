#pragma once
#include<DxLib.h>
#include "ObjectBase.h"
class Weapon :
	public ObjectBase
{
public:
	Weapon(VECTOR pos);
	virtual bool Init()override;
	virtual void Update()override;
	virtual void Draw()override;
	virtual void Release()override;
private:
};

