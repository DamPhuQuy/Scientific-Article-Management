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
    auto it = this->authors.find(authorID); 
        
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

Author AuthorRepository::input(const int &authorID, const int &newArticleID) {
    auto it = this->authors.find(authorID); 

    if (it != authors.end()) {
        Author author = it->second; 

        author.getArticlesID().push_back(newArticleID); 

        return author; 
    }
    else {
        string authorName;
        string authorEmail;
        string dob;
        string country;
        int authorGender = 0; 
        vector<int> articlesID; 

        cout << "Enter author name: "; getline(cin, authorName); 

        cout << "Enter author email: "; getline(cin, authorEmail); 

        cout << "Enter DOB (format dd/mm/yyyy): "; getline(cin, dob); 

        cout << "Enter author country: "; getline(cin, country); 

        cout << "Enter gender (M/F): "; 
        string temp; getline(cin, temp); 
        if (temp != "M") authorGender = 1; 

        articlesID.push_back(newArticleID); 

        Author author(authorID, authorName, authorEmail, dob, country, authorGender, articlesID); 

        return author; 
    }
}