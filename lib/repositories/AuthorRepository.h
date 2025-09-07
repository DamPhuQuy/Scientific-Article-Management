#pragma once

#include <map>
#include <iostream> 
#include "models/Author.h"
#include "utilities/IOHelper.h" 
#include "utilities/IDManager.h"
#include "models/Article.h"
#include "models/Journal.h"

using namespace std; 

class AuthorRepository {
private: 
    map<string, Author> &authors;
    shared_ptr<ArticleRepository*> articleRepos;
public:
    explicit AuthorRepository(map<string, Author>& au);
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