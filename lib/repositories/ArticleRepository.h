#pragma once

#include <string> 
#include <vector> 
#include <unordered_map>
#include "models/Article.h"
#include "utilities/IDManager.h"
#include "utilities/IOHelper.h" 
#include "services/DataManipulation.h"
#include "utilities/Constants.h"
#include "repositories/AuthorRepository.h"
#include "repositories/JournalRepository.h"

using namespace std;

class ArticleRepository {
private: 
    unordered_map<int, Article> *articles; 
public: 
    ArticleRepository(); 
    ArticleRepository(unordered_map<int, Article> *a);
    ArticleRepository(const ArticleRepository &current);
    ~ArticleRepository();

    void setArticlesMap(const unordered_map<int, Article> &articles); 
    unordered_map<int, Article>& getArticlesMap() const; 

    void addArticle(const Article &article); 
    void removeArticle(int articleID); 

    Article getArticle(int articleID) const; 
    vector<Article> getAllArticles() const;

    Article input(DataWrapper &data); 

    void showArticleDescriptionByID(DataWrapper &dw, const int &articleID); 
};