#include <RectangleGrid.h>
#include <iostream>
RectangleGrid::RectangleGrid(Window w, int rows, int cols) : m_rows(rows), m_cols(cols)
{
    int offset = 2;
    int width = w.width / cols;
    int height = w.height / (2 * rows);
    for (int i = 0; i < cols; ++i)
    {
        for (int j = 0; j < rows; ++j)
        {
            m_rects.push_back(Rectangle(width - offset, height - offset, width * i, j * height));
        }
    }
}
void RectangleGrid::draw(SDL_Renderer *w)
{
    RGBColor rect_color{255, 255, 100, 255};
    for (auto &it : m_rects)
    {
        it.draw(w, rect_color);
    }
}
std::vector<Rectangle> *RectangleGrid::getRects()
{
    return &m_rects;
}