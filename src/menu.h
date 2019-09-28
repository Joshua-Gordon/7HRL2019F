#pragma once
#include "SDL2/SDL.h"
#include "Button.h"
#include "Texture.h"

#include <vector>
#include <fstream>
#include <string>

using namespace std;

class Menu {
public:
    Menu(int);

    void handle(SDL_Event& e);


private:
    int id;
    string text;
    Texture image;
    vector<Button> buttons;

};
