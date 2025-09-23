#pragma once

#include <unordered_map>
#include <string>
#include "models/Author.h"

using namespace std;

class AuthorRepository {
private:
    unordered_map<string, Author> authors;
public:
    explicit AuthorRepository(const unordered_map<string, Author> &authors);
    ~AuthorRepository() = default;

    void addAuthor(const Author& author);
    Author getAuthorById(const string& id) const;
    vector<Author> getAllAuthors() const;

    void updateAuthor(const Author& author);
    void deleteAuthor(const string& id); 

    vector<Author> findByName(const string& keyword) const;
};
