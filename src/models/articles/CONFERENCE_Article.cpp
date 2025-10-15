#include "models/articles/CONFERENCE_Article.h"

using namespace std; 

CONFERENCE_Article::CONFERENCE_Article(
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

CONFERENCE_Article::CONFERENCE_Article(const Article &other) : Article(other) {}

Article *CONFERENCE_Article::clone() const
{
    return new CONFERENCE_Article(*this);
}

