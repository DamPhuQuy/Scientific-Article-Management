#pragma once

#include <string>

using namespace std; 

class AuthorArticle {
private: 
    string article_id; 
    string author_id; 
public:
    string get_article_id(const string& author_id) const {
        if (this->author_id == author_id) {
            return article_id; 
        }
    }

    string get_author_id(const string& article_id) const {
        if (this->article_id == article_id) {
            return author_id; 
        }
    }
};