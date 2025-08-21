#include <string> 
#include <vector> 
#include <unordered_map>
#include "Article.h"

using namespace std;

class ArticleRepository {
private: 
    unordered_map<int, Article> articles; 
public: 
    ArticleRepository(); 
    ArticleRepository(const unordered_map<int, Article> &articles);
    ArticleRepository(const ArticleRepository &current);
    ~ArticleRepository();

    void setArticlesMap(const unordered_map<int, Article> &articles); 
    unordered_map<int, Article> getArticlesMap() const; 

    void addArticle(const Article &article); 
    void removeArticle(int articleID); 

    Article getArticle(int articleID) const; 
    vector<Article> getAllArticles() const;   
};