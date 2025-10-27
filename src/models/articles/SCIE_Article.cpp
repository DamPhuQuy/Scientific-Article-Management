#include "SCIE_Article.h"
#include <iostream> 
using namespace std; 

SCIE_Article::SCIE_Article(
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
    id, 
    t, 
    st,
    r
) {}

SCIE_Article::SCIE_Article( 
    string abstract,
	int n_citation,
	string title,
	string venue,
	int year,
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
    t, 
    st,
    r
) {}

SCIE_Article::~SCIE_Article()
{
}

SCIE_Article::SCIE_Article(const Article &other) : Article(other) {}

void SCIE_Article::showDescription() const
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

Article *SCIE_Article::clone() const
{
    return new SCIE_Article(*this);
}

Article *SCIE_Article::input() const
{
    return nullptr;
}
