#include "models/articles/OTHER_Article.h"

using namespace std; 

OTHER_Article::OTHER_Article(
    string abstract, 
    int n_citation, 
    string title, 
    string venue, 
    int year, 
    string a_id, 
    Type t, 
    ArticleStatus st)
: Article(
    abstract, 
    n_citation, 
    title, 
    venue, 
    year, 
    a_id, 
    t, 
    st
) {}

OTHER_Article::OTHER_Article(const Article &other) : Article(other) {}

Article *OTHER_Article::clone() const {
    return new OTHER_Article(*this) ;
}