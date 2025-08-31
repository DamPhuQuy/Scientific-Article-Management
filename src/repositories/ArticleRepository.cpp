#include "repositories/ArticleRepository.h"
#include <iostream>
#include <ranges>

// constructor
ArticleRepository::ArticleRepository(map<string, Article*> &a) :
    articles(a) {}

ArticleRepository::~ArticleRepository() = default;

void ArticleRepository::setArticlesMap(const map<string, Article*> &articles) const {
    this->articles = articles;
}

map<string, Article*>& ArticleRepository::getArticlesMap() const {
    return this->articles;
}

void ArticleRepository::addArticle(Article* a) const {
    if (const string& id = a->getArticleID(); !articles.contains(id)) {
        articles[id] = a;
        cout << "The article ID: " << id << " added successfully!\n";
    } else {
        cout << "This article ID already exists!\n";
    }
}

void ArticleRepository::removeArticle(const string& articleID) const {
    if (!articles.contains(articleID)) {
        cout << "This article ID does not exist!\n";
    }
    else {
        articles.erase(articleID);
        cout << "The article ID: " << articleID << " deleted successfully!\n";
    }
}

Article* ArticleRepository::getArticle(const string &articleID) const {
    auto it = articles.find(articleID);
    if (it != articles.end()) return it->second;
    cout << "This article ID: " << articleID << " does not exist!\n";
    return nullptr;
}

vector<Article*> ArticleRepository::getAllArticles() const {
    vector<Article*> temp;

    for (auto &val: articles | views::values) {
        temp.push_back(val);
    }

    return temp; 
}

Article ArticleRepository::input(const map<string, Author> &authors, const map<string, Journal> &journals) {
    string name;
    cout << "Nhap vao ten bai bao: ";
    getline(cin, name);

    string authorID = IOHelper::chooseFromMap<Author>(authors, "Author");
    if (authorID == "New") {

    }

    string journalID = IOHelper::chooseFromMap<Journal>(journals, "Journal");
    if (journalID == "New") {

    }
}

void ArticleRepository::showArticleDescriptionByID(DataWrapper &dw, const int &articleID) {
    auto it = articles->find(articleID); 
    if (it == articles->end()) {
        cout << "ERROR: " << articleID << " not found!\n";
        return; 
    }
    else {
        Article article = it->second; 
        int articleID = article.getArticleID();
        int authorID = article.getAuthorID(); 
        int journalID = article.getJournalID(); 

        Author author = dw.getAuthors().at(authorID); 
        Journal journal = dw.getJournals().at(journalID); 

        cout << "Article ID: " << articleID << "\n"; 
        cout << "Article Name: " << article.getArticleName() << "\n"; 
        cout << "Author Name: " << author.getAuthorName() << "\n";
        cout << "Journal: " << journal.getJournalName() << "\n"; 
        cout << "Article status: " << article.parseString() << "\n"; 
    }
}
