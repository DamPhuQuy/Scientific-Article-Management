#include <iostream>
#include "Article.h"

using namespace std;

int Article::count = 0; 

string Article::typeToString(Type type) {
    switch (type) {
        case Type::SCIE:       return "SCIE";
        case Type::SCOPUS:     return "SCOPUS";
        case Type::CONFERENCE: return "CONFERENCE";
        default:               return "OTHER";
    }
}

string Article::statusToString(ArticleStatus status) {
    switch(status) {
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
                int n_citation,
                string title, string venue,
                int year,
                string a_id,
                Type t,
                ArticleStatus st)
    : abstract(abstract),
      n_citation(n_citation),
      title(title),
      venue(venue),
      year(year),
      article_id(a_id),
      type(t),
      status(st) {
    ++count; 
}

Article::Article(const Article &other)
    : abstract(other.abstract),
      n_citation(other.n_citation),
      title(other.title),
      venue(other.venue),
      year(other.year),
      article_id(other.article_id),
      type(other.type),
      status(other.status) {
    ++count; 
}

[[nodiscard]] string Article::getId() const {
    return article_id;
}

[[nodiscard]] string Article::getArticleTitle() const {
    return title;
}

[[nodiscard]] int Article::getYear() const
{
    return year;
}

Type Article::getType(int order)
{
    if (order >= 1 && order <= 4)
        return static_cast<Type>(order);
    return Type::OTHER;
}

ArticleStatus Article::getStatus(int order) {
    if (order >= 11 && order <= 17)
        return static_cast<ArticleStatus>(order); 
    return ArticleStatus::DRAFT; 
}

[[nodiscard]] string Article::getVenueName() const
{
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

