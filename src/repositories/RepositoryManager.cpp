#include "RepositoryManager.h"
#include <algorithm> 
#include <iostream> 

using namespace std;

ArticlesRepo::ArticlesRepo(unordered_map<string, Article *> ar_con)
: articles_container(ar_con)
{
}

ArticlesRepo::~ArticlesRepo()
{
    for (auto element : this->articles_container) {
        delete element.second; 
    }
}

void ArticlesRepo::add(const Article &a)
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

void ArticlesRepo::remove(const Article &a)
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

AuthorsRepo::AuthorsRepo(unordered_map<string, Author> au_con)
: authors_container(au_con)
{
}

void AuthorsRepo::add(const Author &au)
{
    string id = au.getId(); 
    auto it = this->authors_container.find(id); 
    if (it != this->authors_container.end()) {
        cout << "Id nay da ton tai!" << endl; 
        return; 
    }
    else {
        this->authors_container[id] = au; 
    }
}

void AuthorsRepo::remove(const Author &au)
{
    string id = au.getId(); 
    auto it = this->authors_container.find(id); 
    if (it != this->authors_container.end()) {
        this->authors_container.erase(id); 
    } 
    else {
        cout << "Id nay khong ton tai!" << endl; 
    }
}

RepositoryManager::RepositoryManager(
    const ArticlesRepo& a_repo,
    const AuthorsRepo& au_repo,
    const vector<ArticleReference>& ar_ref,
    const vector<AuthorArticle>& au_ar
)
    : a_repo(a_repo),
      au_repo(au_repo),
      ar_ref(ar_ref),
      au_ar(au_ar)
{}

// void RepositoryManager::sync()
// {
    
// }
