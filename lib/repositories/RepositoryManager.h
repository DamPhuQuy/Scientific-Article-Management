#pragma once
#include "ArticleRepo.h"
#include "AuthorRepo.h"
#include "AuthorArticleRepo.h"

class RepositoryManager {
private:
    ArticleRepo& a_repo;
    AuthorRepo& au_repo;
    AuthorArticleRepo& au_ar;
public:
    RepositoryManager(
        ArticleRepo& a_repo,
        AuthorRepo& au_repo,
        AuthorArticleRepo& au_ar
    );

    ~RepositoryManager() = default;

     // Access to each repository through reference
    ArticleRepo& getArticles();
    AuthorRepo& getAuthors();
    AuthorArticleRepo& getAuthorArticles();

    // search
    // void liveSearchReferences

    // High-level logic combining repos 
    void sync();
    void clearAll(); 
};

