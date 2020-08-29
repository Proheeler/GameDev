#pragma once
#include "IShape.h"

class Circle : public IShape
{
public:
    Circle(int radius);
    Circle(int radius, int posX, int posY);
    void draw(SDL_Renderer *renderer, RGBColor const &color) override;
    void update(Window &window) override;
    int x();
    int y();
    int radius();

    int m_speedX = 15;
    int m_speedY = 20;
    int m_posX;
    int m_posY;

private:
    int m_radius;
};