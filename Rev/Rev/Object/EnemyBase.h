#pragma once
class EnemyBase
{
public:
	EnemyBase();
	virtual ~EnemyBase()=0;
	virtual bool Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;


private:

protected:

};

