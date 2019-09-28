#include "Button.h"

#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"

#include <string>

using namespace std;

Button::Button(SDL_Renderer *rend, string fontPath, int fontSize, string text, int x_, int y_, int w_, int h_) {
    rect.x = x_;
    rect.y = y_;
    rect.w = w_;
    rect.h = h_;
    
    TTF_Font *font = TTF_OpenFont(fontPath.c_str(), fontSize);

    SDL_Color col = {255, 255, 255, 255};
    SDL_Surface *sur = TTF_RenderText_Solid(font, text.c_str(), col);
    SDL_Texture *tex = SDL_CreateTextureFromSurface(rend, sur);
    SDL_FreeSurface(sur);

    

}