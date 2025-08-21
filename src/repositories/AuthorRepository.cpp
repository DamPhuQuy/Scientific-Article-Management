#include "lib/repositories/AuthorRepository.h"

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
    this->authors.insert({author.getAuthorID, author}); 
}

void AuthorRepository::removeAuthor(int authorID) {
    this->authors.erase(authorID); 
}

Author AuthorRepository::getAuthor(int authorID) {
    auto it = authors.find(authorID); 
        
    if (it == authors.end()) {
        cout << "Not found\n"; 
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
