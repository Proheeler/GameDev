#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "GameObject.h"
#include "GameStateMachine.h"
#include <vector>

class Game
{	
	SDL_Window *m_pWindow;
	SDL_Renderer *m_pRenderer;

	//GameObject array
	// std::vector<GameObject*> m_gameObjects;
	
	int m_currentFrame;

	bool m_bRunning;

	//constructor is now private
	Game():m_bRunning(false){}
    ~Game() {
        // for(size_t i = 0; i<m_gameObjects.size();++i)
        //     delete m_gameObjects[i];
    }

	//s_pInstance member variable
	static Game* s_pInstance;

	//add an object of our GameStateMachine
	GameStateMachine* m_pGameStateMachine;

public:

	//instance function to make this class a singleton
	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}

	//function to return SDL_Renderer object
	SDL_Renderer* getRenderer() const { return m_pRenderer; }

	//function that allows access to state machine
	GameStateMachine* getStateMachine();
	
	bool init(const char *title, int xpos, int ypos, int height, int width, bool fullscreen);

	bool running();

	void handleEvents();
	void update();
	void render();
	void clean();
	
	void quit();

};

typedef Game TheGame;
