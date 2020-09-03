#include <TextureManager.h>

SDL_Texture* TextureManager::loadTexture(std::string path,SDL_Renderer* renderer,SDL_Rect* rect)
{
    SDL_Surface* pTempSurface = SDL_LoadBMP(path.c_str());
    SDL_Texture* m_pTexture = SDL_CreateTextureFromSurface(renderer,pTempSurface);
    SDL_QueryTexture(m_pTexture, NULL, NULL,&rect->w, &rect->h);
    SDL_RenderCopy(renderer, m_pTexture, NULL,NULL);
    return m_pTexture;
}