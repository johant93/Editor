#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <vector>
#include <string>
#include <iostream>

class Document {
    
    private:
        std::vector<string> text ;
        int current_line;
    
    public:
        Document();
    
        out print_current();
        out print_cur_index;
        out print_all();
        void set_current(int new_current);
        void append_after(string newLine);
        void insert_before(string newLine);
        void swap_current(string newLine)
        void remove_current();
        string search_after_current(string text);
        void swap(string old_word,string new_word);
    
}
