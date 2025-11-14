#include "articlerepo.h"
#include "../models/scie_article.h"
#include "../models/scopus_article.h"
#include "../utils/datautils.h"
#include <regex>
#include "../utils/nlohmann/json.hpp"
#include <QDebug>
#include <filesystem>
#include <fstream>
#include <algorithm>
#include <exception>

using namespace std;
namespace fs = std::filesystem;

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

vector<unique_ptr<Article>> ArticleRepo::getCopyAsVector() const {
    vector<unique_ptr<Article>> res;
    res.reserve(articles_container.size());
    for (const auto& pair : articles_container) {
        // make copy
        res.push_back(pair.second->clone());
    }
    return res;
}

// need more fix
void ArticleRepo::load() {
    const fs::path file_path = "dataset.json";
    ifstream in(file_path);

    if (!in.is_open()) {
        return;
    }

    try {
        json data;
        in >> data;

        articles_container.clear();

        for (const auto& item : data) {
            string abstract    = item.value("abstract", "");
            int n_citation          = item.value("n_citation", 0);
            string title       = item.value("title", "");
            string venue       = item.value("venue", "");
            int year                = item.value("year", 0);
            string id          = item.value("id", "");
            Type type               = static_cast<Type>(item.value("type", 4));
            ArticleStatus status    = ArticleStatus::DRAFT;

            // Xử lý references
            std::vector<string> refs;
            if (item.contains("references") && item["references"].is_array()) {
                for (const auto& ref : item["references"]) {
                    refs.push_back(ref.get<string>());
                }
            }

            // Tạo Article đúng loại
            unique_ptr<Article> article(
                DataUtils::createArticle(
                    abstract, n_citation, title, venue, year, id, type, status, refs
                    )
                );

            if (article && !id.empty()) {
                articles_container[id] = std::move(article);
            }
        }
    }
    catch (const json::exception& e) {
        qCritical() << "JSON parse error: " << e.what() << "\n";
    }
    catch (const exception& e) {
        qCritical() << "Error loading articles: " << e.what() << "\n";
    }
}

unique_ptr<Article> ArticleRepo::findById(const string& id) const {
    auto it = articles_container.find(id);
    if (it != articles_container.end()) {
        return it->second->clone();
    }
    return nullptr;
}

vector<unique_ptr<Article>> ArticleRepo::findByTitle(const string& titlePattern) const {
    vector<unique_ptr<Article>> res;

    try {
        const regex pattern(titlePattern, regex::icase);

        for (const auto& pair : articles_container) {
            const string& title = pair.second->getTitle();

            if (regex_search(title, pattern)) {
                res.push_back(pair.second->clone());
            }
        }
    }
    catch (const regex_error& e) {
        qCritical() << "Invalid regex pattern:" << e.what();
    }

    return res;
}

vector<unique_ptr<Article>> ArticleRepo::filterByYear(Type t) const {
    vector<unique_ptr<Article>> res;
    for (const auto& pair : articles_container) {
        if (pair.second->getType() == t) {
            res.push_back(pair.second->clone());
        }
    }
    return res;
}

vector<unique_ptr<Article>> ArticleRepo::filterByYear(int year) const {
    vector<unique_ptr<Article>> res;
    for (const auto& pair : articles_container) {
        if (pair.second->getYear() == year) {
            res.push_back(pair.second->clone());
        }
    }
    return res;
}

vector<unique_ptr<Article>> ArticleRepo::filterByCitation(int minCitations) const {
    vector<unique_ptr<Article>> res;
    for (const auto& pair : articles_container) {
        if (pair.second->getCitation() >= minCitations) {
            res.push_back(pair.second->clone());
        }
    }
    return res;
}

vector<unique_ptr<Article>> ArticleRepo::sortedByCitations(bool ascending) const {
    auto vec = getCopyAsVector();
    sort(vec.begin(), vec.end(), [ascending](const unique_ptr<Article>& a, const unique_ptr<Article>& b) {
        return ascending ? a->getCitation() < b->getCitation() : a->getCitation() > b->getCitation();
    });
    return vec;
}

vector<unique_ptr<Article>> ArticleRepo::sortedByYear(bool ascending) const {
    auto vec = getCopyAsVector();
    sort(vec.begin(), vec.end(), [ascending](const unique_ptr<Article>& a, const unique_ptr<Article>& b) {
        return ascending ? a->getYear() < b->getYear() : a->getYear() > b->getYear();
    });
    return vec;
}

