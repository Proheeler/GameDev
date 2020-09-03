#pragma once
#include "RGBColor.h"

struct Window;
struct SDL_Renderer;
class IShape
{
private:
    int m_posX;
    int m_posY;
    int m_width;
    int m_height;

public:
    IShape(int x, int y, int width, int height);
    virtual void draw(SDL_Renderer *renderer, RGBColor const &color) = 0;
    virtual void update(Window &window) = 0;
    int x();
    int y();
    void setX(int x);
    void setY(int y);
    int width();
    int height();
};
