#pragma once
#include <Rectangle.h>
#include <vector>
#include <Window.h>
#include <map>

class RectangleGrid
{
private:
    std::vector<Rectangle> m_rects;
    int m_rows;
    int m_cols;
public:
    RectangleGrid(Window w,int rows,int cols);
    void draw(SDL_Renderer * w);
    std::vector<Rectangle> * getRects();
};

