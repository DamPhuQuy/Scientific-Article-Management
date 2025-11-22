#include "articlerepo.h"
#include "../models/scie_article.h"
#include "../models/scopus_article.h"
#include "../utils/datautils.h"
#include "../utils/constants.h"
#include <regex>
#include "../utils/nlohmann/json.hpp"
#include "qdir.h"
#include <QDebug>
#include <fstream>
#include <algorithm>
#include <exception>

using namespace std;
namespace fs = std::filesystem;

ArticleRepo::ArticleRepo(HashMap<string, shared_ptr<Article>>&& ar_con)
    : articles_container(std::move(ar_con)) {}

void ArticleRepo::add(shared_ptr<Article> a) {
    if (!a || a->getId().empty()) return;
    articles_container[a->getId()] = std::move(a);
}

void ArticleRepo::remove(const string& articleId) {
    articles_container.remove(articleId);
}

HashMap<string, shared_ptr<Article>>& ArticleRepo::getContainer() {
    return articles_container;
}

const HashMap<string, shared_ptr<Article>>& ArticleRepo::getContainer() const {
    return articles_container;
}

vector<shared_ptr<Article>> ArticleRepo::getCopyAsVector() const {
    vector<shared_ptr<Article>> res;
    res.reserve(articles_container.size());

    articles_container.forEach([&res](const shared_ptr<Article>& article) {
        res.push_back(article);
    });

    return res;
}

void ArticleRepo::load() {
    string file_path = Constants::dataSetJson();
    QDir().mkpath("../../../data");
    ifstream in(file_path);

    if (!in.is_open()) {
        qCritical() << "Cannot open file for loading:" << QString::fromStdString(file_path);
        return;
    }

    try {
        json data;
        in >> data;

        articles_container.clear();

        for (const auto& item : data) {
            // Base
            string abstract      = item.value("abstract", "");
            int    n_citation    = item.value("n_citation", 0);
            string title         = item.value("title", "");
            string venue         = item.value("venue", "");
            int    year          = item.value("year", 0);
            string id            = item.value("id", "");

            Type type            = static_cast<Type>(item.value("type", 4));
            ArticleStatus status = ArticleStatus::PUBLISHED;

            // Lấy references
            vector<string> refs;
            if (item.contains("references") && item["references"].is_array()) {
                refs.reserve(item["references"].size());
                for (const auto& ref : item["references"]) {
                    refs.push_back(ref.get<string>());
                }
            }

            // Take authors
            vector<string> authors;
            if (item.contains("authors") && item["authors"].is_array()) {
                authors.clear();
                authors.reserve(item["authors"].size());
                for (const auto& au : item["authors"]) {
                    authors.push_back(au.get<string>());
                }
            }

            // ---- Tạo Article đúng loại ----
            unique_ptr<Article> article = DataUtils::createArticle(
                abstract,
                n_citation,
                title,
                venue,
                year,
                id,
                type,
                status,
                refs,
                authors,
                item.value("conference_rank", ""),
                item.value("location", ""),
                item.value("acceptance_rate", 0.0),
                item.value("impact_factor", 0.0),
                item.value("q_rank", 0),
                item.value("sjr", 0.0),
                item.value("hIndex", 0)
            );


            // Lưu vào map
            if (article && !id.empty()) {
                articles_container[id] = std::move(article);
            }
        }

        qInfo() << "Load" << QString::number(articles_container.size()) << "articles from " << file_path;
        in.close();
    }
    catch (const json::exception& e) {
        qCritical() << "JSON parse error: " << e.what() << "\n";
    }
    catch (const exception& e) {
        qCritical() << "Error loading articles: " << e.what() << "\n";
    }
}

void ArticleRepo::save() {
    try {
        json data = json::array();

        articles_container.forEach([&data](const shared_ptr<Article>& article) -> void {
            if (article) {
                data.push_back(article->to_json());
            }
        });

        QDir().mkpath("../../../data");
        string file_path = Constants::dataSetJson();
        ofstream out(file_path);

        if (!out.is_open()) {
            qCritical() << "Cannot open file for saving:" << QString::fromStdString(file_path);
            return;
        }

        out << setw(2) << data << endl;
        out.close();
    }
    catch (const json::exception& e) {
        qCritical() << "JSON serialization error:" << e.what();
    }
    catch (const exception& e) {
        qCritical() << "Error saving authors:" << e.what();
    }
    catch (...) {
        qCritical() << "Unknown error occurred while saving authors.";
    }
}

