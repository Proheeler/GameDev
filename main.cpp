
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
// #include <SDL2/>
#include <Rectangle.h>
#include <Circle.h>
#include <RGBColor.h>
#include <Window.h>
#include <Collisions.h>
#include <GameParameters.h>
#include <iostream>
#include <HorizontalMoving.h>
#include <Grid.h>

#include <TextureManager.h>
#include <Game.h>
#include <MenuState.h>
constexpr const int FPS = 25;
constexpr const int DELAY_TIME = 1000.0 / FPS;

void renderText(SDL_Renderer *renderer, Window w)
{
    TTF_Font *font = TTF_OpenFont("/home/dev/development/sdlDev/assets/fonts/KaBlam.ttf", 50);
    if (font != NULL)
    {
        std::string score_text = "GAME OVER";
        SDL_Color textColor = {255, 0, 0, 0};
        SDL_Surface *textSurface = TTF_RenderText_Solid(font, score_text.c_str(), textColor);
        SDL_Texture *text = SDL_CreateTextureFromSurface(renderer, textSurface);
        SDL_FreeSurface(textSurface);
        SDL_Rect renderQuad = {GameParameters::windowSize.x / 2 - 100, GameParameters::windowSize.y / 2, 200, 50};
        SDL_RenderCopy(renderer, text, NULL, &renderQuad);
        SDL_DestroyTexture(text);
        TTF_CloseFont(font);
    }
    else
    {
        fprintf(stderr, "error: font not found\n");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[])
{
	Uint32 frameStart, frameTime;
    if (TheGame::Instance()->init("Game", 100, 100, 1000, 1000, false))
	{
		while (TheGame::Instance()->running())
		{	

            frameStart = SDL_GetTicks();
            GameStateMachine *state = TheGame::Instance()->getStateMachine();
//            state->pushState(new MenuState());
			TheGame::Instance()->handleEvents();
			TheGame::Instance()->update();
			TheGame::Instance()->render();
//            state->popState();


			frameTime = SDL_GetTicks() - frameStart;

			if (frameTime < DELAY_TIME)
			{
				SDL_Delay((int)(DELAY_TIME - frameTime));
			}
		}
	}
	else
	{
		std::cout << "game init failure - " << SDL_GetError() << "\n";
		return -1;
	}

	std::cout << "game closing...\n";
	TheGame::Instance()->clean();
}
// int main(int argc, char *argv[])
// {
//     TTF_Init();
//     // Creating the object by passing Height and Width value.
//     Window w{GameParameters::windowSize.x, GameParameters::windowSize.y};
//     Framework fw(w.width, w.height);

//     // Calling the function that draws circle.
//     Circle m(GameParameters::ballRadius, GameParameters::circlePos.x, GameParameters::circlePos.y);
//     RGBColor color{255, 0, 0, 255};
//     RGBColor rect_color{50, 255, 100, 255};
//     m.setColor(color);
//     m.draw(fw.getRenderer());
//     Rectangle rect(GameParameters::paddleSize.x,
//                    GameParameters::paddleSize.y,
//                    GameParameters::paddlePos.x,
//                    GameParameters::windowSize.y - GameParameters::paddleSize.y);
//     HorizontalMoving mp(&rect, {GameParameters::paddleSpeed.x, GameParameters::paddleSpeed.x});
//     rect.setMovePolicy(&mp);
//     rect.setColor(rect_color);
//     rect.draw(fw.getRenderer());
//     SDL_Event event; // Event variable
//     Grid<Rectangle> grid(w, GameParameters::gridSize.x, GameParameters::gridSize.y);
//     Uint32 frameStart, frameTime;

//     while (!(event.type == SDL_QUIT))
//     {
//         frameStart = SDL_GetTicks();
// //        SDL_Delay(20);         // setting some Delay
//         SDL_PollEvent(&event); // Catching the poll event.
//         switch (event.type)
//         {
//         case SDL_KEYDOWN:
//             // keyboard API for key pressed
//             switch (event.key.keysym.scancode)
//             {
//             case SDL_SCANCODE_W:
//             case SDL_SCANCODE_UP:
//                 rect.moveUp(w);
//                 break;
//             case SDL_SCANCODE_A:
//             case SDL_SCANCODE_LEFT:
//                 rect.moveLeft(w);
//                 break;
//             case SDL_SCANCODE_S:
//             case SDL_SCANCODE_DOWN:
//                 rect.moveDown(w);
//                 break;
//             case SDL_SCANCODE_D:
//             case SDL_SCANCODE_RIGHT:
//                 rect.moveRight(w);
//                 break;
//             }
//         }
//         if (grid.getFigures()->empty())
//         {
//             SDL_RenderClear(fw.getRenderer());
//             renderText(fw.getRenderer(), w);
//             SDL_RenderPresent(fw.getRenderer());
//             continue;
//         }
//         m.update(w);
//         grid.draw(fw.getRenderer());
//         m.draw(fw.getRenderer());
//         rect.draw(fw.getRenderer());
//         SDL_RenderPresent(fw.getRenderer());
//         SDL_RenderClear(fw.getRenderer());
//         checkCollision(m, grid);
//         checkCollision(m, rect,[](Circle &circle,Rectangle& rectangle)
//         {
//             circle.m_speedY = -circle.m_speedY;
//             if (circle.x() < rectangle.x() + rectangle.width() / 2)
//                 circle.m_speedX = -circle.m_speedX;
//             else
//                 circle.m_speedX = circle.m_speedX;
//         });
//         frameTime = SDL_GetTicks() - frameStart;
//         if (frameTime < Delay)
//         {
//             SDL_Delay((int)(Delay - frameTime));
//         }
//     }
// }
