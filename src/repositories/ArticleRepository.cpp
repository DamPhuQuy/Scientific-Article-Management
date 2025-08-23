#include "repositories/ArticleRepository.h"
#include <iostream> 

ArticleRepository::ArticleRepository() {}

ArticleRepository::ArticleRepository(const unordered_map<int, Article> &articles) {
    this->articles = articles; 
}

ArticleRepository::ArticleRepository(const ArticleRepository &current) {
    this->articles = current.articles; 
}

ArticleRepository::~ArticleRepository() {}

void ArticleRepository::setArticlesMap(const unordered_map<int, Article> &articles) {
    this->articles = articles; 
}

unordered_map<int, Article> ArticleRepository::getArticlesMap() const {
    return this->articles; 
}

void ArticleRepository::addArticle(const Article &article) {
    int a_id = article.getArticleID(); 

    auto it = articles.find(a_id); 
    if (it == articles.end()) {
        cout << "The id is duplicated\n"; 
        return; 
    }

    articles.insert({a_id, article}); 
}

void ArticleRepository::removeArticle(int articleID) {
    this->articles.erase(articleID); 
}

Article ArticleRepository::getArticle(int articleID) const {
    auto it = this->articles.find(articleID); 

    if (it == articles.end()) {
        cout << "Not found\n";
        return Article();  
    } else {
        return it->second; 
    }
}

vector<Article> ArticleRepository::getAllArticles() const {
    vector<Article> temp; 

    for (auto it = articles.begin(); it != articles.end(); it++) {
        temp.push_back(it->second); 
    }

    return temp; 
}

/* @Override */
template<>
Article ArticleRepository::input<Article>(DataWrapper &data) {
    int newID = IDManager::generateNextID(*data.articles);

    string name;
    cout << "Enter the article title: "; 
    cin.ignore();
    getline(cin, name);

    // author
    cout << "List of authors: \n"; 
    for (auto it = data.authors->begin(); it != data.authors->end(); it++) {
        cout << "Author ID: " 
             << it->first
             << " - Author Name: "
             << it->second.getAuthorName()
             << "\n"; 
    }

    cout << "Choose available Author ID or create a new one (enter 0): ";
    int authorID; cin >> authorID; 
    if (authorID == 0) {
        authorID = IDManager::generateNextID<Author>(*data.authors); // real instance

        
    }
    
    // journal
    cout << "List of journals: \n";
    for (auto it = data.journals->begin(); it != data.journals->end(); it++) {
        cout << "Journal ID: "
             << it->first 
             << " - Journal Name: "
             << it->second.getJournalName()
             << "\n"; 
    }

    cout << "Choose available Journal ID or create a new one (enter 0): ";
    int journalID; cin >> journalID;
    if (journalID == 0) {
       journalID = IDManager::generateNextID<Journal>(*data.journals); 


    }

    // status

    unordered_map<int, string> statusMapping = {
        {0, "DRAFT"},
        {1, "SUBMITTED"}, 
        {2, "UNDER_REVIEW"}, 
        {3, "REVISIONS"},  
        {4, "ACCEPTED"}, 
        {5, "REJECTED"},  
        {6, "PUBLISHED"}
    };

    cout << "List of article status: \n"; 
    for (const auto& e : statusMapping) {
        cout << e.first << " - " << e.second << "\n"; 
    }

    int statusChoice; cin >> statusChoice;
    ArticleStatus status; 
    status = DataManipulation::parseStatus(statusMapping.at(statusChoice));
}