// Hàm overload: Nhận vào 1 article -> Cập nhật vào list -> Ghi ra file
void ArticleRepo::save(const shared_ptr<Article>& article) {
    if (!article) {
        qWarning() << "Attempted to save a null article pointer.";
        return;
    }

    try {
        articles_container.put(article->getId(), article);

        this->save();

        qDebug() << "Successfully saved article: " << QString::fromStdString(article->getTitle());

    } catch (const std::exception& e) {
        qCritical() << "Error in save(article) overload:" << e.what();
    } catch (...) {
        qCritical() << "Unknown error occurred while saving a single article.";
    }
}

shared_ptr<Article> ArticleRepo::findById(const string& id) {
    bool isContained = articles_container.containsKey(id);

    if (isContained) {
        return articles_container.getOrDefault(id, nullptr);
    }

    return nullptr;
}

vector<shared_ptr<Article>> ArticleRepo::findByTitle(const string& titlePattern) const {
    vector<shared_ptr<Article>> res;

    try {
        const regex pattern(titlePattern, regex::icase);

        articles_container.forEach([&pattern, &res](const shared_ptr<Article>& article) -> void {
            const string& title = article->getTitle();

            if (regex_search(title, pattern)) {
                res.push_back(article->clone());
            }
        });
    }
    catch (const regex_error& e) {
        qCritical() << "Invalid regex pattern:" << e.what();
    }

    return res;
}

vector<shared_ptr<Article>> ArticleRepo::filterByYear(Type t) const {
    vector<shared_ptr<Article>> res;

    articles_container.forEach([&res, &t](const shared_ptr<Article>& article) -> void {
        if (article->getType() == t) {
            res.push_back(article->clone());
        }
    });

    return res;
}

vector<shared_ptr<Article>> ArticleRepo::filterByYear(int year) const {
    vector<shared_ptr<Article>> res;

    articles_container.forEach([&res, &year](const shared_ptr<Article>& article) -> void {
        if (article->getYear() == year) {
            res.push_back(article->clone());
        }
    });

    return res;
}

vector<shared_ptr<Article>> ArticleRepo::filterByCitation(int minCitations) const {
    vector<shared_ptr<Article>> res;

    articles_container.forEach([&res, &minCitations](const shared_ptr<Article>& article) -> void {
        if (article->getCitation() == minCitations) {
            res.push_back(article->clone());
        }
    });

    return res;
}

vector<shared_ptr<Article>> ArticleRepo::sortedByCitations(bool ascending) const {
    auto vec = getCopyAsVector();
    sort(vec.begin(), vec.end(), [ascending](const shared_ptr<Article>& a, const shared_ptr<Article>& b) {
        return ascending ? a->getCitation() < b->getCitation() : a->getCitation() > b->getCitation();
    });
    return vec;
}

vector<shared_ptr<Article>> ArticleRepo::sortedByYear(bool ascending) const {
    auto vec = getCopyAsVector();
    sort(vec.begin(), vec.end(), [ascending](const shared_ptr<Article>& a, const shared_ptr<Article>& b) {
        return ascending ? a->getYear() < b->getYear() : a->getYear() > b->getYear();
    });
    return vec;
}

vector<shared_ptr<Article>> ArticleRepo::sortedByImpactFactor(bool ascending) const {
    vector<shared_ptr<Article>> vec = getCopyAsVector();

    vector<shared_ptr<Article>> filtered;
    filtered.reserve(vec.size());

    // Lọc ra những bài báo SCIE
    for (auto& ptr : vec) {
        if (dynamic_cast<SCIE_Article*>(ptr.get())) {
            filtered.push_back(ptr->clone());
        }
    }

    // Sắp xếp theo ImpactFactor
    sort(filtered.begin(), filtered.end(),
         [ascending](const shared_ptr<Article>& a, const shared_ptr<Article>& b) {
             const auto* ja = static_cast<const SCIE_Article*>(a.get());
             const auto* jb = static_cast<const SCIE_Article*>(b.get());
             return ascending ?
                        (ja->getImpactFactor() < jb->getImpactFactor()) :
                        (ja->getImpactFactor() > jb->getImpactFactor());
         });

    return filtered;
}


