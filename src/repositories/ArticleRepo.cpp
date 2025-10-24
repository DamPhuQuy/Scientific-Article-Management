#include "ArticleRepo.h"
#include <iostream> 

ArticleRepo::ArticleRepo(unordered_map<string, Article *> ar_con)
: articles_container(ar_con)
{
}

ArticleRepo::~ArticleRepo()
{
    for (auto &element : this->articles_container) {
        delete element.second; 
    }
}

void ArticleRepo::add(Article* a)
{
    string id = a->getArticleID(); 
    auto it = this->articles_container.find(id);
    if (it != this->articles_container.end()) {
        cout << "Id nay da ton tai!" << endl;
        delete a; 
        return;
    }
    else {
        this->articles_container[id] = a; 
    }
}

void ArticleRepo::remove(const Article &a)
{
    string id = a.getArticleID(); 
    auto it = this->articles_container.find(id); 
    if (it != this->articles_container.end()) {
        delete it->second;       
        this->articles_container.erase(it);  
    } 
    else {
        cout << "Id nay khong ton tai!" << endl; 
    }
}


void ArticleRepo::traverse()
{
    for (auto element : articles_container) {
        element.second->showDescription(); 
    }
}

vector<Article*> ArticleRepo::getAll() const {
    vector<Article*> res; 
    for (auto element : this->articles_container) {
        res.push_back(element.second); 
    }
    return res; 
}
