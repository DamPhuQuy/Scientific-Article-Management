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
    if (it == aritcle.end()) {
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

void ArticleRepository::input() {
    int articleID = IDManager::generateNextID(this->articles);

    string articleName; 
    getline(cin, articleName); 

    
}
