#pragma once
#include "IShape.h"

class Circle:public IShape
{
public:
    Circle(int radius);
    Circle(int radius, int posX, int posY);
    void draw(SDL_Renderer *renderer, RGBColor const &  color) override;
    void update(Window & window) override;

private:
    int m_radius;
    int m_posX;
    int m_posY;
    int m_speedX = 10;
    int m_speedY = 20;
};