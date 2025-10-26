#pragma once
#include <unordered_map>
#include "Article.h" 

using namespace std; 

class ArticleRepo {
private:
    unordered_map<string, Article*> articles_container; 
public: 
    ArticleRepo() = default; 
    explicit ArticleRepo(unordered_map<string, Article*> ar_con);

    ~ArticleRepo();  

    // utilities
    void add(Article* a); 
    void remove(const Article& a); 
    void traverse();
    vector<Article*> getAll() const; 

    // search
    string liveSearchByTitle() const; 
    string liveSearchByYear() const; 
    string liveSearchByType() const; 
    void searchMenu() const; 
};