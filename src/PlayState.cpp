#include <PlayState.h>
#include <iostream>
#include <Circle.h>
const std::string PlayState::s_playID = "Play";

void PlayState::update()
{
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
        //        std::cout << "drawing"<<std::endl;
        it->draw();
    }
    // nothing for now
}
bool PlayState::onEnter()
{
    std::cout << "entering PlayState\n";
    Circle *circle = new Circle;
    LoaderParams loadP(500,500,135,150,"fireball",6,0,25);
    circle->load(&loadP);
    m_gameObjects.push_back(circle);
    return true;
}
bool PlayState::onExit()
{
    std::cout << "exiting PlayState\n";
    return true;
}