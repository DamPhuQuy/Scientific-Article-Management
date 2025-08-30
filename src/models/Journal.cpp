#include "models/Journal.h"
#include "models/Article.h" 

using namespace std;

Journal::Journal() : 
    journalID(""),
    journalName(""),
    type(Type::OTHER),
    publishNumber(0),
    publishYear(""),
    publisher(""),
    articlesID({}) {
}

Journal::Journal(string j_id,
                 string j_name,
                 Type j_type,
                 int pNum,
                 string pYear,
                 string p,
                 vector<string> ids) : 
    journalID(j_id),
    journalName(j_name),
    type(j_type),        
    publishNumber(pNum),
    publishYear(pYear),
    publisher(p),
    articlesID(ids) {
}


Journal::Journal(const Journal &j) {
    this->journalID = j.journalID;
    this->journalName = j.journalName;
    this->type = j.type;
    this->publishNumber = j.publishNumber;
    this->publishYear = j.publishYear;
    this->publisher = j.publisher;
    this->articlesID = j.articlesID;
}

Journal::~Journal() {}

void Journal::setJournalID(int journalID) {
    this->journalID = journalID;
}

string Journal::getJournalID() const {
    return this->journalID;
}

void Journal::setJournalName(string journalName) {
    this->journalName = journalName;
}

string Journal::getJournalName() const {
    return this->journalName;
}

void Journal::setType(Type type) {
}

string Journal::getType() const {
    if (type == Type::SCI)
        return "SCI";
    else if (type == Type::SCIE)
        return "SCIE";
    else if (type == Type::SCOPUS)
        return "SCOPUS";
    else if (type == Type::ISI)
        return "ISI";
    else if (type == Type::OTHER)
        return "OTHER";
    else {
        cout << "Invalid journal type!\n";
        return "";
    }
}

void Journal::setPublishNumber(int publishNumber) {
    this->publishNumber = publishNumber;
}

int Journal::getPublishNumber() const {
    return this->publishNumber;
}

void Journal::setPublishYear(string publishYear) {
    this->publishYear = publishYear;
}

string Journal::getPublishYear()const {
    return this->publishYear;
}

void Journal::setPublisher(string publisher) {
    this->publisher = publisher;
}

string Journal::getPublisher() const {
    return this->publisher;
}

vector<string> Journal::getArticlesID() const {
    return this->articlesID; 
}