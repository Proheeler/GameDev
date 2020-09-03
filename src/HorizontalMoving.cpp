#include <HorizontalMoving.h>
#include <IShape.h>
#include <Window.h>
HorizontalMoving::HorizontalMoving(IShape * shape,Speed speed):IMovable(shape),m_speed(speed)
{
}

HorizontalMoving::~HorizontalMoving()
{
}

void HorizontalMoving::moveLeft(Window &window)
{
    if (shape()->x() - m_speed.x > 0)
        shape()->setX(shape()->x() - m_speed.x);
}
void HorizontalMoving::moveRight(Window &window)
{
    if (shape()->x() + m_speed.x + shape()->width() <= window.width)
        shape()->setX(shape()->x() + m_speed.x);
}
void HorizontalMoving::moveUp(Window &window)
{

}
void HorizontalMoving::moveDown(Window &window)
{

}
