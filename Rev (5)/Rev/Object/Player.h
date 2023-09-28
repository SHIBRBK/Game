#pragma once
#include <memory>
#include"ActorBase.h"
#include"../Common/Transform.h"
#include "../Scene/Manager/AssetsManager.h"

class Player;
using uniquePlay = std::unique_ptr<Player>;


class Player:
public ActorBase
{
public:
	static constexpr float SCALE = 0.5f;

	Player();
	virtual ~Player()override;
	virtual bool Init()override;
	virtual void Update()override;
	virtual void Draw()override;
	virtual void Release()override;
	void Move();
	const Transform& GetTransform(void) const;
private:
	virtual double DegToRad(double deg)override;
	virtual float DegToRadF(float deg)override;
	shared_Asset model;
	int handle;
	Transform transform_;
};

