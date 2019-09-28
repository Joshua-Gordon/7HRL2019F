#pragma once
#include "SDL2/SDL.h"
#include <string>

using namespace std;

class Button {
public:
    Button(SDL_Renderer *rend, string fontPath, int fontSize, string text, int x_, int y_, int w_, int h_);

    SDL_Rect rect;
    SDL_Texture *text;

};