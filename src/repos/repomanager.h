#pragma once
#include "articlerepo.h"
#include "authorrepo.h"
#include "authorarticlerepo.h"

class RepositoryManager {
private:
    ArticleRepo& a_repo;
    AuthorRepo& au_repo;
    AuthorArticleRepo& au_ar;

    // Article input
    void inputArticle(Article* article);
    void inputArticleReferences(Article* article);
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

    // create article utility
    void createArticle();

    // High-level logic combining repos
    bool validateDataConsistency() const;
    void clearAll();
};

