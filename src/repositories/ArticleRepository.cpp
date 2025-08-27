#include "repositories/ArticleRepository.h"
#include <iostream> 

ArticleRepository::ArticleRepository() {}

ArticleRepository::ArticleRepository(unordered_map<int, Article> *a) :
    articles(a) {}

ArticleRepository::ArticleRepository(const ArticleRepository &current) {
    this->articles = current.articles; 
}

ArticleRepository::~ArticleRepository() {}

void ArticleRepository::setArticlesMap(const unordered_map<int, Article> &articles) {
    *(this->articles) = articles; 
}

unordered_map<int, Article>& ArticleRepository::getArticlesMap() const {
    return *articles; 
}

void ArticleRepository::addArticle(const Article &article) {
    int a_id = article.getArticleID(); 

    auto it = articles->find(a_id); 
    if (it != articles->end()) {
        cout << "The id is duplicated\n"; 
        return; 
    }

    articles->insert({a_id, article}); 
}

void ArticleRepository::removeArticle(int articleID) {
    this->articles->erase(articleID); 
}

Article ArticleRepository::getArticle(int articleID) const {
    auto it = this->articles->find(articleID); 

    if (it == articles->end()) {
        cout << "Not found\n";
        return Article();  
    } else {
        return it->second; 
    }
}

vector<Article> ArticleRepository::getAllArticles() const {
    vector<Article> temp; 

    for (auto it = articles->begin(); it != articles->end(); it++) {
        temp.push_back(it->second); 
    }

    return temp; 
}

Article ArticleRepository::input(DataWrapper &data) {
    int newID = IDManager::generateNextID(data.getArticles()); 

    string name;
    cout << "Enter the article title: "; 
    cin.ignore();
    getline(cin, name);

    // author

    int authorID = IOHelper::chooseFromMap<Author>(data.getAuthors(), "Author"); 
                                
    Author author;
    if (authorID == 0) {
        authorID = IDManager::generateNextID(data.getAuthors()); 
        AuthorRepository au_repo(&data.getAuthors());
        author = au_repo.input(authorID, newID); 
    }
    
    // journal
    
    int journalID = IOHelper::chooseFromMap<Journal>(data.getJournals(), "Journal"); 

    Journal journal; 
    if (journalID == 0) {
       journalID = IDManager::generateNextID<Journal>(data.getJournals()); 
       JournalRepository j_repo(&data.getJournals()); 
       journal = j_repo.input(journalID, newID); 
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

    Article article(newID, name, authorID, journalID, status); 

    return article; 
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
