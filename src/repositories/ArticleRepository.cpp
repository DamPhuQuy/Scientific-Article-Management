#include "ArticleRepository.h"

ArticleRepository::ArticleRepository() {}

ArticleRepository::ArticleRepository(const unordered_map<int, Article> &articles) {
    this->articles = articles; 
}

ArticleRepository::ArticleRepository(const ArticleRepository &other) {
    this->articles = other.articles; 
}

ArticleRepository::~ArticleRepository() {}

void ArticleRepository::addArticle(const Article &article) {
    this->articles.insert({article.getArticleID(), article}); 
}

void ArticleRepository::removeArticle(int articleID) {
    this->articles.erase(articleID); 
}

Article ArticleRepository::getArticle(int articleID) const {
    auto it = this->articles.find(articleId); 
    
    
}

