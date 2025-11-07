#pragma once
#include "AuthorArticle.h"
#include <vector>

using namespace std;

class AuthorArticleRepo {
private:
    vector<AuthorArticle> relations;
public:
    AuthorArticleRepo() = default;
    AuthorArticleRepo(const vector<AuthorArticle>& r);

    ~AuthorArticleRepo() = default;

    const vector<AuthorArticle>& getRelations() const;

    // utilities
    void add(const string& article_id, const string& author_id);
    vector<string> getArticleIdsByAuthor(const string& author_id) const;
    vector<string> getAuthorIdsByArticle(const string& article_id) const;
};