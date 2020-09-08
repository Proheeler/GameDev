#include <Circle.h>
#include <SDL2/SDL.h>
#include <cmath>
#include <Window.h>
#include <RGBColor.h>
Circle::Circle(int radius) : IShape(0,0,2*radius,2*radius),m_radius(radius) {}
Circle::Circle(int radius, int posX, int posY) : IShape(posX,posY,2*radius,2*radius),m_radius(radius)
{
}
Circle::Circle(int width,int height,int posX, int posY): IShape(posX-width/2,posY-height/2,width,width),m_radius(width>>1)
{

}
void Circle::draw(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, getColor().r_channel, getColor().g_channel, getColor().b_channel, getColor().a_channel);
    for (int i = x() - m_radius; i <= x() + m_radius; i++)
    {
        for (int j = y() - m_radius; j <= y() + m_radius; j++)
        {
            if ((std::pow(y() - j, 2) + std::pow(x() - i, 2)) <=
                std::pow(m_radius, 2))
            {
                SDL_RenderDrawPoint(renderer, i, j);
            }
        }
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
}
void Circle::update(Window &window)
{
    if (x() + m_radius >= window.width || x() - m_radius <= 0)
    {
        m_speedX = -m_speedX;
    }
    if (y()  >= window.height || y() + m_radius <= 0)
    {
        m_speedY = -m_speedY;
    }
    setX(x()+m_speedX);
    setY(y()+m_speedY);
}
int Circle::radius()
{
    return m_radius;
}
