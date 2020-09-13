#pragma once
#include "Circle.h"
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
// template <typename FigureShape_1, typename FigureShape_2>
inline bool isIntersecting(SDLGameObject *circle, SDLGameObject* rectangle) noexcept
{
    auto DeltaX = circle->getPosition().getX() - std::max(rectangle->getPosition().getX(), std::min(circle->getPosition().getX(), rectangle->getPosition().getX() + rectangle->getWidth()));
    auto DeltaY = circle->getPosition().getX() - std::max(rectangle->getPosition().getY(), std::min(circle->getPosition().getY(), rectangle->getPosition().getY() + rectangle->getHeight()));
    bool ret = (DeltaX * DeltaX + DeltaY * DeltaY) < (circle->getWidth() * circle->getWidth());
    return ret;
}

inline void checkCollision(Circle *circle, Grid *grid)
{
    std::vector<Brick> *rects = grid->getFigures();
    if (!rects->empty())
    {
        rects->erase(std::remove_if(rects->begin(), rects->end(),
                                    [&circle](Brick shape) {
                                        bool ret = isIntersecting(circle, &shape);
                                        if (ret)
                                        {
                                            circle->setSpeedX();//->m_speedX = -circle->m_speedX;
                                            circle->setSpeedY();//->m_speedY = -circle->m_speedY;
                                        }
                                        return ret;
                                    }),
                     rects->end());
    }
}
inline void checkCollision(Circle *circle, Brick *rectangle)
{
    if (isIntersecting(circle, rectangle))
    {
        circle->setSpeedY();
        if (circle->getPosition().getX() < rectangle->getPosition().getX() + rectangle->getWidth() / 2)
            circle->setSpeedX();//->m_speedX = -circle->m_speedX;
        // else//
        //     circle->m_speedX = circle->m_speedX;
    }
}
