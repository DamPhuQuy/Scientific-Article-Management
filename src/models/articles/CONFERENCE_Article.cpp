#include "CONFERENCE_Article.h"
#include <iostream> 
using namespace std; 

CONFERENCE_Article::CONFERENCE_Article(
    string abstract,
	int n_citation,
	string title,
	string venue,
	int year,
    string id, 
    Type t,
    ArticleStatus st,
    const vector<string>& r
)
: Article(
    abstract, 
    n_citation, 
    title, 
    venue, 
    year,  
    id.empty() ? UUID_Generator::generateUUID() : id, 
    t, 
    st,
    r
) {}

CONFERENCE_Article::~CONFERENCE_Article() {} 

CONFERENCE_Article::CONFERENCE_Article(const Article &other) : Article(other) {}

void CONFERENCE_Article::showDescription() const
{
    cout << "==== ARTICLE INFO ====" << endl;
    cout << "ID: " << article_id << endl;
    cout << "Title: " << title << endl;
    cout << "Venue: " << venue << endl;
    cout << "Year: " << year << endl;
    cout << "Citations: " << n_citation << endl;
    cout << "Type: " << typeToString() << endl;
    cout << "Abstract: " << abstract << endl;
    cout << "============================" << endl; 
}

Article *CONFERENCE_Article::clone() const
{
    return new CONFERENCE_Article(*this);
}
