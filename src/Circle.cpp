#include <Circle.h>
#include <SDL2/SDL.h>
#include <cmath>
#include <Window.h>
#include <RGBColor.h>
Circle::Circle(int radius) : m_radius(radius), m_posX(0), m_posY(0) {}
Circle::Circle(int radius, int posX, int posY) : m_radius(radius), m_posX(posX), m_posY(posY)
{
}
void Circle::draw(SDL_Renderer *renderer, RGBColor const & color)
{
    SDL_SetRenderDrawColor(renderer, color.r_channel, color.g_channel, color.b_channel, color.a_channel);

    // Drawing circle
    for (int x = m_posX - m_radius; x <= m_posX + m_radius; x++)
    {
        for (int y = m_posY - m_radius; y <= m_posY + m_radius; y++)
        {
            if ((std::pow(m_posY - y, 2) + std::pow(m_posX - x, 2)) <=
                std::pow(m_radius, 2))
            {
                SDL_RenderDrawPoint(renderer, x, y);
            }
        }
    }

    // Show the change on the screen
    SDL_RenderPresent(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
}
void Circle::update(Window &window)
{
    if (m_posX + m_radius >= window.width || m_posX - m_radius <= 0)
    {
        m_speedX = -m_speedX;
    }
    if (m_posY + m_radius >= window.height || m_posY - m_radius <= 0)
    {
        m_speedY = -m_speedY;
    }
    m_posX += m_speedX;
    m_posY += m_speedY;
}