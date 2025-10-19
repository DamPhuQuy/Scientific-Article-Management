#include "RepositoryManager.h"
#include <algorithm> 
#include <iostream> 

using namespace std;

RepositoryManager::RepositoryManager(
    ArticleRepo& a_repo,
    AuthorRepo& au_repo,
    AuthorArticleRepo& au_ar,
    ArticleReferenceRepo& ar_ref
)
    : a_repo(a_repo),
      au_repo(au_repo),
      ar_ref(ar_ref),
      au_ar(au_ar)
{}

ArticleRepo &RepositoryManager::getArticles()
{ return a_repo; }
AuthorRepo &RepositoryManager::getAuthors()
{ return au_repo; }
AuthorArticleRepo &RepositoryManager::getAuthorArticles()
{ return au_ar; }
ArticleReferenceRepo &RepositoryManager::getArticleReferences()
{ return ar_ref; }


// void RepositoryManager::sync()
// {
    
// }
