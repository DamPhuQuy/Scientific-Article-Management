#pragma once
#include <iostream>
#include <string>
#include "Article.h"
#include "Author.h"

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

    AuthorArticle(const string& article_id, const string& author_id) 
        : article_id(article_id), author_id(author_id) {}
    
    vector AuthorArticle::AuthorArticle> links = { 
        AuthorArticle("A001", "AU001"),
        AuthorArticle("A001", "AU002"),
        AuthorArticle("A002", "AU002")
    }


