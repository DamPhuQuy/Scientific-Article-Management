#pragma once
#include <unordered_map>
#include "Article.h" 

using namespace std; 

class ArticleRepo {
private:
    unordered_map<string, Article*> articles_container; 
public: 
    explicit ArticleRepo(unordered_map<string, Article*> ar_con = {});
    ~ArticleRepo();  

    void add(const Article& a); 
    void remove(const Article& a); 
};