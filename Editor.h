#ifndef EDITOR_H
#define EDITOR_H

#include "Document.h"

class Editor {
  
private:
    
    Document document;
    bool quit;
    bool is_number(const string& s);

    
public:
    
    Editor();
    void open();
    
};

#endif

