#include "RepositoryManager.h"
#include <algorithm> 
#include <iostream> 

using namespace std;

RepositoryManager::RepositoryManager(
    const ArticleRepo& a_repo = ArticleRepo(),
    const AuthorRepo& au_repo = AuthorRepo(),
    const AuthorArticleRepo& au_ar = AuthorArticleRepo(),
    const ArticleReferenceRepo& ar_ref = ArticleReferenceRepo()
)
    : a_repo(a_repo),
      au_repo(au_repo),
      ar_ref(ar_ref),
      au_ar(au_ar)
{}

// void RepositoryManager::sync()
// {
    
// }
