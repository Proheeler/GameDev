#include <PlayState.h>
#include <iostream>
#include <Circle.h>
#include <Grid.h>
#include <Collisions.h>
const std::string PlayState::s_playID = "Play";

void PlayState::update()
{
    // for(size_t i = 0 ; i < m_gameObjects.size()-1;++i)
    // {
        checkCollision(dynamic_cast<Circle*>(m_gameObjects[0]),dynamic_cast<Grid*>(m_gameObjects[1]));
    // }
    for (auto const &it : m_gameObjects)
    {

        it->update();
    }
    // nothing for now
}
void PlayState::render()
{
    for (auto const &it : m_gameObjects)
    {
        it->draw();
    }
    // nothing for now
}
bool PlayState::onEnter()
{
    std::cout << "entering PlayState\n";
    Circle *circle = new Circle;
    LoaderParams loadP(500,700,135,150,"fireball",6,0,25);
    circle->load(&loadP);
    m_gameObjects.push_back(circle);

    Grid *grid = new Grid(10,10);
    m_gameObjects.push_back(grid);
    return true;
}
bool PlayState::onExit()
{
    std::cout << "exiting PlayState\n";
    return true;
}