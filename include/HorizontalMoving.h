#pragma once
#include "IMovable.h"
#include "UtilityStructs.h"
struct Window;
class HorizontalMoving:public IMovable
{
private:
    Speed m_speed;
public:
    HorizontalMoving(IShape * shape,Speed speed);
    ~HorizontalMoving();
     void moveLeft(Window &window) override ;
     void moveRight(Window &window) override;
     void moveUp(Window &window) override;
     void moveDown(Window &window) override;   
};


