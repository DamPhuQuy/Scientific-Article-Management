#pragma once

class AuthorRepository {
private:
    vector<Author> authors;
public:
    AuthorRepository() = default;
    ~AuthorRepository() = default;

    void addAuthor(const Author& author);
    Author getAuthorById(const string& id) const;
    vector<Author> getAllAuthors() const;

    void updateAuthor(const Author& author);
    void deleteAuthor(const string& id); 

    vector<Author> findByName(const string& keyword) const;

    vector<Author> findByEmail(const string& email) const;

};
