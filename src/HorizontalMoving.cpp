#include <HorizontalMoving.h>
#include <Window.h>
HorizontalMoving::HorizontalMoving(SDLGameObject * shape,Speed speed):IMovable(shape),m_speed(speed)
{
}

HorizontalMoving::~HorizontalMoving()
{
}

void HorizontalMoving::moveLeft(Window &window)
{
    if (shape()->getPosition().getX() - m_speed.x > 0)
        shape()->setPosition({shape()->getPosition().getX() - m_speed.x,shape()->getPosition().getY()});
}
void HorizontalMoving::moveRight(Window &window)
{
    if (shape()->getPosition().getX() + m_speed.x + shape()->getWidth() <= window.width)
        shape()->setPosition({shape()->getPosition().getX() + m_speed.x,shape()->getPosition().getY()});
}
void HorizontalMoving::moveUp(Window &window)
{

}
void HorizontalMoving::moveDown(Window &window)
{

}
