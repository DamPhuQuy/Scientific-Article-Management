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

    string getReferenceId() const { return reference_id; }
    string getArticleId() const { return article_id; }
};

    
