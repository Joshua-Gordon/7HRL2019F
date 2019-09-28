#include "Menu.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL2_framerate.h"

#include <unistd.h>

#define WINWIDTH 720
#define WINHEIGHT 1080

int eventNum = -1;

int main() {
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    SDL_Window *win = SDL_CreateWindow("7HRL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINWIDTH, WINHEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer *rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_PRESENTVSYNC);

    FPSmanager FPSMan;
    SDL_initFramerate(&FPSMan);
    SDL_setFramerate(&FPSMan, 60);

    Menu m(0,rend);

    Menu startMenu(-1, rend);
    Button start(rend, "assets/btn.png", 0, 200, 380, 336, 117);

    bool running = true;
    while(running) {
        SDL_RenderClear(rend);
        if (eventNum == -1) { //I'm sorry, I was told to do this...
            startMenu.render();
            start.render();
            SDL_Event event;
            SDL_PollEvent(&event);
            start.handle(event);
            switch (event.type) {
                case SDL_QUIT:
                    return 1;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_q:
                            running = false;
                    }
            }
            SDL_RenderPresent(rend);
            SDL_framerateDelay(&FPSMan);
            continue;
        }

        m.setEvent(eventNum);
        m.render();
        SDL_RenderPresent(rend);
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            m.handle(event);
            switch (event.type) {
                case SDL_QUIT:
                    return 1;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_q:
                            running = false;
                    }
            }
        }
        SDL_framerateDelay(&FPSMan);
    }

    return 0;
}
