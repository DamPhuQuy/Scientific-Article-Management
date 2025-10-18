#pragma once
#include <unordered_map>
#include <string>
#include "Article.h"
#include "ArticleReference.h"
#include "AuthorArticle.h"
#include "DataManipulation.h"
#include "Author.h"

using namespace std;

class ArticlesRepo {
private:
    unordered_map<string, Article*> articles_container; 
public: 
    explicit ArticlesRepo(unordered_map<string, Article*> ar_con = {});
    ~ArticlesRepo();  

    void add(const Article& a); 
    void remove(const Article& a); 
};

class AuthorsRepo {
private: 
    unordered_map<string, Author> authors_container; 
public: 
    explicit AuthorsRepo(unordered_map<string, Author> au_con = {}); 
    ~AuthorsRepo() = default; 

    void add(const Author& au);
    void remove(const Author& au);
};

class RepositoryManager {
private:
    ArticlesRepo a_repo; 
    AuthorsRepo au_repo; 
    vector<ArticleReference> ar_ref; 
    vector<AuthorArticle> au_ar; 
public:
    RepositoryManager(
        const ArticlesRepo& a_repo = ArticlesRepo(),
        const AuthorsRepo& au_repo = AuthorsRepo(),
        const vector<ArticleReference>& ar_ref = {},
        const vector<AuthorArticle>& au_ar = {}
    );

    ~RepositoryManager() = default;

    void sync(); 
};

