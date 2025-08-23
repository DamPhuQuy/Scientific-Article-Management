#include "repositories/AuthorRepository.h"

AuthorRepository::AuthorRepository() {}  

AuthorRepository::AuthorRepository(const unordered_map<int, Author> &authors) {
    this->authors = authors; 
}

AuthorRepository::AuthorRepository(const AuthorRepository &current) {
    this->authors = current.getAuthorsMap(); 
}

AuthorRepository::~AuthorRepository() {}

void AuthorRepository::setAuthorsMap(const unordered_map<int, Author> &authors) {
    this->authors = authors; 
}  

unordered_map<int, Author> AuthorRepository::getAuthorsMap() const {
    return this->authors;
}

void AuthorRepository::addAuthor(const Author &author) {
    this->authors.insert({author.getAuthorID(), author}); 
}

void AuthorRepository::removeAuthor(int authorID) {
    this->authors.erase(authorID); 
}

Author AuthorRepository::getAuthor(int authorID) const {
    auto it = authors.find(authorID); 
        
    if (it == authors.end()) {
        cout << "ERROR: " << authorID << " not found!\n"; 
        return Author(); 
    } else {
        return it->second; 
    }
}

vector<Author> AuthorRepository::getAllAuthors() const {
    vector<Author> temp; 

    for (auto it = authors.begin(); it != authors.end(); it++) {
        temp.push_back(it->second);
    }

    return temp; 
}

/* Override */
template<>
Author AuthorRepository::input<Author, int>(DataWrapper &data, const int &id) { 
    cout << "Choose available Author ID or create a new one (enter 0): ";
    int authorID; cin >> authorID; 
    if (authorID == 0) {
        authorID = IDManager::generateNextID<Author>(*data.authors); // real instance

        string authorName, authorEmail, dob, country; 
        int authorGender = 0;

        cout << "Enter author name: "; 
        getline(cin, authorName); 
        
        cout << "Enter authorEmail: "; 
        getline(cin, authorEmail); 

        cout << "Enter DOB (format: dd/mm/yyyy): "; 
        getline(cin, dob); 

        cout << "Enter country: "; 
        getline(cin, country); 

        cout << "Enter gender (M/F): "; 
        string gender; getline(cin, gender); 
        if (gender != "M") authorGender = 1;  

        vector<int> articles; 

        Author newAuthor(authorID, authorName, authorEmail, dob, country, authorGender, articles);
        return newAuthor; 
    } else {
        return Author(); 
    }
}