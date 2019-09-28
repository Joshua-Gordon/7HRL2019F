#include "Button.h"

#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"

#include <string>
#include <assert.h>

using namespace std;

Button::Button(SDL_Renderer *rend_, string fontPath, int fontSize, string text_, int x_, int y_, int w_, int h_) {
    rend = rend_;
    rect.x = x_;
    rect.y = y_;
    rect.w = w_;
    rect.h = h_;
    
    TTF_Font *font = TTF_OpenFont(fontPath.c_str(), fontSize);
    assert(font != NULL);

    SDL_Color col = {255, 255, 255, 255};
    SDL_Surface *sur = TTF_RenderText_Solid(font, text_.c_str(), col);
    assert(sur != nullptr);
    SDL_Texture *tex = SDL_CreateTextureFromSurface(rend, sur);
    text = tex;
    SDL_FreeSurface(sur);
}

void Button::render() {
    SDL_RenderCopy(rend, text, NULL, &rect);
}