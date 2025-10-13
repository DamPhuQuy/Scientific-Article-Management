#include "models/articles/SCIE_Article.h"

using namespace std; 

SCIE_Article::SCIE_Article(
    string abstract,
	int n_citation,
	string title,
	string venue,
	int year = 0,
    string a_id,
    Type t,
    ArticleStatus st
)
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

SCIE_Article::SCIE_Article(const Article &other) : Article(other) {}

Article* SCIE_Article::clone() const {
    return new SCIE_Article(*this);
}