#include <Rectangle.h>

#include <SDL2/SDL.h>
#include <cmath>
#include <Window.h>
#include <RGBColor.h>
#include <FrameWork.h>
Rectangle::Rectangle()
{

}

void Rectangle::draw()
{
    SDLGameObject::draw();
}
void Rectangle::update()
{
}

void Rectangle::clean()
{

}

void Rectangle::moveUp(Window &window)
{
    m_movePolicy->moveUp(window);
}

void Rectangle::moveDown(Window &window)
{
    m_movePolicy->moveDown(window);
}

void Rectangle::moveLeft(Window &window)
{
    m_movePolicy->moveLeft(window);
}
void Rectangle::moveRight(Window &window)
{
    m_movePolicy->moveRight(window);
}

void Rectangle::setMovePolicy(IMovable *value)
{
    m_movePolicy = value;
}
