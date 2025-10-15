#pragma once

#include <string> 

using namespace std; 

class ArticleReference {
private: 
    string article_id; 
    string reference_id;
public: 
    ArticleReference(string article_id, string reference_id)
    : article_id(article_id), reference_id(reference_id) {} 

    string get_reference_id(const string& article_id) {
        if (this->article_id == article_id) {
            return reference_id; 
        }
    }

    string get_article_id(const string& reference_id) {
        if (this->reference_id == reference_id) {
            return article_id; 
        }
    }
};

    
