#pragma once
#include "ArticleRepo.h"
#include "AuthorRepo.h"
#include "AuthorArticleRepo.h"
#include "ArticleReferenceRepo.h"

class RepositoryManager {
private:
    ArticleRepo& a_repo;
    AuthorRepo& au_repo;
    AuthorArticleRepo& au_ar;
    ArticleReferenceRepo& ar_ref;
public:
    RepositoryManager(
        ArticleRepo& a_repo,
        AuthorRepo& au_repo,
        AuthorArticleRepo& au_ar,
        ArticleReferenceRepo& ar_ref
    );

    ~RepositoryManager() = default;

     // Access to each repository through reference
    ArticleRepo& getArticles();
    AuthorRepo& getAuthors();
    AuthorArticleRepo& getAuthorArticles();
    ArticleReferenceRepo& getArticleReferences();

    // High-level logic combining repos 
    void sync();
    void clearAll(); 
};

