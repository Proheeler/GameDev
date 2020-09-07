#include "Circle.h"
#include "Rectangle.h"
#include <algorithm>
#include "Grid.h"
template <typename T>
T clamp(T val, T min, T max)
{
    if (val < min)
        val = min;
    else if (val > max)
        val = max;
    return val;
}
template<typename FigureShape_1,typename FigureShape_2>
bool isIntersecting(FigureShape_1 &circle, FigureShape_2 rectangle) noexcept
{
    auto DeltaX = circle.x() - std::max(rectangle.x(), std::min(circle.x(), rectangle.x() + +rectangle.width()));
    auto DeltaY = circle.y() - std::max(rectangle.y(), std::min(circle.y(), rectangle.y() + rectangle.height()));
    bool ret = (DeltaX * DeltaX + DeltaY * DeltaY) < (circle.radius() * circle.radius());
    return ret;
}

template <typename FigureShape_1,typename FigureShape_2>
void checkCollision(FigureShape_1 &circle, Grid<FigureShape_2> &grid)
{
    std::vector<FigureShape_2> *rects = grid.getFigures();
    if (!rects->empty())
    {
        rects->erase(std::remove_if(rects->begin(), rects->end(),
                                    [&circle](FigureShape_2 shape) {
                                        bool ret = isIntersecting(circle, shape);
                                        if (ret)
                                        {
                                            circle.m_speedX = -circle.m_speedX;
                                            circle.m_speedY = -circle.m_speedY;
                                        }
                                        return ret;
                                    }),
                     rects->end());
    }
}
template <typename FigureShape,typename Action>
void checkCollision(Circle &circle, FigureShape &rectangle,Action logicAction)
{
    if (isIntersecting(circle, rectangle))
    {
        logicAction(circle,rectangle);
    }
}
