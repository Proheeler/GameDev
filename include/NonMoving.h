#pragma once
#include "IMovable.h"
#include "UtilityStructs.h"
class NonMoving:public IMovable
{
public:
    NonMoving(IShape * shape,Speed):IMovable(shape){}
    ~NonMoving();
     void moveLeft(Window &) override {};
     void moveRight(Window &) override{};
     void moveUp(Window &) override{};
     void moveDown(Window &) override{};
};
