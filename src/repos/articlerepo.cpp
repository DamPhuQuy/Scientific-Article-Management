#include "articlerepo.h"

ArticleRepo::ArticleRepo(unordered_map<string, unique_ptr<Article>> ar_con)
    : articles_container(ar_con) {}

void ArticleRepo::add(unique_ptr<Article> a) {
    if (!a || a->getId().empty()) return;
    articles_container[a->getId()] = std::move(a);
}

void ArticleRepo::remove(const string& articleId) {
    articles_container.erase(articleId);
}

unordered_map<string, unique_ptr<Article>>& ArticleRepo::getContainer() {
    return articles_container;
}

const unordered_map<string, unique_ptr<Article>>& ArticleRepo::getContainer() const {
    return articles_container;
}

void ArticleRepo::extracted(vector<unique_ptr<Article>> &res) const {
    res.clear();
    res.reserve(articles_container.size());
    for (const auto& pair : articles_container) {
        // make copy
        res.push_back(make_unique<Article>(pair.second));
    }
}

unique_ptr<Article> ArticleRepo::findById(const string& id) const {
    auto it = articles_container.find(id);
    if (it != articles_container.end()) {
        return make_unique<Article>(*it->second);
    }
    return nullptr;
}
