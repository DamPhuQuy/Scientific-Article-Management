#pragma once
#include "articlerepo.h"
#include "authorrepo.h"
#include "src/utils/usermanager.h"

class RepositoryManager {
private:
    ArticleRepo& a_repo;
    AuthorRepo& au_repo;
    UserManager& u_manager;

    // Article input
    void inputArticle(Article* article);
    void inputArticleReferences(Article* article);
public:
    RepositoryManager(
        ArticleRepo& a_repo,
        AuthorRepo& au_repo,
        UserManager& u_manager
    );

    ~RepositoryManager() = default;

    // Access to each repository through reference
    ArticleRepo& getArticles();
    AuthorRepo& getAuthors();
    UserManager& getUsers();

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

