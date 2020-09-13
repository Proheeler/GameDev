#include <Circle.h>
#include <SDL2/SDL.h>
#include <cmath>
#include <Window.h>
#include <RGBColor.h>
#include <GameParameters.h>

Circle::Circle()
{
    m_velocity = {m_speedX, m_speedY};
    m_numFrames=6;
    // m_currentFrame=1;
    // m_acceleration = {10,10};
}

void Circle::load(const LoaderParams *pParams)
{
    SDLGameObject::load(pParams);
}

void Circle::draw()
{
    SDLGameObject::draw();
}
void Circle::update()
{
    
    auto pos = getPosition();
    if (pos.getX() + getWidth() >= GameParameters::windowSize.x || pos.getX() + getWidth() / 2 <= 0)
    {
        m_velocity.setX(-m_velocity.getX());
        
    }
    if (pos.getY() + getWidth() >= GameParameters::windowSize.y || pos.getY() + getWidth() / 2 <= 0)
    {
        m_velocity.setY(-m_velocity.getY());
    }
    // m_velocity = {m_speedX, m_speedY};
    SDLGameObject::update();
}
void Circle::clean()
{
}
int Circle::radius()
{
    return m_radius;
}
    void Circle::setSpeedX()
    {
        m_velocity.setX(-m_velocity.getX());
    }
    void Circle::setSpeedY()
    {
        m_velocity.setY(-m_velocity.getY());
    }
