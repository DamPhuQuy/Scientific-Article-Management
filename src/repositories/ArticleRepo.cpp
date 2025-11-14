#include "ArticleRepo.h"
#include "SearchByRegex.h"
#include "MenuUtilities.h"
#include <thread>           // sleep_for
#include <chrono>           // milliseconds
#include <iostream>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono_literals;

ArticleRepo::ArticleRepo(unordered_map<string, Article *> ar_con)
: articles_container(ar_con)
{
}

ArticleRepo::~ArticleRepo()
{
    for (auto &element : this->articles_container) {
        delete element.second;
    }
}

void ArticleRepo::add(Article* a)
{
    string id = a->getId();
    auto it = this->articles_container.find(id);
    if (it != this->articles_container.end()) {
        cout << "Id nay da ton tai!" << endl;
        delete a;
        return;
    }
    else {
        this->articles_container[id] = a;
    }
}

void ArticleRepo::remove(const Article &a)
{
    string id = a.getId();
    auto it = this->articles_container.find(id);
    if (it != this->articles_container.end()) {
        delete it->second;
        this->articles_container.erase(it);
    }
    else {
        cout << "Id nay khong ton tai!" << endl;
    }
}


void ArticleRepo::traverse()
{
    for (auto element : articles_container) {
        element.second->showDescription();
    }
}

unordered_map<string, Article *> &ArticleRepo::getContainer()
{
    return this->articles_container;
}

vector<Article*> ArticleRepo::getAll() const {
    vector<Article*> res;
    for (auto element : this->articles_container) {
        res.push_back(element.second);
    }
    return res;
}

string ArticleRepo::liveSearchByTitle() const {
    auto getTitle = [](Article* a) -> string { return a->getArticleTitle(); };

    auto printArticle = [](Article* a, bool highlight) -> void {
        if (highlight)
            cout << "-> " << "[" << a->getArticleTitle() << "] (" << a->getYear() << ", " << a->typeToString() << ")\n";
        else
            cout << "    " << "[" << a->getArticleTitle() << "] (" << a->getYear() << ", " << a->typeToString() << ")\n";
    };

    return SearchByRegex::liveSearch(
        this->articles_container,
        getTitle,
        printArticle
    );
}

string ArticleRepo::liveSearchByYear() const {
    auto getYear = [](Article* a) -> string { return to_string(a->getYear()); };
    auto printArticle = [](Article* a, bool highlight) -> void {
        if (highlight)
            cout << "-> " << "[" << a->getYear() << "] (" << a->getArticleTitle() << ", " << a->typeToString() << ")\n";
        else
            cout << "    " << "[" << a->getYear() << "] (" << a->getArticleTitle() << ", " << a->typeToString() << ")\n";
    };

    return SearchByRegex::liveSearch(
        this->articles_container,
        getYear,
        printArticle
    );
}

string ArticleRepo::liveSearchByType() const {
    auto getType = [](Article* a) -> string{
        return a->typeToString();
    };

    auto printArticle = [](Article* a, bool highlight) -> void {
        if (highlight)
            cout << "-> " << "[" << a->typeToString() << "] (" << a->getArticleTitle() << ", " << a->getYear() << ")\n";
        else
            cout << "    " << "[" << a->typeToString() << "] (" << a->getArticleTitle() << ", " << a->getYear() << ")\n";
    };

    return SearchByRegex::liveSearch(
        this->articles_container,
        getType,
        printArticle
    );
}

