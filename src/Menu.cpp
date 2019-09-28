#include "Menu.h"

#define IMAGE 0
#define TEXT 1
#define BTNS 2

Menu::Menu(int i,SDL_Renderer* r) {
    cerr << "Menu constructor" << endl;

    rend = r;

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
                Button b(rend,"assets/Lato.ttf",20,0,"Hello!",0,80*buttons.size(),100,100);
                b.load(line);
                buttons.push_back(b);
                cerr << "Created button\n";
                break;
        }
        if(file.eof()) {
            break;
        }
    }
    cerr << "Loaded file\n";

}

void Menu::render() {

    image.setRenderer(rend);
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
