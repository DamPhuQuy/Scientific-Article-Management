#pragma once
#include <unordered_map>
#include <string>
#include "ArticleRepo.h" 
#include "AuthorRepo.h" 
#include "AuthorArticleRepo.h" 
#include "ArticleReferenceRepo.h" 
#include "DataManipulation.h"

using namespace std;

class RepositoryManager {
private:
    ArticleRepo a_repo; 
    AuthorRepo au_repo; 
    AuthorArticleRepo au_ar; 
    ArticleReferenceRepo ar_ref; 
public:
    RepositoryManager(
        const ArticleRepo& a_repo = ArticleRepo(),
        const AuthorRepo& au_repo = AuthorRepo(),
        const AuthorArticleRepo& au_ar = AuthorArticleRepo(),
        const ArticleReferenceRepo& ar_ref = ArticleReferenceRepo()
    );

    ~RepositoryManager() = default;

     // --- Access to each repository ---
    ArticleRepo& getArticles();
    AuthorRepo& getAuthors();
    AuthorArticleRepo& getAuthorArticles();
    ArticleReferenceRepo& getArticleReferences();

    // --- High-level logic combining repos ---
    void sync();
    void clearAll(); 
};

