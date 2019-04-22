//###################################################
//##########Yehonatan Shaag 308357953################
//##########Johann Thuillier 336104120 ################
//###################################################

#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;
class Document {
    
    private:
        std::vector<string> text ;
        int current_line;
    
    public:
        Document();
    
        void print_current();
        void print_cur_index();
        friend ostream& operator<<(ostream& os, const Document& doc);
        void set_current(int new_current);
        void append_after();
        void insert_before();
        void swap_current();
        void remove_current();
        void search_after_current(string text);
        void swap(const string& line);
    
};
#endif
