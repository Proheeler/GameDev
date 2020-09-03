
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
// #include <SDL2/>
#include <Rectangle.h>
#include <Circle.h>
#include <RGBColor.h>
#include <Window.h>
#include <RectangleGrid.h>
#include <Collisions.h>
#include <GameParameters.h>
#include <iostream>
#include <HorizontalMoving.h>
void renderText(SDL_Renderer *renderer, Window &w)
{
    TTF_Font *font = TTF_OpenFont("/home/dev/development/sdlDev/assets/fonts/KaBlam.ttf", 50);
    if (font != NULL)
    {
        std::string score_text = "GAME OVER";
        SDL_Color textColor = {255, 0, 0, 0};
        SDL_Surface *textSurface = TTF_RenderText_Solid(font, score_text.c_str(), textColor);
        SDL_Texture *text = SDL_CreateTextureFromSurface(renderer, textSurface);
        int text_width = textSurface->w;
        int text_height = textSurface->h;
        SDL_FreeSurface(textSurface);
        SDL_Rect renderQuad = { GameParameters::windowSize.x/2-100, GameParameters::windowSize.y/2,200,50};
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

class Framework
{
public:
    // Contructor which initialize the parameters.
    Framework(int height_, int width_) : height(height_), width(width_)
    {
        SDL_Init(SDL_INIT_VIDEO); // Initializing SDL as Video
        SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0); // setting draw color
        SDL_RenderClear(renderer);                    // Clear the newly created window
        SDL_RenderPresent(renderer);                  // Reflects the changes done in the
                                                      //  window.
    }

    // Destructor
    ~Framework()
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    SDL_Renderer *getRenderer()
    {
        return renderer;
    }

private:
    int height;                    // Height of the window
    int width;                     // Width of the window
    SDL_Renderer *renderer = NULL; // Pointer for the renderer
    SDL_Window *window = NULL;     // Pointer for the window
};

int main(int argc, char *argv[])
{
    TTF_Init();
    // Creating the object by passing Height and Width value.
    Window w{GameParameters::windowSize.x, GameParameters::windowSize.y};
    Framework fw(w.width, w.height);

    // Calling the function that draws circle.
    Circle m(GameParameters::ballRadius, GameParameters::circlePos.x, GameParameters::circlePos.y);
    RGBColor color{255, 0, 0, 255};
    RGBColor rect_color{50, 255, 100, 255};
    m.setColor(color);
    m.draw(fw.getRenderer());
    Rectangle rect(GameParameters::paddleSize.x,
                   GameParameters::paddleSize.y,
                   GameParameters::paddlePos.x,
                   GameParameters::windowSize.y - GameParameters::paddleSize.y);
    HorizontalMoving mp(&rect,{GameParameters::paddleSpeed.x,GameParameters::paddleSpeed.x});
    rect.setMovePolicy(&mp);
    rect.setColor(rect_color);
    rect.draw(fw.getRenderer());
    SDL_Event event; // Event variable
    RectangleGrid grid(w, GameParameters::gridSize.x, GameParameters::gridSize.y);

    while (!(event.type == SDL_QUIT))
    {
        SDL_Delay(0);          // setting some Delay
        SDL_PollEvent(&event); // Catching the poll event.
        switch (event.type)
        {
        case SDL_KEYDOWN:
            // keyboard API for key pressed
            switch (event.key.keysym.scancode)
            {
            case SDL_SCANCODE_W:
            case SDL_SCANCODE_UP:
                rect.moveUp(w);
                break;
            case SDL_SCANCODE_A:
            case SDL_SCANCODE_LEFT:
                rect.moveLeft(w);
                break;
            case SDL_SCANCODE_S:
            case SDL_SCANCODE_DOWN:
                rect.moveDown(w);
                break;
            case SDL_SCANCODE_D:
            case SDL_SCANCODE_RIGHT:
                rect.moveRight(w);
                break;
            }
        }
        if (grid.getRects()->empty())
        {
            SDL_RenderClear(fw.getRenderer());
            renderText(fw.getRenderer(), w);
            SDL_RenderPresent(fw.getRenderer());
            continue;
        }
        m.update(w);
        grid.draw(fw.getRenderer());
        m.draw(fw.getRenderer());
        rect.draw(fw.getRenderer());
        SDL_RenderPresent(fw.getRenderer());
        SDL_RenderClear(fw.getRenderer());
        checkCollision(m, grid);
        checkCollision(m, rect);
    }
}
