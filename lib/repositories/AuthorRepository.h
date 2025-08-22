#pragma once

#include <unordered_map>
#include <iostream> 
#include "lib/models/Author.h"

class AuthorRepository {
private: 
    unordered_map<int, Author> authors; 
public: 
    AuthorRepository(); 
    AuthorRepository(const unordered_map<int, Author>& authors); 
    AuthorRepository(const AuthorRepository &current); 
    ~AuthorRepository(); 

    void setAuthorsMap(const unordered_map<int, Author> &authors); 
    unordered_map<int, Author> getAuthorsMap() const; 

    void addAuthor(const Author &author); 
    void removeAuthor(int authorID);

    Author getAuthor(int authorID) const; 
    vector<Author> getAllAuthors() const; 
};