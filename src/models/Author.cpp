#include "models/Author.h" 

using namespace std; 

Author::Author() :
    authorID(""), authorName(""), authorEmail(""), dob(""), country(""), 
    authorGender(0), articlesID({}) {
}

Author::Author(string a_id, 
               string au_name,
               string au_email,
               string au_dob,
               string au_country,
               int au_gender,
               vector<string> ids) :
    authorID(a_id), authorName(au_name), authorEmail(au_email), dob(au_dob), country(au_country), 
    authorGender(au_gender), articlesID(ids) {
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

string Author::getAuthorID() const {
    return this->authorID;
}

void Author::setAuthorName(string authorName) {
    this->authorName = authorName;
}

string Author::getAuthorName() const {
    return this->authorName;
}

void Author::setAuthorEmail(string authorEmail) {
    this->authorEmail = authorEmail;
}

string Author::getAuthorEmail() const {
    return this->authorEmail;
}

void Author::setDob(string dob) {
    this->dob = dob;
}

string Author::getDob() const {
    return this->dob;
}

void Author::setCountry(string country) {
    this->country = country;
}

string Author::getCountry() const {
    return this->country;
}

void Author::setAuthorGender(int authorGender) {
    this->authorGender = authorGender;
}

int Author::getAuthorGender() const {
    return this->authorGender;
}

vector<string> Author::getArticlesID() const{
    return this->articlesID;
}


