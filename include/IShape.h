#pragma once
#include "RGBColor.h"

struct Window;
struct SDL_Renderer;
class IShape
{
private:
    /* data */
public:
    virtual void draw(SDL_Renderer *renderer, RGBColor const &  color) = 0;
    virtual void update(Window & window) = 0;

};

