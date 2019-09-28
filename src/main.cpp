#include "Menu.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL2_framerate.h"

#include <unistd.h>

#define WINWIDTH 720
#define WINHEIGHT 1080

int eventNum = 0;

int main() {
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    SDL_Window *win = SDL_CreateWindow("7HRL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINWIDTH, WINHEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer *rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_PRESENTVSYNC);

    FPSmanager FPSMan;
    SDL_initFramerate(&FPSMan);
    SDL_setFramerate(&FPSMan, 60);

    Menu m(0,rend);

    bool running = true;
    while(running) {
        SDL_RenderClear(rend);
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
