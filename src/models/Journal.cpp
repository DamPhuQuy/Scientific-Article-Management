#include <utility>

#include "models/Journal.h"

using namespace std;


Journal::Journal(string j_id, string j_name, const Type j_type, const int pNum, const int pYear, string p, const vector<string> &ids) :
    journalID(std::move(j_id)), journalName(std::move(j_name)), type(j_type), publishNumber(pNum), publishYear(pYear), publisher(std::move(p)), articlesID(ids){
}

Journal::~Journal() = default;

void Journal::setJournalID(const string &j_id) {
    this->journalID = j_id;
}

string Journal::getJournalID() const {
    return this->journalID;
}

void Journal::setJournalName(const string &j_name) {
    this->journalName = j_name;
}

string Journal::getJournalName() const {
    return this->journalName;
}

void Journal::setPublishNumber(const int pNum) {
    this->publishNumber = pNum;
}

int Journal::getPublishNumber() const {
    return this->publishNumber;
}

void Journal::setPublishYear(const int &pYear) {
    this->publishYear = pYear;
}

int Journal::getPublishYear() const {
    return this->publishYear;
}

void Journal::setPublisher(const string &p) {
    this->publisher = p;
}

string Journal::getPublisher() const {
    return this->publisher;
}

vector<string> Journal::getArticlesID() const {
    return this->articlesID; 
}

string Journal::getTypeName() const {
    return "J";
}