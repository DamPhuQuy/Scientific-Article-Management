#include "RepositoryManager.h"
#include <algorithm> 
#include <iostream> 

using namespace std;

RepositoryManager::RepositoryManager(
    ArticleRepo &a_repo, 
    AuthorRepo &au_repo, 
    AuthorArticleRepo &au_ar
)
: a_repo(a_repo), au_repo(au_repo), au_ar(au_ar)
{
}

ArticleRepo &RepositoryManager::getArticles()
{ return a_repo; }
AuthorRepo &RepositoryManager::getAuthors()
{ return au_repo; }
AuthorArticleRepo &RepositoryManager::getAuthorArticles()
{ return au_ar; }


// void RepositoryManager::sync()
// {
    
// }
