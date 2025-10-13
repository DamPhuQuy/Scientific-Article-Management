#include "repositories/RepositoryManager.h"
#include <algorithm> 

using namespace std;

RepositoryManager::RepositoryManager(unordered_map<string, Article *> articles_container, vector<ArticleReference> ar_ref, vector<AuthorArticle> au_ar)
: articles_container(articles_container),
  ar_ref(ar_ref),
  au_ar(au_ar)
{
}

RepositoryManager::~RepositoryManager()
{
    for (auto element : articles_container) {
        delete element.second; 
    }
}
