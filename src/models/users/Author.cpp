#include <utility>
#include "models/Author.h"

using namespace std; 

Author::Author(): authorGender(0) {
}

Author::Author(const string &a_id,
               const string &au_name,
               const string &au_email,
               const string &au_dob,
               const string &au_country,
               const int& au_gender,
               const vector<string> &ids) :
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

Author::~Author() = default;

void Author::setAuthorID(const string &au_id) {
    this->authorID = au_id;
}

string Author::getAuthorID() const {
    return this->authorID;
}

void Author::setAuthorName(const string &au_name) {
    this->authorName = au_name;
}

string Author::getAuthorName() const {
    return this->authorName;
}

void Author::setAuthorEmail(const string &au_email) {
    this->authorEmail = au_email;
}

string Author::getAuthorEmail() const {
    return this->authorEmail;
}

void Author::setDob(const string &birth) {
    this->dob = birth;
}

string Author::getDob() const {
    return this->dob;
}

void Author::setCountry(const string &c) {
    this->country = c;
}

string Author::getCountry() const {
    return this->country;
}

void Author::setAuthorGender(const int au_g) {
    this->authorGender = au_g;
}

int Author::getAuthorGender() const {
    return this->authorGender;
}

vector<string> Author::getArticlesID() const{
    return this->articlesID;
}

string Author::getTypeName() {
    return "Au";
}