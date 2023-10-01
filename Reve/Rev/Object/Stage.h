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
	Stage();
	~Stage();
	virtual bool Init()override;
	virtual void Update()override;
	virtual void Draw()override;
	virtual void Release()override;

	uniqueTra tra_;
	int modelID ;
};

