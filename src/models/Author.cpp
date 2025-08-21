#include "lib/models/Author.h" 

using namespace std; 

Author::Author() {} 

Author::Author(int authorID, string authorName, string authorEmail, string dob, string country, int authorGender, vector<int> articlesID) {
    this->authorID = authorID;
    this->authorName = authorName;
    this->authorEmail = authorEmail;
    this->dob = dob;
    this->country = country;
    this->authorGender = authorGender;
    this->articlesID = articlesID; 
}

Author::Author(const Author &a) {
    this->authorID = a.authorID;
    this->authorName = a.authorName;
    this->authorEmail = a.authorEmail;
    this->dob = a.dob;
    this->country = a.country;
    this->authorGender = a.authorGender;
    this->articlesID = a.articlesID;
}

Author::~Author() {}

void Author::setAuthorID(int authorID) {
    this->authorID = authorID;
}

int Author::getAuthorID() {
    return this->authorID;
}

void Author::setAuthorName(string authorName) {
    this->authorName = authorName;
}

string Author::getAuthorName() {
    return this->authorName;
}

void Author::setAuthorEmail(string authorEmail) {
    this->authorEmail = authorEmail;
}

string Author::getAuthorEmail() {
    return this->authorEmail;
}

void Author::setDob(string dob) {
    this->dob = dob;
}

string Author::getDob() {
    return this->dob;
}

void Author::setCountry(string country) {
    this->country = country;
}

string Author::getCountry() {
    return this->country;
}

void Author::setAuthorGender(int authorGender) {
    this->authorGender = authorGender;
}

int Author::getAuthorGender() {
    return this->authorGender;
}




