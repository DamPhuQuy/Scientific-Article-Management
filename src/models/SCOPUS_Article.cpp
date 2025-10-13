#include "models/SCOPUS_Article.h"

using namespace std; 

SCOPUS_Article::SCOPUS_Article(
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

SCOPUS_Article::SCOPUS_Article(const Article &other) : Article(other) {}

Article *SCOPUS_Article::clone() const {
    return new SCOPUS_Article(*this);
}