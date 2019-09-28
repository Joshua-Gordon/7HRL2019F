#include "menu.h"

#define IMAGE 0
#define TEXT 1
#define BTNS 2

Menu::Menu(int i) {

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

                break;
        }
    }

}
