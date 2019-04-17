

#include "Document.h"

using namespace std;

//constructor
Document::Document(){
    Document::current_line=0;
    
}

/*
 print the current line of the document
 */
void Document::print_current(){
    
}

/*
prints line number of current line followed by TAB
 followed by current line
 */
void Document::print_cur_index(){
    
}

/*
 set a line to be the current line.
 E.g : set_current(7) makes line #7 the current line
 */
void Document::set_current(int new_current){
    
}

/*
 appends new text after the current line
 */
void Document::append_after(){
    
}
/*
 inserts new text before the current line
 */
void Document::insert_before(){
    
}

/*
 changes the current line for text that follows
 */
void Document::swap_current(){
    
}

/*
 deletes the current line
 */
void Document::remove_current(){
    
}

/*
 searchesforwardaftercurrentlineforthespecifiedtext.Thesearchwrapstothe beginning of the buffer and continues down to the current line, if necessary
 */
string Document::search_after_current(string text){
    string result;
    return result;
}

/*
 replaces old string with new in current line
 */
void Document::swap(string line){
    
}

/*
 operator: prints all lines
 */
ostream& operator<<(ostream& os, const Document& doc){
    
    return os;
}
