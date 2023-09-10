#pragma once
#include "Item.h"
class Gun :
    public Item
{
public:
    Gun();
    ~Gun();
    bool Init()override;
    void Update()override;
    void Draw()override;
    void Release()override;
private:
};

