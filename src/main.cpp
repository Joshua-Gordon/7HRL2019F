#include "Menu.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"

#include <unistd.h>

#define WINWIDTH 640
#define WINHEIGHT 480

int eventNum = 0;

int main() {
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    SDL_Window *win = SDL_CreateWindow("7HRL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINWIDTH, WINHEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer *rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_PRESENTVSYNC);
    Button but(rend, "assets/Lato.ttf", 20, "Hello!", 0, 0, 100, 100);

    while(1) {
        SDL_RenderClear(rend);
        but.render();
        SDL_RenderPresent(rend);
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    return 1;

            }
        }
        sleep(1);
    }

    return 0;
}