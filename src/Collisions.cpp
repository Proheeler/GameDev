#include <Collisions.h>
#include <algorithm>
#include <iostream>

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
    // template <class T1, class T2>
    bool isIntersecting(Circle &mA, Rectangle &mB) noexcept
    {
        return mA.x() + mA.radius() >= mB.x() - mB.width() / 2 && mA.x() - mA.radius() <= mB.x() + mB.width() / 2 &&
               mA.y() - mA.radius() >= mB.y() && mA.y() + mA.radius() <= mB.y() - mB.height();
    }
} // namespace
void checkCollision(Circle &circle, RectangleGrid &grid)
{
    std::vector<Rectangle> *rects = grid.getRects();
    if (!rects->empty())
    {
        rects->erase(std::remove_if(rects->begin(), rects->end(),
                                    [&circle](Rectangle rectangle) {
                                        // Find the closest point to the circle within the rectangle
                                        float closestX = clamp(circle.x(), rectangle.x(), rectangle.x() + rectangle.width());
                                        float closestY = clamp(circle.y(), rectangle.y() + rectangle.height(), rectangle.y());

                                        // Calculate the distance between the circle's center and this closest point
                                        float distanceX = circle.x() - closestX;
                                        float distanceY = circle.y() - closestY;

                                        // If the distance is less than the circle's radius, an intersection occurs
                                        float distanceSquared = (distanceX * distanceX) + (distanceY * distanceY);
                                        bool ret = distanceSquared < (circle.radius() * circle.radius());
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
    float closestX = clamp(circle.x(), rectangle.x(), rectangle.x() + rectangle.width());
    float closestY = clamp(circle.y(), rectangle.y() + rectangle.height(), rectangle.y());

    // Calculate the distance between the circle's center and this closest point
    float distanceX = circle.x() - closestX;
    float distanceY = circle.y() - closestY;

    // If the distance is less than the circle's radius, an intersection occurs
    float distanceSquared = (distanceX * distanceX) + (distanceY * distanceY);
    bool ret = distanceSquared < (circle.radius() * circle.radius());
    if(ret)
    std::cout << "Raddle collide with ball" << std::endl;
    // circle.m_speedY = -circle.m_speedY;
    // if (circle.x() < rectangle.x() + rectangle.width() / 2)
    //     circle.m_speedX = -circle.m_speedX;
    // else
    //     mBall.velocity.x = ballVelocity;
}