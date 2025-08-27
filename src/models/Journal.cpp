#include "models/Journal.h"

using namespace std;

Journal::Journal() {}

Journal::Journal(int j_id, 
                 string j_name,
                 journalTypes j_type,
                 int pNum,
                 string pYear,
                 string p,
                 vector<int> ids) : 
    journalID(j_id), journalName(j_name), types(j_type), publishNumber(pNum), publishYear(pYear), publisher(p), articlesID(ids) {}


Journal::Journal(const Journal &j) {
    this->journalID = j.journalID;
    this->journalName = j.journalName;
    this->types = j.types;
    this->publishNumber = j.publishNumber;
    this->publishYear = j.publishYear;
    this->publisher = j.publisher;
    this->articlesID = j.articlesID;
}

Journal::~Journal() {}

void Journal::setJournalID(int journalID) {
    this->journalID = journalID;
}

int Journal::getJournalID() const {
    return this->journalID;
}

void Journal::setJournalName(string journalName) {
    this->journalName = journalName;
}

string Journal::getJournalName() const {
    return this->journalName;
}

void Journal::setTypes(journalTypes types) {
    this->types = types;
}

journalTypes Journal::getTypes() const {
    return this->types;
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

string Journal::toString(journalTypes type) const {
    if (type == journalTypes::SCI)
        return "SCI"; 
    else if (type == journalTypes::SCIE) 
        return "SCIE"; 
    else if (type == journalTypes::SCOPUS) 
        return "SCOPUS"; 
    else if (type == journalTypes::ISI)
        return "ISI"; 
    else if (type == journalTypes::OTHER)
        return "OTHER"; 
    else {
        cout << "Invalid journal type!\n"; 
        return ""; 
    }
}

vector<int> Journal::getArticlesID() const {
    return this->articlesID; 
}