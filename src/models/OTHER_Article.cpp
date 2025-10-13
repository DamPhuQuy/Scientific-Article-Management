#include "models/OTHER_Article.h"

using namespace std; 

OTHER_Article::OTHER_Article(
    string abstract, 
    vector<string> authors, 
    int n_citation, 
    vector<string> references, 
    string title, 
    string venue, 
    int year, 
    string a_id, 
    Type t, 
    ArticleStatus st)
: Article(
    abstract, 
    authors, 
    n_citation, 
    references, 
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