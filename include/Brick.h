#pragma once
#include "IMovable.h"
#include <SDLGameObject.h>
class Brick : public SDLGameObject
{
public:
    Brick(int width,int height,int x,int y);
	virtual void draw();
	virtual void update();
	virtual void clean();
    void moveUp(Window &window);
    void moveDown(Window &window);
    void moveLeft(Window &window);
    void moveRight(Window &window);
    int m_speedX = 10;
    int m_speedY = 20;

    void setMovePolicy(IMovable *value);

private:
    IMovable* m_movePolicy;

};
