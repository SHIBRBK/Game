#pragma once
#include <memory>
#include"ActorBase.h"
#include"../Common/Transform.h"


class Player;
using uniquePlay = std::unique_ptr<Player>;

class Player;
using sharedPlay = std::shared_ptr<Player>;

class InputManager;
class WeaponBase;


class Player :
	public ActorBase
{
public:
	static constexpr float SCALE = 1.0f;

	Player();
	~Player()override {};
	bool Init()override;
	void Update()override;
	void UpdatePlay(InputManager& input);
	void Draw()override;
	void Release()override;
	void Move();
	const Transform& GetTransform(void) const;
private:
	double DegToRad(double deg)override;
	float DegToRadF(float deg)override;
	int handle;
	Transform tra_;
	std::shared_ptr<WeaponBase> weapon_;

};

