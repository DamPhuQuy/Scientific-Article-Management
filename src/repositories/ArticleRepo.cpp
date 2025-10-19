#include "ArticleRepo.h"
#include <iostream> 

ArticleRepo::ArticleRepo(unordered_map<string, Article *> ar_con)
: articles_container(ar_con)
{
}

ArticleRepo::~ArticleRepo()
{
    for (auto element : this->articles_container) {
        delete element.second; 
    }
}

void ArticleRepo::add(const Article &a)
{
    string id = a.getArticleID(); 
    auto it = this->articles_container.find(id);
    if (it != this->articles_container.end()) {
        cout << "Id nay da ton tai!" << endl;
        return;
    }
    else {
        this->articles_container[id] = a.clone(); 
    }
}

void ArticleRepo::remove(const Article &a)
{
    string id = a.getArticleID(); 
    auto it = this->articles_container.find(id); 
    if (it != this->articles_container.end()) {
        this->articles_container.erase(id); 
    } 
    else {
        cout << "Id nay khong ton tai!" << endl; 
    }
}