#ifndef EDITOR_H
#define EDITOR_H

#include "Document.h"

class Editor {
  
private:
    
    Document document;
    bool quit;
    
public:
    
    Editor();
    void open();
    
};

#endif

