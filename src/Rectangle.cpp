#include <Rectangle.h>

#include <SDL2/SDL.h>
#include <cmath>
#include <Window.h>
#include <RGBColor.h>

Rectangle::Rectangle(int width, int height) : IShape(0,0,width,height) {}


Rectangle::Rectangle(int width, int height, int posX, int posY) : IShape(posX,posY,width,height)
{
}

void Rectangle::draw(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, getColor().r_channel, getColor().g_channel, getColor().b_channel, getColor().a_channel);

    SDL_Rect r;
    r.x = x();
    r.y = y();
    r.w = width();
    r.h = height();

    // Show the change on the screen
    SDL_RenderFillRect(renderer, &r);
    // SDL_RenderPresent(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
}
void Rectangle::update(Window &window)
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
