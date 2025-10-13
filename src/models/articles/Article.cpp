#include "models/articles/Article.h"
#include <iostream>
#include "Article.h"

using namespace std;

string Article::typeToString() const {
    switch (this->type) {
        case Type::SCIE:       return "SCIE";
        case Type::SCOPUS:     return "SCOPUS";
        case Type::CONFERENCE: return "CONFERENCE";
        default:               return "OTHER";
    }
}

string Article::statusToString() const {
    switch(this->status) {
        case ArticleStatus::SUBMITTED:     return "SUBMITTED";
        case ArticleStatus::UNDER_REVIEW:  return "UNDER_REVIEW";
        case ArticleStatus::REVISIONS:     return "REVISIONS";
        case ArticleStatus::ACCEPTED:      return "ACCEPTED";
        case ArticleStatus::REJECTED:      return "REJECTED";
        case ArticleStatus::PUBLISHED:     return "PUBLISHED";
        default:                           return "DRAFT";
    }
}

Article::Article(string abstract,
                vector<string> authors,
                int n_citation,
                vector<string> references,
                string title, string venue,
                int year,
                string a_id,
                Type t,
                ArticleStatus st)
    : abstract(abstract),
      authors(authors),
      n_citation(n_citation),
      references(references),
      title(title),
      venue(venue),
      year(year),
      article_id(a_id),
      type(t),
      status(st) {
}

Article::Article(const Article &other)
    : abstract(other.abstract),
      authors(other.authors),
      n_citation(other.n_citation),
      references(other.references),
      title(other.title),
      venue(other.venue),
      year(other.year),
      article_id(other.article_id),
      type(other.type),
      status(other.status) {
}

[[nodiscard]] string Article::getArticleID() const {
    return article_id;
}

[[nodiscard]] string Article::getArticleTitle() const {
    return title;
}

[[nodiscard]] vector<string> Article::getAuthors() const {
    if (authors.empty()) {
        return {};
    }

    return authors;
}

[[nodiscard]] vector<string> Article::getReferences() const {
    return references;
}

[[nodiscard]] int Article::getYear() const
{
    return year;
}

[[nodiscard]] string Article::getVenueName() const {
    return venue;
}

string Article::getAbstract() const
{
    return abstract;
}

int Article::getCitation() const
{
    return n_citation;
}

// status working flow

void Article::submit() {
    int choice; 
    cout << "ban co muon submit khong (1: co, 0: khong): ";
    cin >> choice;
    if (choice == 0) {
        return; 
    }
    else if(choice != 1) {
        cout << "Lua chon khong hop le!" << endl; 
        return; 
    }
    else{
        if (this->status == ArticleStatus::DRAFT) {
            this->status = ArticleStatus::SUBMITTED;
        }
        cout<<"Da submit thanh cong!"<<endl; 
    }
}

void Article::startReview() {
    if (this->status == ArticleStatus::SUBMITTED) {
        this->status = ArticleStatus::UNDER_REVIEW; 
    }
}

void Article::requestRevisions() {
    if (this->status == ArticleStatus::UNDER_REVIEW) {
        this->status = ArticleStatus::REVISIONS;
    }
}

void Article::accept() {
    if (this->status == ArticleStatus::REVISIONS) {
        this->status = ArticleStatus::ACCEPTED; 
    }
    cout<<"Bai bao cua ban da duoc accept !"<<endl;
}

void Article::reject() {
    if (this->status == ArticleStatus::UNDER_REVIEW || this->status == ArticleStatus::REVISIONS) {
        this->status = ArticleStatus::REJECTED; 
    }
    cout<<"Bai bao cua ban da bi reject !"<<endl;
}

void Article::publish() {
    if (this->status == ArticleStatus::ACCEPTED) {
        this->status = ArticleStatus::PUBLISHED; 
    }
    cout<<"Bai bao da duoc publish !"<<endl;
}

// abstract method

void Article::display() const {
    //
}

