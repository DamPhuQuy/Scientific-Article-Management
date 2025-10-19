#include "ArticleReferenceRepo.h"

ArticleReferenceRepo::ArticleReferenceRepo(const vector<ArticleReference> &ref)
: references(ref)
{
}

void ArticleReferenceRepo::addReference(const std::string &article_id, const std::string &reference_id)
{
    references.emplace_back(article_id, reference_id);
}

vector<string> ArticleReferenceRepo::getReferencesOf(const std::string &article_id) const
{
    vector<string> result;
    for (const auto& ref : references) {
        if (ref.getArticleId() == article_id)
            result.push_back(ref.getReferenceId());
    }
    return result;
}

vector<string> ArticleReferenceRepo::getCitedBy(const string &reference_id) const
{
    vector<string> result;
    for (const auto& ref : references) {
        if (ref.getReferenceId() == reference_id)
            result.push_back(ref.getArticleId());
    }
    return result;
}
