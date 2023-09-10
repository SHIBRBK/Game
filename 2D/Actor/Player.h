#pragma once
#include "Actor.h"
class Player :
    public Actor
{
public:
    Player();
    ~Player();
    void Init()override;
    void Update()override;
    void Draw()override;
    void Release()override;
private:

};

