#include <Brick.h>

#include <SDL2/SDL.h>
#include <cmath>
#include <Window.h>
#include <RGBColor.h>
#include <Game.h>
Brick::Brick(int width,int height,int x,int y)
{
    m_position = {x,y};
    m_width = width;
    m_height = height;
}

void Brick::draw()
{
    SDL_SetRenderDrawColor(Game::Instance()->getRenderer(), 255,100,100,0);

    SDL_Rect r;
    r.x = m_position.getX();
    r.y = m_position.getY();
    r.w = m_width;
    r.h = m_height;

    // Show the change on the screen
    SDL_RenderFillRect(Game::Instance()->getRenderer(), &r);
    // SDL_RenderPresent(renderer);
    SDL_SetRenderDrawColor(Game::Instance()->getRenderer(), 0, 0, 0, 0);
}
void Brick::update()
{
}

void Brick::clean()
{

}

void Brick::moveUp(Window &window)
{
    m_movePolicy->moveUp(window);
}

void Brick::moveDown(Window &window)
{
    m_movePolicy->moveDown(window);
}

void Brick::moveLeft(Window &window)
{
    m_movePolicy->moveLeft(window);
}
void Brick::moveRight(Window &window)
{
    m_movePolicy->moveRight(window);
}

void Brick::setMovePolicy(IMovable *value)
{
    m_movePolicy = value;
}
