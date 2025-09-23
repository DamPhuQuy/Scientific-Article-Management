#pragma once

#include "models/Article.h"
#include "repositories/EventListener.h"
#include <map>
#include <vector>
#include <memory>

using namespace std;

class ArticleRepository {
private:
    map<string, Article*> articlesMap;
    EventListener eventListener;
    static unsigned long count;
public:
    ArticleRepository() = default;
    explicit ArticleRepository(const map<string, Article*> &aMap);
    ~ArticleRepository();

    void addArticle(const Article& article);
    [[nodiscard]] Article* getArticleById(const string& id) const;
    [[nodiscard]] vector<Article*> getAllArticles() const;

    void updateArticle(const Article& article);
    void deleteArticle(const string& id);

    [[nodiscard]] vector<const Article*> findByTitle(const string &keyword) const;

    [[nodiscard]] vector<const Article*> findByAuthorId(const string& authorID) const;

    [[nodiscard]] vector<const Article*> findByJournalId(const string& journalID) const;
};