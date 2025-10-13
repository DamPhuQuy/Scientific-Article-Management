#pragma once

#include <string> 

using namespace std; 

class ArticleReference {
private: 
    string article_id; 
    string reference_id;
public: 
    string get_reference_id(const string& article_id) {
        if (this->article_id == article_id) {
            return reference_id; 
        }
    }
};