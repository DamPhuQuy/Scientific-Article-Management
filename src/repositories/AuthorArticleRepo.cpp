#include "AuthorArticleRepo.h"

AuthorArticleRepo::AuthorArticleRepo(const vector<AuthorArticle> &r)
: relations(r)
{
}

const vector<AuthorArticle> &AuthorArticleRepo::getRelations() const
{
    return this->relations;
}

void AuthorArticleRepo::add(const string &article_id, const string &author_id)
{
    relations.emplace_back(article_id, author_id);
}

vector<string> AuthorArticleRepo::getArticleIdsByAuthor(const string &author_id) const
{
    vector<string> result;
    for (const auto& r : relations) {
        if (r.getAuthorId() == author_id) {
            result.push_back(r.getArticleId());
        }
    }
    return result;
}

vector<string> AuthorArticleRepo::getAuthorIdsByArticle(const string &article_id) const
{
    vector<string> result;
    for (const auto& r : relations) {
        if (r.getArticleId() == article_id) {
            result.push_back(r.getAuthorId());
        }
    }
    return result;
}
