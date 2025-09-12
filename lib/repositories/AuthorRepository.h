#pragma once

#include <map>
#include <iostream> 
#include <repositories/DataWrapper.h>
#include "utilities/IOHelper.h" 
#include "utilities/IDManager.h"


using namespace std; 

class AuthorRepository {
private: 
    DataWrapper &data;
public:
    explicit AuthorRepository(DataWrapper &dataWrapper);
    ~AuthorRepository(); 

    void setAuthorsMap(const map<string, Author> &authors) const;
    [[nodiscard]] map<string, Author> getAuthorsMap() const;

    void addAuthor(const Author &author) const;
    void removeAuthor(const string &authorID) const;

    [[nodiscard]] Author* getAuthor(const string &authorID) const;
    [[nodiscard]] vector<Author> getAllAuthors() const;

    [[nodiscard]] Author input(const string &authorID, const string &newArticleID) const;

    void showAuthorDescriptionByID(const map<string, Article*> &articles, const string &authorID) const;
}; 