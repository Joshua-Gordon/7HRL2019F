#pragma once
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include <string>

using namespace std;

class Button {
public:
    Button(SDL_Renderer *rend_, string filePath, int nextEventId_, int x_, int y_, int w_, int h_);
    Button(SDL_Renderer *rend_, string fontPath, int fontSize, int nextEventId_, string text, int x_, int y_, int w_, int h_);
    Button(SDL_Renderer *rend_, string fontPath, int fontSize, int nextEventId_, int x_, int y_, int w_, int h_);

    void render();
    void handle(SDL_Event& e);
    void load(string &format);
    void setText(const string &text_);

private:
    SDL_Renderer *rend;
    SDL_Rect rect;
    SDL_Texture *text;
    TTF_Font *font;
    int nextEventId;

};
