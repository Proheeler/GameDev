#pragma once
#include <future>
#include <vector>
#include <Window.h>
#include <SDL2/SDL.h>
#include <SDLGameObject.h>
#include <GameParameters.h>
#include <Brick.h>
class Grid:public SDLGameObject
{
private:
    std::vector<Brick> m_shapes;
    int m_rows;
    int m_cols;

public:
    Grid(int rows, int cols) : m_rows(rows), m_cols(cols)
    {
        int offset = 1;
        int width = GameParameters::windowSize.x / cols;
        int height = GameParameters::windowSize.y / (2 * rows);
        for (int i = 0; i < cols; ++i)
        {
            for (int j = 0; j < rows; ++j)
            {
                Brick tmpFig(width - offset, height - offset, width * i, j * height);;
                // RGBColor rect_color{(rand() % 255) + 1, (rand() % 255) + 1, (rand() % 255) + 1};
                // tmpFig.setColor(rect_color);
                m_shapes.push_back(tmpFig);
            }
        }
    }
    virtual void draw()
    {
        for (auto &it : m_shapes)
        {
            it.draw();
        }
    }
	virtual void update()
    {

    }
	virtual void clean()
    {

    }

    std::vector<Brick> *getFigures()
    {
        return &m_shapes;
    }
};
