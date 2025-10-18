#include "Author.h"
#include <iostream> 

using namespace std; 

Author::Author(string id, string fullName, string country, string fieldOfStudy, int totalPublications)
: id(id), 
  fullName(fullName), 
  country(country), 
  fieldOfStudy(fieldOfStudy), 
  totalPublications(totalPublications)
{
}

Author::Author(const Author& other)
: id(other.id), 
  fullName(other.fullName), 
  country(other.country), 
  fieldOfStudy(other.fieldOfStudy), 
  totalPublications(other.totalPublications) 
{
}

// getters

string Author::getId() const {
    return this->id;
}
string Author::getFullName() const {
    return this->fullName;
}
string Author::getCountry() const {
    return this->country;
}
string Author::getFieldOfStudy() const {
    return this->fieldOfStudy;
}
int Author::getTotalPublications() const {
    return this->totalPublications;
}

// setters

void Author::setId(const string& newId) {
        this->id = newId;
}
void Author::setFullName(const string& newFullName) {
    this->fullName = newFullName;
}
void Author::setCountry(const string& newCountry) {
    this->country = newCountry;
}
void Author::setFieldOfStudy(const string& newFieldOfStudy) {
    this->fieldOfStudy = newFieldOfStudy;
}
void Author::setTotalPublications(int newTotal) {
    this->totalPublications = newTotal;
}

void Author::showAuthorDetails() const {
    cout << "Author ID: " << this->id << "\n";
    cout << "Full Name: " << this->fullName << "\n";
    cout << "Country: " << this->country << "\n";
    cout << "Field of Study: " << this->fieldOfStudy << "\n";
    cout << "Total Publications: " << this->totalPublications << "\n";
    cout << "---------------------------------------" << endl;
}