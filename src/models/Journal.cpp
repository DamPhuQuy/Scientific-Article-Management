#include "Journal.h"

Journal::Journal() {}

Journal::Journal(int journalID, string journalName, journalTypes types, int publishNumber, string publishYear, string publisher) {
    this->journalID = journalID;
    this->journalName = journalName;
    this->types = types;
    this->publishNumber = publishNumber;
    this->publishYear = publishYear;
    this->publisher = publisher;
}

Journal::Journal(const Journal &j) {
    this->journalID = j.journalID;
    this->journalName = j.journalName;
    this->types = j.types;
    this->publishNumber = j.publishNumber;
    this->publishYear = j.publishYear;
    this->publisher = j.publisher;
    this->articles = j.articles;
}

Journal::~Journal() {}

void Journal::setJournalID(int journalID) {
    this->journalID = journalID;
}

int Journal::getJournalID() {
    return this->journalID;
}

void Journal::setJournalName(string journalName) {
    this->journalName = journalName;
}

string Journal::getJournalName() {
    return this->journalName;
}

void Journal::setTypes(journalTypes types) {
    this->types = types;
}

journalTypes Journal::getTypes() {
    return this->types;
}

void Journal::setPublishNumber(int publishNumber) {
    this->publishNumber = publishNumber;
}

int Journal::getPublishNumber() {
    return this->publishNumber;
}

void Journal::setPublishYear(string publishYear) {
    this->publishYear = publishYear;
}

string Journal::getPublishYear() {
    return this->publishYear;
}

void Journal::setPublisher(string publisher) {
    this->publisher = publisher;
}

string Journal::getPublisher() {
    return this->publisher;
}

void Journal::addArticle(const Article &article) {
    articles.push_back(article);
}

vector<Article> Journal::getArticles() const {
    return articles;
}

