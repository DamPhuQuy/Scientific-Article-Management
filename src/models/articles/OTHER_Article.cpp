#include "OTHER_Article.h"
#include <iostream>
using namespace std;

OTHER_Article::OTHER_Article(
    string abstract,
    int n_citation,
    string title,
    string venue,
    int year,
    string id,
    Type t,
    ArticleStatus st,
    const vector<string> &r)
    : Article(
          abstract,
          n_citation,
          title,
          venue,
          year,
          id.empty() ? UUID_Generator::generateUUID() : id,
          t,
          st,
          r) {}

OTHER_Article::~OTHER_Article()
{
}

OTHER_Article::OTHER_Article(const Article &other) : Article(other) {}

void OTHER_Article::showDescription()
{
    cout << "==== ARTICLE INFO ====" << endl;
    cout << "ID: " << article_id << endl;
    cout << "Title: " << title << endl;
    cout << "Venue: " << venue << endl;
    cout << "Year: " << year << endl;
    cout << "Citations: " << n_citation << endl;
    cout << "Type: " << typeToString() << endl;
    cout << "Abstract: ";
    printAbstract(this->abstract);
    cout << "============================" << endl;
}

Article *OTHER_Article::clone() const
{
    return new OTHER_Article(*this);
}
