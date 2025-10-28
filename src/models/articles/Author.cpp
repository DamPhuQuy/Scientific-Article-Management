#include "Author.h"
#include <iostream> 
#include <limits>

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
    cout << "Author:\n"
         << "  ID                : " << id               << '\n'
         << "  Full name         : " << fullName         << '\n'
         << "  Country           : " << country          << '\n'
         << "  Field of study    : " << fieldOfStudy     << '\n'
         << "  Total publications: " << totalPublications<< '\n';
}

void Author::inputFromUser()
{
    cout << "=== Enter Author Details ===\n";
    
    auto readLine = [](const string& prompt) -> string {
        string line;
        cout << prompt;
        getline(cin >> ws, line);   // skip leading whitespace
        return line;
    };
    // Helper lambda for integer input with validation
    auto readInt = [](const string& prompt) -> int {
        int value;
        while (true) {
            cout << prompt;
            if (cin >> value) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return value;
            }
            cout << "  ** Invalid number, try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    };

    this->fullName         = readLine("Full name        : ");
    this->country          = readLine("Country          : ");
    this->fieldOfStudy     = readLine("Field of study   : ");
    this->totalPublications = readInt("Total publications: ");
    cout << "-----------------------------\n";
}