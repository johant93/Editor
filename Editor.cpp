
#include "Editor.h"
#include <iostream>

using namespace std;

Editor::Editor(){
    Document document;
    quit = false ;
    
}

void Editor::open(){
    string line ;
    while (!quit) {
        getline(cin, line);
        
        if (line == "a") {
            Editor::document.append_after();
        }
        else if (line == "i"){
            Editor::document.insert_before();
        }
        else if (line == "p"){
            Editor::document.print_current();
        }
        else if (line == "%p"){
            cout << Editor::document;
        }
        else if (line == "n"){
            Editor::document.print_cur_index();
        }
        else if (line == "c"){
            Editor::document.swap_current();
        }
        else if (line == "d"){
            Editor::document.remove_current();
        }
        else if (line.substr(0,1) == "s"){
            Editor::document.swap(line.substr(1));
        }
        else if (line.substr(0,1) == "/"){
            Editor::document.search_after_current(line.substr(1));
        }
        else if (line == "Q"){
            quit = true;
        }
    }
}


