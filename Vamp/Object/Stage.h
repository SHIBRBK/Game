#pragma once
#include <memory>
#include "ObjectBase.h"
#include "../Common/Transform.h"
class Stage;
using uniqueStage = std::unique_ptr<Stage>;

class Stage :
	public ObjectBase
{
public:

	static constexpr float SCALE = 10.0f;

	Stage();
	bool Init()override;
	void Update()override;
	void Draw()override;
	void Release()override;
	Transform tra_;
	int modelID = 0;
private:
	float DegToRadF(float deg);
};

