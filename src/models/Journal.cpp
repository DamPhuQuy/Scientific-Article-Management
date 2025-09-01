#include <utility>

#include "models/Journal.h"

using namespace std;

Journal::Journal(string j_id,
                 string j_name,
                 const Type j_type,
                 const int pNum,
                 string pYear,
                 string p,
                 vector<string> ids) : 
    journalID(std::move(j_id)),
    journalName(std::move(j_name)),
    type(j_type),        
    publishNumber(pNum),
    publishYear(std::move(pYear)),
    publisher(std::move(p)),
    articlesID(std::move(ids)) {
}

Journal::~Journal() = default;

void Journal::setJournalID(const string &journalID) {
    this->journalID = journalID; 
}

string Journal::getJournalID() const {
    return this->journalID;
}

void Journal::setJournalName(const string &journalName) {
    this->journalName = journalName;
}

string Journal::getJournalName() const {
    return this->journalName;
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

void Journal::setPublishNumber(const int publishNumber) {
    this->publishNumber = publishNumber;
}

int Journal::getPublishNumber() const {
    return this->publishNumber;
}

void Journal::setPublishYear(const string &publishYear) {
    this->publishYear = publishYear;
}

string Journal::getPublishYear()const {
    return this->publishYear;
}

void Journal::setPublisher(const string &publisher) {
    this->publisher = publisher;
}

string Journal::getPublisher() const {
    return this->publisher;
}

vector<string> Journal::getArticlesID() const {
    return this->articlesID; 
}

void Journal::generateID(const int &count) {
    journalID = getType() + "-" + "Journal" + "-" + to_string(count);
}

string Journal::nextID(const int &count) const {
    return getType() + "-" + journalID + "-" + to_string(count + 1);
}
