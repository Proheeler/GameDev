#pragma once
#include "IShape.h"
#include <GameParameters.h>
class Circle : public IShape
{
public:
    Circle(int radius);
    Circle(int radius, int posX, int posY);
    void draw(SDL_Renderer *renderer, RGBColor const &color) override;
    void update(Window &window) override;
    int radius();

    int m_speedX = GameParameters::ballSpeed.x;
    int m_speedY = GameParameters::ballSpeed.y;

private:
    int m_radius;
};