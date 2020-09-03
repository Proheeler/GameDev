#include <SDL2/SDL.h>
#include <string>
class TextureManager
{
private:
    /* data */
public:
    static SDL_Texture* loadTexture(std::string path,SDL_Renderer* renderer,SDL_Rect* rect);
};


