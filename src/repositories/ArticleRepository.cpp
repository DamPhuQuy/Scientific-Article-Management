#include "repositories/ArticleRepository.h"

#include <iostream>
#include <algorithm>
#include <regex>

ArticleRepository::ArticleRepository(const map<string, Article *> &aMap): articlesMap(aMap) {
    ArticleRepository::count = aMap.size();
}

ArticleRepository::~ArticleRepository() {
    ranges::for_each(articlesMap, [](auto& pair) -> void {
        delete pair.second;
    });
}

void ArticleRepository::addArticle(const Article& article) {
    const auto id = article.getArticleID();
    if (const auto it = articlesMap.find(id); it != articlesMap.end()) {
        cout << "Id nay da ton tai!" << endl;
        return;
    }
    articlesMap[id] = article.clone();
}

Article * ArticleRepository::getArticleById(const string &id) const {
    if (const auto it = articlesMap.find(id); it == articlesMap.end()) {
        cout << "Article does not exist" << endl;
        return nullptr;
    }
    else {
        return it->second;
    }
}

vector<Article*> ArticleRepository::getAllArticles() const {
    vector<Article*> articles;

    ranges::for_each(articlesMap, [&](const auto &element) -> void {
         articles.push_back(element.second);
    });

    return articles;
}

void ArticleRepository::updateArticle(const Article &article) {
    const auto id = article.getArticleID();
    if (const auto it = articlesMap.find(id); it != articlesMap.end()) {
        delete it->second;
    }
    articlesMap[id] = article.clone();
}

void ArticleRepository::deleteArticle(const string& id) {
    if (const auto it = articlesMap.find(id); it != articlesMap.end()) {
        articlesMap.erase(it);
    }
}

vector<const Article *> ArticleRepository::findByTitle(const string &keyword) const {
    vector<const Article*> articles;

    regex pattern(keyword);
    ranges::for_each(articlesMap, [&](const auto &pair) -> void {
        if (regex_search(pair.second->getArticleID(), pattern)) {
            articles.push_back(pair.second);
        }
    });

    return articles;
}

vector<const Article *> ArticleRepository::findByAuthorId(const string &authorID) const {
    vector<const Article*> articles;

    regex pattern(authorID);
    ranges::for_each(articlesMap, [&](const auto& pair) -> void {
        if (regex_search(pair.second->getAuthorID(), pattern)) {
            articles.push_back(pair.second);
        }
    });

    return articles;
}

vector<const Article *> ArticleRepository::findByJournalId(const string &journalID) const {
    vector<const Article*> articles;

    regex pattern(journalID);
    ranges::for_each(articlesMap, [&](const auto &pair) -> void {
        if (regex_search(pair.second->getJournalID(), pattern)) {
            articles.push_back(pair.second);
        }
    });

    return articles;
}


