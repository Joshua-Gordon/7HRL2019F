#pragma once
#include "SDL2/SDL.h"
#include "Button.h"
#include "Texture.h"

#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Menu {
public:
    Menu(int,SDL_Renderer*);

    void render();
    void handle(SDL_Event& e);
    void loadFile(int);
    void setEvent(int eventId);

private:

    SDL_Renderer* rend;

    int id;
    string text;
    Texture image;
    vector<Button> buttons;
};
