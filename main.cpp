
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

#include <Rectangle.h>
#include <Circle.h>
#include <RGBColor.h>
#include <Window.h>
#include <RectangleGrid.h>
#include <Collisions.h>
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

    // Creating the object by passing Height and Width value.
    Window w{1000, 1000};
    Framework fw(1000, 1000);

    // Calling the function that draws circle.
    Circle m(20, 500, 500);
    RGBColor color{255, 0, 0, 255};
    RGBColor rect_color{50, 255, 100, 255};
    m.draw(fw.getRenderer(), color);
    Rectangle rect(200, 50, w.width / 2 - 100 / 2, w.height - 20);
    rect.draw(fw.getRenderer(), rect_color);
    SDL_Event event; // Event variable
    RectangleGrid grid(w,10,10);
    // Below while loop checks if the window has terminated using close in the
    //  corner.
    while (!(event.type == SDL_QUIT))
    {
        SDL_Delay(20);         // setting some Delay
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
    

    
    m.update(w);
    grid.draw(fw.getRenderer());
    m.draw(fw.getRenderer(), color);
    rect.draw(fw.getRenderer(), rect_color);
    SDL_RenderPresent(fw.getRenderer());
    SDL_RenderClear(fw.getRenderer());
    checkCollision(m,grid);
    checkCollision(m,rect);
}   
}
