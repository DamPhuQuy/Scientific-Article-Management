#pragma once
#include <string>
#include "Article.h"
#include "Author.h"

using namespace std; 

class AuthorArticle {
private: 
    string article_id; 
    string author_id; 
public:
    AuthorArticle(string article_id, string author_id) 
    : article_id(article_id), author_id(author_id) {} 

    string getArticleId() const { return article_id; }
    string getAuthorId() const { return author_id; }
};

