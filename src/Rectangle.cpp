#include <Rectangle.h>

#include <SDL2/SDL.h>
#include <cmath>
#include <Window.h>
#include <RGBColor.h>
Rectangle::Rectangle(int width, int height) : m_width(width), m_height(height), m_posX(0), m_posY(0) {}
Rectangle::Rectangle(int width, int height, int posX, int posY) : m_width(width), m_height(height), m_posX(posX), m_posY(posY)
{
}
void Rectangle::draw(SDL_Renderer *renderer, RGBColor const &color)
{
    SDL_SetRenderDrawColor(renderer, color.r_channel, color.g_channel, color.b_channel, color.a_channel);

    // Drawing circle
    SDL_Rect r;
    r.x = m_posX;
    r.y = m_posY;
    r.w = m_width;
    r.h = m_height;

    // Show the change on the screen
    SDL_RenderFillRect(renderer, &r);
    SDL_RenderPresent(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
}
void Rectangle::update(Window &window)
{
}
void Rectangle::moveUp(Window &window)
{
    // if (m_posY - m_speedY + m_height > 0)
    //     m_posY -= m_speedY;
}
void Rectangle::moveDown(Window &window)
{
    // if (m_posY + m_speedY + m_height<= window.height )
    //     m_posY += m_speedY;
}
void Rectangle::moveLeft(Window &window)
{
    if (m_posX - m_speedX > 0)
        m_posX -= m_speedX;
}
void Rectangle::moveRight(Window &window)
{
    if (m_posX + m_speedX + m_width <= window.width)
        m_posX += m_speedX;
}