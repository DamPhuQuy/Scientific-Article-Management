#include "Journal.h"

Journal::Journal() {}

Journal::Journal(int journalID, 
                 string journalName,
                 journalTypes types, 
                 int publishID, 
                 string publishName,
                 string publishYear,
                 string publisher) {
    this->journalID = journalID;
    this->journalName = journalName;
    this->types = types;
    this->publishID = publishID;
    this->publishName = publishName;
    this->publishYear = publishYear;
    this->publisher = publisher;
}

Journal::Journal(const Journal& j) {
    this->journalID = j.journalID;
    this->journalName = j.journalName;
    this->types = j.types;
    this->publishID = j.publishID;
    this->publishName = j.publishName;
    this->publishYear = j.publishYear;
    this->publisher = j.publisher;
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

void Journal::setJournalTypes(journalTypes types) {
    this->types = types;
}

journalTypes Journal::getJournalTypes() {
    return this->types;
}

void Journal::setPublishID(int publishID) {
    this->publishID = publishID;
}

int Journal::getPublishID() {
    return this->publishID;
}

void Journal::setPublishName(string publishName) {
    this->publishName = publishName;
}

string Journal::getPublishName() {
    return this->publishName;
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


