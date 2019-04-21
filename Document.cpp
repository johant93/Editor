

#include "Document.h"

using namespace std;

//constructor
Document::Document(){
    Document::current_line=-1;
    
}

/*
 print the current line of the document
 */
void Document::print_current(){
    if (Document::current_line > -1)
    cout<<Document::text[Document::current_line];
    else
        cout << "?" ;
}

/*
prints line number of current line followed by TAB
 followed by current line
 */
void Document::print_cur_index(){
    cout<<Document::current_line+1<<"       "
    <<Document::text[Document::current_line];
}

/*
 set a line to be the current line.
 E.g : set_current(7) makes line #7 the current line
 */
void Document::set_current(int new_current){
    if(new_current>=0 && new_current<=text.size())
    Document::current_line = new_current-1;
    else
        cout << "?" ;
}

/*
 appends new text after the current line
 */
void Document::append_after(){
    string line = "";
    getline(cin,line);
    while(line != "."){
        auto it = text.begin()+ ++current_line ;
        Document::text.insert(it,line);
        getline(cin,line);
    }
}
/*
 inserts new text before the current line
 */
void Document::insert_before(){
    string line = "";
    getline(cin,line);
    while(line != "."){
        auto it = text.begin()+ current_line++ ;
        Document::text.insert(it,line);
        getline(cin,line);
    }
}

/*
 changes the current line for text that follows
 */
void Document::swap_current(){
    if (!text.empty()) {
    string line = "";
    getline(cin,line);
    auto it = text.begin()+ current_line-- ;
    Document::text.erase(it);
    while(line != "."){
        Document::text.insert(it,line);
        it++;
        current_line++;
        getline(cin,line);
    }
    }
    else {
        cout << "?";
    }
}

/*
 deletes the current line
 */
void Document::remove_current(){
    if (!text.empty()) {
        auto it = text.begin()+ current_line-- ;
        Document::text.erase(it);
    }
    else
        cout << "?";
}

/*
 searchesforwardaftercurrentlineforthespecifiedtext.Thesearchwrapstothe bd
beginning of the buffer and continues down to the current line, if necessary
 */
void Document::search_after_current(string txt){
    auto it = find(text.begin(),text.end(),txt);
    if (it != text.end()) {
        cout << *it ;
        current_line = (int)distance(text.begin(), it);
    }
    else
        cout << "?" ;
}

/*
 replaces old string with new in current line
 */
void Document::swap(const string& line){
    string oldStr = "",newStr = "";
    string::const_iterator itLine = line.begin();
    while (itLine != line.end() && *itLine != '/'){
        oldStr+= *itLine ;
        ++itLine ;
    }
    size_t start = distance(line.begin(),itLine)+1 ;
    size_t end = (line.length()-1)-start;
    newStr = line.substr(start,end);
    
    auto it = find(text.begin(),text.end(),oldStr);
    if (it != text.end()) {
        current_line = (int)distance(text.begin(), it);
    }
    else
        cout << "?" ;
    it = text.begin()+ current_line ;
    Document::text.erase(it);
    Document::text.insert(it,newStr);
}

/*
 operator: prints all lines
 */
ostream& operator<<(ostream& os, const Document& doc){
    auto it = doc.text.begin();
    while(it<doc.text.end()){
        os << *it << "\n";
        it++;
    }
    return os;
}
