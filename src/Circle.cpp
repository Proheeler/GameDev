#include <Circle.h>
#include <SDL2/SDL.h>
#include <cmath>
#include <Window.h>
#include <RGBColor.h>
#include <GameParameters.h>
#include <FrameWork.h>


Circle::Circle()
{
    m_velocity ={10,10};
    m_acceleration = {10,10};
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
    SDLGameObject::update();
}
void Circle::clean()
{

}
int Circle::radius()
{
    return m_radius;
}
