#include "repositories/ArticleRepository.h"
#include <iostream>
#include <ranges>

// constructor
ArticleRepository::ArticleRepository(DataWrapper &dataWrapper) :
    data(dataWrapper) {} 

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
        cout << "The article ID: " << articles.articleID << " deleted successfully!\n";
    }
}

Article* ArticleRepository::getArticle(const string &articleID) const {
    auto it = articles.find(articleID);
    if (it != articles.end()) return it->second;
    cout << "This article ID: " << articleID << " does not exist!\n";
    return nullptr;
}

vector<data.Article*> ArticleRepository::getAllArticles() const {
    vector<data.Article*> temp;

    for (auto &val: articles | views::values) {
        temp.push_back(val);
    }

    return temp; 
}

Article ArticleRepository::input(map<string, Author> &data.authors, map<string, Journal> &data.journals) {
    string name;
    cout << "Nhap vao ten bai bao: ";
    getline(cin, name);

    map<int, Type> TypeMap = {
	    {0, Type::SCI}, 
	    {1, Type::SCIE},
	    {2, Type::ISI},
	    {3, Type::SCOPUS},
	    {4, Type::OTHER}
    }; 

    for (auto it = TypeMap.begin(); it != TypeMap.end(); ++it) {
        cout << "STT: " << it->first << " - " << DataManipulation::parseType(it->second);    
    }

    cout << "Chon the loai bai bao: "; 
    int choose; cin >> choose; cin.ignore(); 
    if (TypeMap.find(choose) == TypeMap.end()) {
        cout << "Loai bai bao khong hop le, chon mac dinh la OTHER\n";
        choose = 4; 
    }

    Article* newArticle = ArticleFactory::createEmptyArticle(TypeMap.at(choose)); 


    authorID = IOHelper::chooseFromMap<Author>(data.authors, "Author");
    if (authorID == "New") {
        AuthorRepository au_repo(data.authors);

    }

    journalID = IOHelper::chooseFromMap<Journal>(data.journals, "Journal");
    if (journalID == "New") {
        JournalRepository j_repo(data.journals);
    }
    
}

void ArticleRepository::showArticleDescriptionByID(const map<string, Author> &data.authors, const map<string, Journal> &data.journals, const string &articleID) {
    auto it = articles.find(articleID);
    if (it == articles.end()) {
        cout << "ERROR: " << articleID << " not found!\n";
        return; 
    }
    else {
        Article* article = it->second; 
        string articleID = article->getArticleID();
        string authorID = article->getAuthorID(); 
        string journalID = article->getJournalID(); 

        Author author = authors.at(authorID); 
        Journal journal = journals.at(journalID); 

        cout << "Article ID: " << articleID << "\n"; 
        cout << "Article Name: " << article->getArticleName() << "\n"; 
        cout << "Author Name: " << author.getAuthorName() << "\n";
        cout << "Journal: " << journal.getJournalName() << "\n"; 
        cout << "Article status: " << article->parseString() << "\n"; 
    }
}
