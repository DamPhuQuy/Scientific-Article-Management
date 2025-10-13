#include "models/articles/SCIE_Article.h"

using namespace std; 

SCIE_Article::SCIE_Article(
    string abstract,
	vector<string> authors,
	int n_citation,
	vector<string> references,
	string title,
	string venue,
	int year = 0,
    string a_id,
    Type t,
    ArticleStatus st
)
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

SCIE_Article::SCIE_Article(const Article &other) : Article(other) {}

Article* SCIE_Article::clone() const {
    return new SCIE_Article(*this);
}