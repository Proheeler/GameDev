#include <Game.h>
#include <TextureManager.h>
#include <InputHandler.h>
#include <Circle.h>
// #include <MainMenuState.h>
#include "PlayState.h"
// #include "MenuButton.h"

//definition for static instance 
Game* Game::s_pInstance = 0;

bool Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{	
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	//attempt to initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{	
		std::cout << "SDL init success\n";
		//init the window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (m_pWindow != 0)	//window init success
		{
			std::cout << "Window creation success\n";
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if (m_pRenderer != 0) //renderer init success
			{
				std::cout << "renderer init success\n";
				SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
			}
			else
			{
				std::cout << "renderer init failed\n";
				return false;	//renderer init fail
			}
		}
		else
		{
			std::cout << "window init fail\n";
			return false;	//window init fail
		}
	}
	else
	{
		std::cout << "SDL init fail\n";
		return false;	//SDL init fail
	}
	
	//initialise joysticks
	TheInputHandler::Instance()->initialiseJoysticks();

	std::cout << "init success\n";
    //load TextureManager
     if (!TheTextureManager::Instance()->load("/home/dev/development/sdlDev/assets/sprites/Fireball.png", "fireball", m_pRenderer))
     {
        std::cout<<"Ball not loaded"<<std::endl;
     }
    Circle *circle = new Circle;
    LoaderParams loadP(500,500,120,120,"fireball",6,0,2);
    circle->load(&loadP);
    m_gameObjects.push_back(circle);


	

	m_bRunning = true;	//everything inited successfully, start the main loop
    m_pGameStateMachine = new GameStateMachine();
    m_pGameStateMachine->pushState(new PlayState());
	//load MENU state 
	// TheGameObjectFactory::instance()->registerType("MenuButton", new MenuButtonCreator());

	return true;
}

bool Game::running()
{
	return m_bRunning;
}

GameStateMachine* Game::getStateMachine()
{
	return m_pGameStateMachine;
}

void Game::handleEvents()
{	
	//waits and listens for a quit event 
	TheInputHandler::Instance()->update();

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
	{
		m_pGameStateMachine->changeState(new PlayState());
	}
}

void Game::update()
{
    for(auto const &it:m_gameObjects)
    {
        it->update();
    }
	//use GameStateMachine's update function
	m_pGameStateMachine->update();
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer); //clear the renderer to the draw color
    for(auto const &it:m_gameObjects)
    {
//        std::cout << "drawing"<<std::endl;
        it->draw();
    }
	//use GameStateMachine's render function
	m_pGameStateMachine->render();

	SDL_RenderPresent(m_pRenderer);	//draw to the screen
}

void Game::clean()
{
	std::cout << "cleaning game\n";
	
	//close the joysticks
	TheInputHandler::Instance()->clean();

	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::quit()
{
	m_bRunning = false;
}
