#include "models/Article.h"

using namespace std;

const unordered_map<Type, string> Article::TypeNames = {
    {Type::SCI, "SCI"},
    {Type::SCIE, "SCIE"},
    {Type::ISI, "ISI"},
    {Type::SCOPUS, "SCOPUS"},
    {Type::OTHER, "OTHER"}
};

const unordered_map<ArticleStatus, string> Article::StatusNames = {
    {ArticleStatus::DRAFT, "Draft"},
    {ArticleStatus::SUBMITTED, "Submitted"},
    {ArticleStatus::UNDER_REVIEW, "Under Review"},
    {ArticleStatus::REVISIONS, "Revisions Required"},
    {ArticleStatus::ACCEPTED, "Accepted"},
    {ArticleStatus::REJECTED, "Rejected"},
    {ArticleStatus::PUBLISHED, "Published"}
};

// Constructor

Article::Article(const string &a_id,
            const string &a_name,
            const string &au_id,
            const string &j_id,
            const Type t,
            const ArticleStatus st) :
    articleID(a_id), articleName(a_name), authorID(au_id), journalID(j_id), type(t), status(st) {}

// Getter and setter

string Article::getArticleID() const {
    return this->articleID;
}

string Article::getArticleName() const {
    return this->articleName;
}

string Article::getAuthorID() const {
    return this->authorID;
}

string Article::getJournalID() const {
    return this->journalID;
}

string Article::getTypeName() const {
    return TypeNames.at(type); 
}

string Article::getStatusName() const {
    return StatusNames.at(status); 
}

// status working flow

void Article::submit() {
    if (this->status == ArticleStatus::DRAFT) {
        this->status = ArticleStatus::SUBMITTED;
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
}

void Article::reject() {
    if (this->status == ArticleStatus::UNDER_REVIEW || this->status == ArticleStatus::REVISIONS) {
        this->status = ArticleStatus::REJECTED; 
    }
}

void Article::publish() {
    if (this->status == ArticleStatus::ACCEPTED) {
        this->status = ArticleStatus::PUBLISHED; 
    }
}

// abstract method

void Article::display() const {
    cout << "Article ID: " << this->articleID << endl;
    cout << "Article Title: " << this->articleName << endl;
    cout << "Author ID: " << this->authorID << endl;
    cout << "Journal ID: " << this->journalID << endl;
    cout << "Type: " << Article::getTypeName() << endl;
    cout << "Status: " << Article::getStatusName() << endl;
}

void Article::generateID(const int &count) {
    string concat = "";
    if (count >= 0 && count < 9) {
        concat = "00" + to_string(count + 1);
    } else if (count >= 9 && count < 99) {
        concat = "0" + to_string(count + 1);
    } else {
        concat = to_string(count + 1); 
    }
    articleID = getTypeName() + "-" + concat; 
}

SCI_Article::SCI_Article(
    const string &a_id, 
    const string &a_name, 
    const string &au_id, 
    const string &j_id, 
    ArticleStatus st
)
: Article(a_id, a_name, au_id, j_id, Type::SCI, st) {}

SCIE_Article::SCIE_Article(
    const string &a_id,
    const string &a_name, 
    const string &au_id,
    const string &j_id, 
    ArticleStatus st
)
: Article(a_id, a_name, au_id, j_id, Type::SCIE, st) {} 

ISI_Article::ISI_Article(
    const string &a_id, 
    const string &a_name, 
    const string &au_id,
    const string &j_id, 
    ArticleStatus st
)
: Article(a_id, a_name, au_id, j_id, Type::ISI, st) {} 

SCOPUS_Article::SCOPUS_Article(
    const string &a_id,
    const string &a_name, 
    const string &au_id, 
    const string &j_id, 
    ArticleStatus st
)
: Article(a_id, a_name, au_id, j_id, Type::SCOPUS, st) {}

OTHER_Article::OTHER_Article(
    const string &a_id, 
    const string &a_name, 
    const string &au_id,
    const string &j_id, 
    ArticleStatus st
)
: Article(a_id, a_name, au_id, j_id, Type::OTHER, st) {} 