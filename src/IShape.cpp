#include <IShape.h>
IShape::IShape(int x, int y, int width, int height):m_posX(x),m_posY(y),m_width(width),m_height(height)
{
}

int IShape::x()
{
    return m_posX;
}

int IShape::y()
{
    return m_posY;
}

void IShape::setX(int x)
{
    m_posX = x;
}

void IShape::setY(int y)
{
    m_posY = y;
}

int IShape::width()
{
    return m_width;
}

int IShape::height()
{
    return m_height;
}
