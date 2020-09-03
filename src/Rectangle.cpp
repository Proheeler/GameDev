#include <Rectangle.h>

#include <SDL2/SDL.h>
#include <cmath>
#include <Window.h>
#include <RGBColor.h>

Rectangle::Rectangle(int width, int height) : IShape(0,0,width,height) {}


Rectangle::Rectangle(int width, int height, int posX, int posY) : IShape(posX,posY,width,height)
{
}

void Rectangle::draw(SDL_Renderer *renderer, RGBColor const &color)
{
    SDL_SetRenderDrawColor(renderer, color.r_channel, color.g_channel, color.b_channel, color.a_channel);

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
    movePolicy->moveUp(window);
}

void Rectangle::moveDown(Window &window)
{
    movePolicy->moveDown(window);
}

void Rectangle::moveLeft(Window &window)
{
    movePolicy->moveLeft(window);
}
void Rectangle::moveRight(Window &window)
{
    movePolicy->moveRight(window);
}

void Rectangle::setMovePolicy(IMovable *value)
{
    movePolicy = value;
}
