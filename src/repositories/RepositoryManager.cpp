#include "repositories/RepositoryManager.h"
#include <algorithm>
#include <regex>

RepositoryManager::RepositoryManager(
    const map<string, Article *> &_articles,
    const map<string, Author> &_authors,
    const map<string, Journal> &_journals)
        : articles(_articles), authors(_authors), journals(_journals) {
    cout << "Repository initialized successfully!" << endl;
}

RepositoryManager::~RepositoryManager() {
    ranges::for_each(articles, [](auto& pair) -> void {
        delete pair.second;
    });
}

/* ========= Article ========= */

void RepositoryManager::addArticle(const Article& article) {
    const auto id = article.getArticleID();
    if (const auto it = this->articles.find(id); it != this->articles.end()) {
        cout << "Id nay da ton tai!" << endl;
        return;
    }
    this->articles[id] = article.clone();
}

Article * RepositoryManager::getArticleById(const string &id) const {
    if (const auto it = articles.find(id); it == articles.end()) {
        cout << "Article does not exist" << endl;
        return nullptr;
    }
    else {
        return it->second;
    }
}

vector<const Article*> RepositoryManager::getAllArticles() const {
    vector<const Article*> res;

    ranges::for_each(this->articles, [&](const auto &element) -> void {
         res.push_back(element.second);
    });

    return res;
}

void RepositoryManager::updateArticle(const Article &article) {
    const auto id = article.getArticleID();
    if (const auto it = articles.find(id); it != articles.end()) {
        delete it->second;
    }
    articles[id] = article.clone();
}

void RepositoryManager::deleteArticle(const string& id) {
    if (const auto it = articles.find(id); it != articles.end()) {
        articles.erase(it);
    }
}

vector<const Article *> RepositoryManager::findByTitle(const string &keyword) const {
    vector<const Article*> res;

    regex pattern(keyword);
    ranges::for_each(this->articles, [&](const auto &pair) -> void {
        if (regex_search(pair.second->getArticleID(), pattern)) {
            res.push_back(pair.second);
        }
    });

    return res;
}

vector<const Article *> RepositoryManager::findByAuthorId(const string &authorID) const {
    vector<const Article*> res;

    regex pattern(authorID);
    ranges::for_each(this->articles, [&](const auto& pair) -> void {
        if (regex_search(pair.second->getAuthorID(), pattern)) {
            res.push_back(pair.second);
        }
    });

    return res;
}

vector<const Article *> RepositoryManager::findByJournalId(const string &journalID) const {
    vector<const Article*> res;

    regex pattern(journalID);
    ranges::for_each(this->articles, [&](const auto &pair) -> void {
        if (regex_search(pair.second->getJournalID(), pattern)) {
            res.push_back(pair.second);
        }
    });

    return res;
}

/* ========= Author ========= */
void RepositoryManager::addAuthor(const Author& author) {
    const string authorID = author.getAuthorID();

    if (const auto it = authors.find(authorID); it == authors.end()) {
        authors[authorID] = author;
    } else {
        cout << "This authorID existed";
    }
}

Author RepositoryManager::getAuthorById(const string& id) const {
    if (const auto it = authors.find(id); it == authors.end()) {
        cout << "This authorID doesn't exist";
        return {};
    } else {
        return it->second;
    }
}

vector<Author> RepositoryManager::getAllAuthors() const {
    vector<Author> res;
    ranges::for_each(this->authors, [&](const pair<string, Author> &element) -> void {
        res.push_back(element.second);
    });
    return res;
}

void RepositoryManager::updateAuthor(const Author& author) {
    const string authorID = author.getAuthorID();
    if (const auto it = authors.find(authorID); it == authors.end()) {
        cout << "This authorID doesn't exist";
        return;
    }
    else {
        it->second = author;
    }
}

void RepositoryManager::deleteAuthor(const string& id) {
    if (const auto it = authors.find(id); it == authors.end()) {
        cout << "This authorID doesn't exist";
        return;
    } else {
        authors.erase(it);
    }
}

vector<Author> RepositoryManager::findByAuthorName(const string &keyword) const {
    vector<Author> result;

    const regex pattern(keyword, regex_constants::icase);

    ranges::for_each(this->authors, [&](const pair<string, Author> &element) -> void {
        if (regex_search(element.second.getAuthorName(), pattern)) {
            result.push_back(element.second);
        }
    });

    return result;
}

void RepositoryManager::addJournal(const Journal &journal) {
    const string journalID = journal.getJournalID();

    if (const auto it = journals.find(journalID); it == journals.end()) {
        journals[journalID] = journal;
    } else {
        cout << "This journalID existed" << endl;
    }
}

Journal RepositoryManager::getJournalById(const string& id) const {
    if (const auto it = journals.find(id); it == journals.end()) {
        cout << "This journalID doesn't exist" << endl;
        return {};
    } else {
        return it->second;
    }
}

vector<Journal> RepositoryManager::getAllJournals() const {
    vector<Journal> res;
    ranges::for_each(this->journals, [&](const pair<string, Journal> &element) -> void {
        res.push_back(element.second);
    });
    return res;
}

void RepositoryManager::updateJournal(const Journal &journal) {
    const string journalID = journal.getJournalID();
    if (const auto it = journals.find(journalID); it == journals.end()) {
        cout << "This journalID doesn't exist" << endl;
        return;
    }
    else {
        it->second = journal;
    }
}

void RepositoryManager::deleteJournal(const string& id) {
    if (const auto it = journals.find(id); it == journals.end()) {
        cout << "This journalID doesn't exist" << endl;
        return;
    } else {
        journals.erase(it);
    }
}

vector<Journal> RepositoryManager::findByName(const string &keyword) const {
    vector<Journal> res;

    const regex pattern(keyword, regex_constants::icase);

    ranges::for_each(this->journals, [&](const pair<string, Journal> &element) -> void {
        if (regex_search(element.second.getJournalName(), pattern)) {
            res.push_back(element.second);
        }
    });

    return res;
}

vector<Journal> RepositoryManager::findByType(const string &type) const {
    vector<Journal> res;

    const regex pattern(type, regex_constants::icase);

    ranges::for_each(this->journals, [&](const pair<string, Journal> &element) -> void {
        if (regex_match(element.second.getJournalName(), pattern)) {
            res.push_back(element.second);
        }
    });

    return res;
}

vector<Journal> RepositoryManager::findByYear(const int& year) const {
    vector<Journal> res;

    const regex pattern(to_string(year), regex_constants::icase);

    ranges::for_each(this->journals, [&](const pair<string, Journal> &element) -> void {
        if (regex_match(to_string(element.second.getPublishYear()), pattern)) {
            res.push_back(element.second);
        }
    });

    return res;
}

// General
template<>
unsigned int RepositoryManager::size<Article>() {
    return this->articles.size();
}

template<>
unsigned int RepositoryManager::size<Author>() {
    return this->authors.size();
}

template<>
unsigned int RepositoryManager::size<Journal>() {
    return this->journals.size();
}

template<typename T>
string RepositoryManager::generateID(const T& t) {
    const unsigned int number = RepositoryManager::size<T>() + 1;

    string res = t.getTypeName() + "_";

    if (number > 0 && number < 10) {
        res += "00" + to_string(number);
    } else if (number > 9 && number < 100) {
        res += "0" + to_string(number);
    } else {
        res += to_string(number);
    }

    return res;
}

