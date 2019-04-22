

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
    cout<<Document::text[Document::current_line]<<"\n";
    else
        cout << "?\n" ;
}

/*
prints line number of current line followed by TAB
 followed by current line
 */
void Document::print_cur_index(){
    cout<<Document::current_line+1<<"       "
    <<Document::text[Document::current_line]<<"\n";
}

/*
 set a line to be the current line.
 E.g : set_current(7) makes line #7 the current line
 */
void Document::set_current(int new_current){
    if(new_current>=0 && new_current<=text.size())
    Document::current_line = new_current-1;
    else
        cout << "?\n" ;
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
        cout << "?\n";
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
        cout << "?\n";
}

/*
 searches forward after current line for the specified text.The search wraps to the beginning of the buffer and continues down to the current line, if necessary
 */
void Document::search_after_current(string txt){
    string strFound = "";
    size_t found = string::npos;
    auto it = Document::text.begin();
    for (; it<Document::text.end() && found== string::npos; it++) {
        strFound = *it ;
        found = strFound.find(txt);
    }
    if (it != text.end() || found != string::npos) {
        cout << strFound << "\n" ;
        current_line = (int)distance(text.begin(), --it);
    }
    else
        cout << "?\n" ;
}

/*
 replaces old string with new in current line
 */
void Document::swap(const string& input){
    string oldStr = "",newStr = "";
    string &line = Document::text[current_line];
    size_t found = string::npos;
    string::const_iterator itLine = input.begin();
    //get oldstring
    while (itLine != input.end() && *itLine != '/'){
        oldStr+= *itLine ;
        ++itLine ;
    }
    size_t start = distance(input.begin(),itLine)+1 ;
    size_t end = (input.length()-1)-start;
    newStr = input.substr(start,end);
    
    found = line.find(oldStr);
    if(found != string::npos){
        line.replace(line.find(oldStr),oldStr.length(),newStr);
    }
    else
        cout << "?\n" ;
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
