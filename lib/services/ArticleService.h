#pragma once 
#include "RepositoryManager.h"
#include "UUID_Generator.h" 
#include "DataManipulation.h"

class ArticleService {
private:
    RepositoryManager& repo; 

    void inputArticle(Article* article); 
    void inputArticleReferences(Article* article); 
public:
    ArticleService(RepositoryManager& repo); 
    ~ArticleService() = default; 

    RepositoryManager& getRepo() const { return repo; } 

    void createArticle(); 
};
