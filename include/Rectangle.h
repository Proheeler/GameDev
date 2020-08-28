#pragma once
#include "IShape.h"
class Rectangle:public IShape
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

private:
    int m_width;
    int m_height;
    int m_posX;
    int m_posY;
    int m_speedX = 10;
    int m_speedY = 20;
};