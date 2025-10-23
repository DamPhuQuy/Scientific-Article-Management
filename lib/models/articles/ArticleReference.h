#pragma once

#include <string> 


using namespace std; 

class ArticleReference {
private: 
    string article_id; 
    string reference_id;
public: 
    ArticleReference() = default; 
    ArticleReference(const string& article_id, const string& reference_id)
    : article_id(article_id), reference_id(reference_id) {} 

    ~ArticleReference() = default; 

    // getters
    string getReferenceId() const { return reference_id; }
    string getArticleId() const { return article_id; }

    // setters
    void setReferenceId(const string& ref_id) {
        reference_id = ref_id; 
    }

    void setArticleId(const string& a_id) {
        article_id = a_id; 
    }
};

    
