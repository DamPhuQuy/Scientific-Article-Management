#include "ArticleService.h"

Article* ArticleService::createArticle(Type type, const ArticleData& data) {
    Article* article = DataManipulation::createArticle(type);
    article->setTitle(data.title);
    article->setAbstract(data.abstractText);
    article->setVenue(data.venue);
    article->setYear(data.year);
    article->setNCitation(data.nCitations);
    article->setStatus(data.status);
    repo.getArticles().add(article);
    return article;
}

void ArticleService::addReferences(Article* article, const std::vector<std::string>& references) {
    article->getReferences().clear();
    for (const auto& ref : references)
        article->getReferences().push_back(ref);
}

void ArticleService::addAuthors(Article* article, const std::vector<std::string>& authorIds) {
    for (const auto& id : authorIds)
        repo.getAuthorArticles().add(article->getId(), id);
}
