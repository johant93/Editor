//###################################################
//##########Yehonatan Shaag 308357953################
//##########Johann Thuillier 336104120 ################
//###################################################

#include "Editor.h"
#include <iostream>

using namespace std;

Editor::Editor(){
    Document document;
    quit = false ;
    
}

void Editor::loop(){
    string line ;
    while (!quit) {
        getline(cin, line);
        
        if (line == "a") { //done
            Editor::document.append_after();
        }
        else if (line == "i"){ //done
            Editor::document.insert_before();
        }
        else if (line == "p"){// done
            Editor::document.print_current();
        }
        else if (line == "%p"){ //done
            cout << Editor::document;
        }
        else if (line == "n"){ // done
            Editor::document.print_cur_index();
        }
        else if (line == "c"){ // done
            Editor::document.swap_current();
        }
        else if (line == "d"){ // done
            Editor::document.remove_current();
        }
        else if (is_number(line)){ // done
            int new_index = stoi(line);
            Editor::document.set_current(new_index);
        }
        else if (line.substr(0,2) == "s/"){
            Editor::document.swap(line.substr(2));
        }
        else if (line.substr(0,1) == "/"){ // done
            Editor::document.search_after_current(line.substr(1));
        }
        else if (line == "Q"){  // done
            quit = true;
        }
        else
            cout << "?\n" ;
    }
}

/*
 help function to check if a string is a number
 */
bool Editor::is_number(const string& s)
{
    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}


