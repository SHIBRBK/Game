#pragma once
#include "ObjectBase.h"
class Stage :
    public ObjectBase
{
public:
	Stage();
	~Stage();
	virtual bool Init()override;
	virtual void Update()override;
	virtual void Draw()override;
	virtual void Release()override;
};

