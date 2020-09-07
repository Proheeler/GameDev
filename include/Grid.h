#pragma once
#include "IShape.h"
#include <future>
#include <vector>
#include <Window.h>
template <typename FigureShape>
class Grid
{
private:
    std::vector<FigureShape> m_shapes;
    int m_rows;
    int m_cols;

public:
    Grid(Window w, int rows, int cols) : m_rows(rows), m_cols(cols)
    {
        int offset = 1;
        int width = w.width / cols;
        int height = w.height / (2 * rows);
        for (int i = 0; i < cols; ++i)
        {
            for (int j = 0; j < rows; ++j)
            {
                FigureShape tmpFig(width - offset, height - offset, width * i, j * height);
                RGBColor rect_color{(rand() % 255) + 1, (rand() % 255) + 1, (rand() % 255) + 1};
                tmpFig.setColor(rect_color);
                m_shapes.push_back(tmpFig);
            }
        }
    }
    void draw(SDL_Renderer *w)
    {
        for (auto &it : m_shapes)
        {
            it.draw(w);
        }
    }
    std::vector<FigureShape> *getFigures()
    {
        return &m_shapes;
    }
};
