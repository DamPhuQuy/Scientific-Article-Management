#include <utility>
#include "models/Author.h"

using namespace std; 

Author::Author(): authorGender(0) {
}

Author::Author(string a_id, 
               string au_name,
               string au_email,
               string au_dob,
               string au_country,
               const int au_gender,
               vector<string> ids) :
    authorID(std::move(a_id)), authorName(std::move(au_name)), authorEmail(std::move(au_email)), dob(std::move(au_dob)), country(std::move(au_country)),
    authorGender(au_gender), articlesID(std::move(ids)) {
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

void Author::setAuthorID(const string &authorID) {
    this->authorID = authorID;
}

string Author::getAuthorID() const {
    return this->authorID;
}

void Author::setAuthorName(const string &authorName) {
    this->authorName = authorName;
}

string Author::getAuthorName() const {
    return this->authorName;
}

void Author::setAuthorEmail(const string &authorEmail) {
    this->authorEmail = authorEmail;
}

string Author::getAuthorEmail() const {
    return this->authorEmail;
}

void Author::setDob(const string &dob) {
    this->dob = dob;
}

string Author::getDob() const {
    return this->dob;
}

void Author::setCountry(const string &country) {
    this->country = country;
}

string Author::getCountry() const {
    return this->country;
}

void Author::setAuthorGender(const int authorGender) {
    this->authorGender = authorGender;
}

int Author::getAuthorGender() const {
    return this->authorGender;
}

vector<string> Author::getArticlesID() const{
    return this->articlesID;
}

void Author::generateID(int count) {
    this->authorID = "Au-" + to_string(count); 
}

string Author::nextID(int count) {
    return "Au-" + to_string(count + 1);
}
