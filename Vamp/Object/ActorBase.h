#pragma once
#include<DxLib.h>
#include<memory>
#include<list>
#include"ObjectBase.h"

class ActorBase;
using uniqueActor = std::list<std::unique_ptr<ActorBase>>;

class ActorBase :
	public ObjectBase
{
public:
	ActorBase();
	virtual bool Init() override;
	virtual void Update()override;
	virtual void Draw()override;
	virtual void Release()override;
	virtual double DegToRad(double deg) = 0;
	virtual float DegToRadF(float deg) = 0;
private:
};

