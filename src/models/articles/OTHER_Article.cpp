#include "OTHER_Article.h"
#include <iostream> 
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

OTHER_Article::~OTHER_Article()
{
}

OTHER_Article::OTHER_Article(const Article &other) : Article(other) {}

void OTHER_Article::showDescription() const
{
    cout << "==== ARTICLE INFO ====" << endl;
    cout << "ID: " << article_id << endl;
    cout << "Title: " << title << endl;
    cout << "Venue: " << venue << endl;
    cout << "Year: " << year << endl;
    cout << "Citations: " << n_citation << endl;
    cout << "Type: " << typeToString(type) << endl;
    cout << "Abstract: " << abstract << endl;
    cout << "============================" << endl; 
}

Article *OTHER_Article::clone() const
{
    return new OTHER_Article(*this) ;
}

Article *OTHER_Article::input() const
{
    return nullptr;
}
