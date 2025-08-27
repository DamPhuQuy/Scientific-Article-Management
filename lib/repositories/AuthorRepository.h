#pragma once

#include <unordered_map>
#include <iostream> 
#include "models/Author.h"
#include "utilities/IOHelper.h" 
#include "utilities/IDManager.h"

using namespace std; 

class AuthorRepository {
private: 
    unordered_map<int, Author> *authors; 
public: 
    AuthorRepository(); 
    AuthorRepository(unordered_map<int, Author>* au); 
    AuthorRepository(const AuthorRepository &current); 
    ~AuthorRepository(); 

    void setAuthorsMap(unordered_map<int, Author> *authors); 
    unordered_map<int, Author> getAuthorsMap() const; 

    void addAuthor(const Author &author); 
    void removeAuthor(int authorID);

    Author getAuthor(int authorID) const; 
    vector<Author> getAllAuthors() const; 

    Author input(const int &authorID, const int &newArticleID); 

    void showAuthorDescriptionByID(DataWrapper &dw, const int &authorID); 
}; 