vector<unique_ptr<Article>> ArticleRepo::sortedByImpactFactor(bool ascending) const {
    vector<unique_ptr<Article>> vec = getCopyAsVector();

    vector<unique_ptr<Article>> filtered;
    filtered.reserve(vec.size());

    for (auto& ptr : vec) {
        if (auto* journal = dynamic_cast<SCIE_Article*>(ptr.get())) {
            filtered.push_back(ptr);
        }
    }

    sort(filtered.begin(), filtered.end(),
              [ascending](const unique_ptr<Article>& a, const unique_ptr<Article>& b) {
                  auto* ja = static_cast<SCIE_Article*>(a.get());
                  auto* jb = static_cast<SCIE_Article*>(b.get());
                  return ascending ? ja->getImpactFactor() < jb->getImpactFactor()
                                   : ja->getImpactFactor() > jb->getImpactFactor();
              });

    return filtered;
}

vector<unique_ptr<Article>> ArticleRepo::sortedBySJR(bool ascending) const {
    vector<unique_ptr<Article>> vec = getCopyAsVector();

    vector<unique_ptr<Article>> filtered;
    filtered.reserve(vec.size());

    for (auto& ptr : vec) {
        if (auto* journal = dynamic_cast<SCOPUS_Article*>(ptr.get())) {
            filtered.push_back(ptr);
        }
    }

    sort(filtered.begin(), filtered.end(),
         [ascending](const unique_ptr<Article>& a, const unique_ptr<Article>& b) {
             auto* ja = static_cast<SCOPUS_Article*>(a.get());
             auto* jb = static_cast<SCOPUS_Article*>(b.get());
             return ascending ? ja->getSJR() < jb->getSJR()
                              : ja->getSJR() > jb->getSJR();
         });

    return filtered;
}

vector<unique_ptr<Article>> ArticleRepo::sortedByHIndex(bool ascending) const {
    vector<unique_ptr<Article>> vec = getCopyAsVector();

    vector<unique_ptr<Article>> filtered;
    filtered.reserve(vec.size());

    for (auto& ptr : vec) {
        if (auto* journal = dynamic_cast<SCOPUS_Article*>(ptr.get())) {
            filtered.push_back(ptr);
        }
    }

    sort(filtered.begin(), filtered.end(),
         [ascending](const unique_ptr<Article>& a, const unique_ptr<Article>& b) {
             auto* ja = static_cast<SCOPUS_Article*>(a.get());
             auto* jb = static_cast<SCOPUS_Article*>(b.get());
             return ascending ? ja->getHIndex() < jb->getHIndex()
                              : ja->getHIndex() > jb->getHIndex();
         });

    return filtered;
}

vector<unique_ptr<Article>> ArticleRepo::updateTitle(const string& id, const string& title) {
    vector<unique_ptr<Article>> affected;
    auto it = articles_container.find(id);
    if (it != articles_container.end()) {
        it->second->setTitle(title);
        affected.push_back(it->second->clone());
    }
    return affected;
}


vector<unique_ptr<Article>> ArticleRepo::updateVenue(const string& id, const string& venue) {
    vector<unique_ptr<Article>> affected;
    auto it = articles_container.find(id);
    if (it != articles_container.end()) {
        it->second->setVenue(venue);
        affected.push_back(it->second->clone());
    }
    return affected;
}


vector<unique_ptr<Article>> ArticleRepo::updateYear(const string& id, const int& year) {
    vector<unique_ptr<Article>> affected;
    auto it = articles_container.find(id);
    if (it != articles_container.end()) {
        it->second->setYear(year);
        affected.push_back(it->second->clone());
    }
    return affected;
}


int ArticleRepo::count() const {
    return static_cast<int>(articles_container.size());
}


int ArticleRepo::countByType(Type t) const {
    int cnt = 0;
    for (const auto& pair : articles_container) {
        if (pair.second->getType() == t) ++cnt;
    }
    return cnt;
}

double ArticleRepo::averageCitations() const {
    if (articles_container.empty()) return 0.0;
    long long sum = 0;
    for (const auto& pair : articles_container) {
        sum += pair.second->getCitation();
    }
    return static_cast<double>(sum) / articles_container.size();
}
