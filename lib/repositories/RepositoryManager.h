#pragma once
#include <unordered_map>
#include <string>
#include "models/articles/Article.h"
#include "models/articles/ArticleReference.h"
#include "models/articles/AuthorArticle.h"
#include "services/DataManipulation.h"
#include "models/articles/Author.h"

using namespace std;

class ArticlesRepo {
private:
    unordered_map<string, Article*> articles_container; 
public: 
    
    explicit ArticlesRepo(unordered_map<string, Article*> ar_con);
    ~ArticlesRepo();  

    void add(const Article& a); 
    void remove(const Article& a); 
};

class AuthorsRepo {
private: 
    unordered_map<string, Author> authors_container; 
public: 
    explicit AuthorsRepo(unordered_map<string, Author> au_con); 
    ~AuthorsRepo(); 

    void add(const Author& au);
    void remove(const Author& au);
};

class RepositoryManager {
private:
    ArticlesRepo a_repo; 
    vector<ArticleReference> ar_ref; 
    vector<AuthorArticle> au_ar; 
public:
    RepositoryManager(
        ArticlesRepo a_repo,
        vector<ArticleReference> ar_ref,
        vector<AuthorArticle> au_ar
    );

    ~RepositoryManager();
};

