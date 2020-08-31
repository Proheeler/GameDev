#include <Collisions.h>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <GameParameters.h>
namespace
{
    template <typename T>
    T clamp(T val, T min, T max)
    {
        if (val < min)
            val = min;
        else if (val > max)
            val = max;
        return val;
    }
    bool isIntersecting(Circle &circle, Rectangle rectangle) noexcept
    {
        auto DeltaX = circle.x() - std::max(rectangle.x(), std::min(circle.x(), rectangle.x() + +rectangle.width()));
        auto DeltaY = circle.y() - std::max(rectangle.y(), std::min(circle.y(), rectangle.y() + rectangle.height()));
        bool ret = (DeltaX * DeltaX + DeltaY * DeltaY) < (circle.radius() * circle.radius());
        return ret;
    }
} // namespace
void checkCollision(Circle &circle, RectangleGrid &grid)
{
    std::vector<Rectangle> *rects = grid.getRects();
    if (!rects->empty())
    {
        rects->erase(std::remove_if(rects->begin(), rects->end(),
                                    [&circle](Rectangle rectangle) {
                                        bool ret = isIntersecting(circle, rectangle);
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
void checkCollision(Circle &circle, Rectangle &rectangle)
{
    if (isIntersecting(circle, rectangle))
    {
        circle.m_speedY = -circle.m_speedY;
        if (circle.x() < rectangle.x() + rectangle.width() / 2)
            circle.m_speedX = -circle.m_speedX;
        else
            circle.m_speedX = circle.m_speedX;
    }
}