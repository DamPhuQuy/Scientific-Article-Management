#include "models/articles/CONFERENCE_Article.h"

using namespace std; 

CONFERENCE_Article::CONFERENCE_Article(
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

CONFERENCE_Article::CONFERENCE_Article(const Article &other) : Article(other) {}

Article *CONFERENCE_Article::clone() const
{
    return new CONFERENCE_Article(*this);
}