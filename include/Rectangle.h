#pragma once
#include "IShape.h"
#include "IMovable.h"

class Rectangle : public IShape
{
public:
    Rectangle(int width, int height, int posX, int posY);
    Rectangle(int width, int height);
    void draw(SDL_Renderer *renderer, RGBColor const &color) override;
    void update(Window &window) override;
    void moveUp(Window &window);
    void moveDown(Window &window);
    void moveLeft(Window &window);
    void moveRight(Window &window);

    int m_speedX = 10;
    int m_speedY = 20;

    void setMovePolicy(IMovable *value);

private:
    IMovable* movePolicy;
};
