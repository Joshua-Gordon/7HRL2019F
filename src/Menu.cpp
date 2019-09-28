#include "Menu.h"

#define IMAGE 0
#define TEXT 1
#define BTNS 2

Menu::Menu(int i,SDL_Renderer* r) {

    rend = r;

    int state = IMAGE;

    text = "";
    id = i;
    string filepath = to_string(id) + ".ev";

    ifstream file(filepath);
    string line;
    while(getline(file,line)) {
        switch(state) {
            case IMAGE:
                image.loadFromFile("assets/"+line);
                image.setRenderer(rend);
                state = TEXT;
                break;
            case TEXT:
                if(line.compare("EVENTS:") == 0) {
                    state = BTNS;
                    break;
                }
                text += line + "\n";
                break;
            case BTNS:
                Button b(rend,"assets/Lato.ttf",20,0,"Hello!",0,0,100,100);
                b.load(line);
                buttons.push_back(b);
                break;
        }
    }

}

void Menu::render() {

    image.render(0,0);
    for(auto i = buttons.begin(); i != buttons.end(); ++i) {
        i->render();
    }

}

void Menu::handle(SDL_Event& e) {
    for(auto i = buttons.begin(); i != buttons.end(); ++i) {
        i->handle(e);
    }
}
