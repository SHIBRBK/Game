#pragma once
#include<DxLib.h>
#include<memory>
#include<list>
#include"ObjectBase.h"

class ActorBase;
using uniqueActor = std::list<std::unique_ptr<ActorBase>>;

class ActorBase:
	public ObjectBase
{
public:
	ActorBase();
	virtual ~ActorBase()override = 0;
	virtual bool Init() override = 0;
	virtual void Update()override = 0;
	virtual void Draw()override = 0;
	virtual void Release()override = 0;
	virtual double DegToRad(double deg) = 0;
	virtual float DegToRadF(float deg) = 0;
private:
};