vector<shared_ptr<Article>> ArticleRepo::sortedBySJR(bool ascending) const {
    vector<shared_ptr<Article>> vec = getCopyAsVector();

    vector<shared_ptr<Article>> filtered;
    filtered.reserve(vec.size());

    for (auto& ptr : vec) {
        if (dynamic_cast<SCOPUS_Article*>(ptr.get())) {
            filtered.push_back(ptr->clone());
        }
    }

    sort(filtered.begin(), filtered.end(),
         [ascending](const shared_ptr<Article>& a, const shared_ptr<Article>& b) {
             auto* ja = static_cast<SCOPUS_Article*>(a.get());
             auto* jb = static_cast<SCOPUS_Article*>(b.get());
             return ascending ? ja->getSJR() < jb->getSJR()
                              : ja->getSJR() > jb->getSJR();
         });

    return filtered;
}

vector<shared_ptr<Article>> ArticleRepo::sortedByHIndex(bool ascending) const {
    vector<shared_ptr<Article>> vec = getCopyAsVector();

    vector<shared_ptr<Article>> filtered;
    filtered.reserve(vec.size());

    for (auto& ptr : vec) {
        if (dynamic_cast<SCOPUS_Article*>(ptr.get())) {
            filtered.push_back(ptr->clone());
        }
    }

    sort(filtered.begin(), filtered.end(),
         [ascending](const shared_ptr<Article>& a, const shared_ptr<Article>& b) {
             auto* ja = static_cast<SCOPUS_Article*>(a.get());
             auto* jb = static_cast<SCOPUS_Article*>(b.get());
             return ascending ? ja->getHIndex() < jb->getHIndex()
                              : ja->getHIndex() > jb->getHIndex();
         });

    return filtered;
}

vector<shared_ptr<Article>> ArticleRepo::updateTitle(const string& id, const string& title) {
    vector<shared_ptr<Article>> affected;
    bool found = false;

    articles_container.forEach([&](const string& key, shared_ptr<Article>& article) {
        if (!found && key == id) {
            found = true;
            article->setTitle(title);
            affected.push_back(article->clone());
        }
    });

    return affected;
}


vector<shared_ptr<Article>> ArticleRepo::updateVenue(const string& id, const string& venue) {
    vector<shared_ptr<Article>> affected;
    affected.reserve(1);

    bool found = false;
    articles_container.forEach([&](const string& key, shared_ptr<Article>& article) {
        if (!found && key == id) {
            found = true;
            article->setVenue(venue);
            affected.push_back(article->clone());
        }
    });

    return affected;
}



vector<shared_ptr<Article>> ArticleRepo::updateYear(const string& id, const int& year) {
    vector<shared_ptr<Article>> affected;
    affected.reserve(1);
    bool found = false;

    articles_container.forEach([&](const string& key, shared_ptr<Article>& article) {
        if (!found && key == id) {
            found = true;
            article->setYear(year);
            affected.push_back(article->clone());
        }
    });

    return affected;
}



unsigned int ArticleRepo::count() const {
    return articles_container.size();
}


int ArticleRepo::countByType(Type t) const {
    int cnt = 0;

    articles_container.forEach([&](const shared_ptr<Article> article) -> void {
        if (article->getType() == t) ++cnt;
    });
    return cnt;
}

double ArticleRepo::averageCitations() const {
    if (articles_container.isEmpty()) return 0.0;
    long long sum = 0;

    articles_container.forEach([&](const shared_ptr<Article> article) -> void {
        sum += article->getCitation();
    });
    return static_cast<double>(sum) / articles_container.size();
}

void ArticleRepo::update(shared_ptr<Article> article) {
    if (!article || article->getId().empty()) {
        qWarning() << "update(): Invalid article or empty ID";
        return;
    }

    string id = article->getId();

    bool isExists = this->articles_container.containsKey(id);

    if (isExists) {
        articles_container[id] = std::move(article);
        qDebug() << "Article updated successfully:" << QString::fromStdString(id);
    }
    else {
        qWarning() << "update(): Article not found:" << QString::fromStdString(id);
        return;
    }
}
