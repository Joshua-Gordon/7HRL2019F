#pragma once
#include "SDL2/SDL.h"
#include <string>

using namespace std;

class Button {
public:
    Button(SDL_Renderer *rend_, string fontPath, int fontSize, int nextEventId_, string text, int x_, int y_, int w_, int h_);
    void render();
    void load(string &format);

    SDL_Renderer *rend;
    SDL_Rect rect;
    SDL_Texture *text;
    int nextEventId;
};