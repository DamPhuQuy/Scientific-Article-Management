#pragma once
#include "articlerepo.h"
#include "authorrepo.h"

class RepositoryManager {
private:
    ArticleRepo& a_repo;
    AuthorRepo& au_repo;

    // Article input
    void inputArticle(Article* article);
    void inputArticleReferences(Article* article);
public:
    RepositoryManager(
        ArticleRepo& a_repo,
        AuthorRepo& au_repo
    );

    ~RepositoryManager() = default;

    // Access to each repository through reference
    ArticleRepo& getArticles();
    AuthorRepo& getAuthors();

    void load();
    void save();

    // search
    // void liveSearchReferences

    // create article utility
    void createArticle();

    // High-level logic combining repos
    // bool validateDataConsistency() const;
    void clearAll();
};

