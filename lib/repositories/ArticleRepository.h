#pragma once

#include <vector>
#include <map>
#include "models/Article.h"
#include "utilities/IOHelper.h"
#include "repositories/AuthorRepository.h"
#include "utilities/ArticleFactory.h"
#include "services/DataManipulation.h"

using namespace std;

class ArticleRepository {
private:
    map<string, Article*> &articles;
public:
    // constructor
    explicit ArticleRepository(map<string, Article*> &a);
    ~ArticleRepository();

    // getter and setter
    void setArticlesMap(const map<string, Article*> &articles) const;
    [[nodiscard]] map<string, Article*>& getArticlesMap() const;

    void addArticle(Article *a) const;

    void removeArticle(const string& articleID) const;

    [[nodiscard]] Article* getArticle(const string &articleID) const;
    [[nodiscard]] vector<Article*> getAllArticles() const;

    Article input(map<string, Author> &authors, map<string, Journal> &journals);

    void showArticleDescriptionByID(const map<string, Author> &authors, const map<string, Journal> &journals, const string &articleID); 
};