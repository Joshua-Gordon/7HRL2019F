#include "Menu.h"

#define IMAGE 0
#define TEXT 1
#define BTNS 2

Menu::Menu(int i,SDL_Renderer* r) {
    cerr << "Menu constructor" << endl;

    rend = r;

    loadFile(i);
}

void Menu::loadFile(int i) {
    buttons.clear();
    int state = IMAGE;

    text = "";
    id = i;
    string filepath = "events/" + to_string(id) + ".ev";
    cerr << "Loading file " << "filepath";

    ifstream file(filepath);
    string line;
    while(getline(file,line)) {
        cerr << "Read line: " << line << endl;
        switch(state) {
            case IMAGE:
                image.setRenderer(rend);
                image.loadFromFile("assets/"+line);
                cerr << "Loaded image assets/" << line << endl;
                state = TEXT;
                break;
            case TEXT:
                if(line.compare("EVENTS:") == 0) {
                    state = BTNS;
                    break;
                }
                text += line + "\n";
                cerr << "Wrote text\n";
                break;
            case BTNS:
                Button b(rend,"assets/Lato.ttf",20,0,"Hello!",0,680+80*buttons.size(),100,100);
                b.load(line);
                buttons.push_back(b);
                cerr << "Created button\n";
                break;
        }
        if(file.eof()) {
            break;
        }
    }
    TTF_Font* font = TTF_OpenFont("assets/Lato.ttf",20);
    SDL_Color col = {255, 255, 255, 255};
    SDL_Surface *sur = TTF_RenderText_Blended_Wrapped(font, text.c_str(), col,720);
    SDL_Texture *tex = SDL_CreateTextureFromSurface(rend, sur);
    caption = Texture(rend,tex,720,200);

    cerr << "Loaded file\n";
}

void Menu::render() {
    image.setRenderer(rend);
    image.render(0,0);
    caption.render(0,480);
    for(auto i = buttons.begin(); i != buttons.end(); ++i) {
        i->render();
    }

}

void Menu::handle(SDL_Event& e) {
    for(auto i = buttons.begin(); i != buttons.end(); ++i) {
        i->handle(e);
    }
}

void Menu::setEvent(int eventId) {
    if (id == eventId) {
        return;
    }

    loadFile(eventId);
}
