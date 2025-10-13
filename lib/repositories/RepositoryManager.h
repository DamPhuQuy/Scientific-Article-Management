#pragma once
#include <unordered_map>
#include <string>
#include "models/articles/Article.h"
#include "models/articles/ArticleReference.h"
#include "models/articles/AuthorArticle.h"

using namespace std;

class RepositoryManager {
private:
    unordered_map<string, Article*> articles_container;
    vector<ArticleReference> ar_ref; 
    vector<AuthorArticle> au_ar; 
public:
    RepositoryManager(
        unordered_map<string, Article*> articles_container,
        vector<ArticleReference> ar_ref,
        vector<AuthorArticle> au_ar
    );

    ~RepositoryManager();
};

