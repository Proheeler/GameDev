#include <RectangleGrid.h>
#include <iostream>
#include <cstdlib>
RectangleGrid::RectangleGrid(Window w, int rows, int cols) : m_rows(rows), m_cols(cols)
{
    int offset = 1;
    int width = w.width / cols;
    int height = w.height / (2 * rows);
    for (int i = 0; i < cols; ++i)
    {
        for (int j = 0; j < rows; ++j)
        {
            Rectangle tmpRect(width - offset, height - offset, width * i, j * height);
            RGBColor rect_color{(rand() % 255) + 1, (rand() % 255) + 1, (rand() % 255) + 1};
            tmpRect.setColor(rect_color);
            m_rects.push_back(tmpRect);
        }
    }
}
void RectangleGrid::draw(SDL_Renderer *w)
{

    for (auto &it : m_rects)
    {
        it.draw(w);
    }
}
std::vector<Rectangle> *RectangleGrid::getRects()
{
    return &m_rects;
}