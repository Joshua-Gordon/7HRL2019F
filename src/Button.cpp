#include "Button.h"

#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"

#include <string>
#include <assert.h>
#include <iostream>

using namespace std;

extern int eventNum;

Button::Button(SDL_Renderer *rend_, string fontPath, int fontSize, int nextEventId_, string text_, int x_, int y_, int w_, int h_) {
    rend = rend_;
    rect.x = x_;
    rect.y = y_;
    rect.w = w_;
    rect.h = h_;
    
    font = TTF_OpenFont(fontPath.c_str(), fontSize);
    assert(font != NULL);

    SDL_Color col = {255, 255, 255, 255};
    SDL_Surface *sur = TTF_RenderText_Solid(font, text_.c_str(), col);
    assert(sur != nullptr);
    SDL_Texture *tex = SDL_CreateTextureFromSurface(rend, sur);
    text = tex;
    SDL_FreeSurface(sur);
}

Button::Button(SDL_Renderer *rend_, string fontPath, int fontSize, int nextEventId_, int x_, int y_, int w_, int h_) {
    rend = rend_;
    rect.x = x_;
    rect.y = y_;
    rect.w = w_;
    rect.h = h_;

    font = TTF_OpenFont(fontPath.c_str(), fontSize);
    assert(font != NULL);

    text = nullptr;
}

void Button::render() {
    SDL_RenderCopy(rend, text, NULL, &rect);
}


#define ID 0
#define TEXT 1
void Button::load(string &format) {
    int state = ID;
    size_t cur = format.find("-"),prev = 0;
    while(cur != string::npos) {
        switch(state) {
            case ID:
                nextEventId = atoi(format.substr(prev,cur).c_str());
                state = TEXT;
                break;
            case TEXT:
                setText(format.substr(prev,cur));
                state = 2;
                break;
            default:
                break;
        }
        prev = cur+1;
        cur = format.find("-",prev);
    }
}

void Button::setText(const string &text_) {
    if (text != nullptr) {
        SDL_DestroyTexture(text);
    }

    SDL_Color col = {255, 255, 255, 255};
    assert(font != nullptr);
    SDL_Surface *sur = TTF_RenderText_Solid(font, text_.c_str(), col);
    assert(sur != nullptr);
    SDL_Texture *tex = SDL_CreateTextureFromSurface(rend, sur);
    text = tex;
    SDL_FreeSurface(sur);
    rect.w = text_.length()*20;
}

void Button::handle(SDL_Event& e) {
    if (e.type == SDL_MOUSEBUTTONDOWN) {
        int mX;
        int mY;
        SDL_GetMouseState(&mX, &mY);
        if (mX >= rect.x && mX <= (rect.x + rect.w) && mY >= rect.y && mY <= (rect.y + rect.h)) {
            eventNum = nextEventId;
        }
    }
}
