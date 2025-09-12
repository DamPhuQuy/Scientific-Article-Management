#pragma once

#include <vector>
#include <map>
#include "utilities/IOHelper.h"
#include "repositories/DataWrapper.h"
#include "utilities/ArticleFactory.h"
#include "services/DataManipulation.h"


using namespace std;

class ArticleRepository {
private:
    DataWrapper &data;
public:
    // constructor
    explicit ArticleRepository(DataWrapper &dataWrapper);
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