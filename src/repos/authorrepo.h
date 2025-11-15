#pragma once
#include "../models/author.h"

using namespace std;

class AuthorRepo {
private:
    unordered_map<string, Author> authors_container;
public:
    AuthorRepo() = default;
    explicit AuthorRepo(unordered_map<string, Author> au_con);

    ~AuthorRepo() = default;

    // utilities
    void add(const Author& au);
    void remove(const string& id);

    unordered_map<string, Author>& getAuthorContainer();

    // Import and Export
    void load();
    void save();

    // search functions
    Author findById(const string& id) const;
    Author findByName(const string& name) const;
    Author findByCountry(const string& coutry) const;

    // filter
    vector<Author> filterByField(const string& field) const;
    vector<Author> filterByMinPublications(int minPubs) const;

    // sort
    vector<Author> sortedByName(bool ascending=true) const;
    vector<Author> sortedByPublications(bool ascending=true) const;

    // update
    void updateName(const string& id, const string& name);
    void updateCountry(const string& id, const string& country);
    void updateFieldOfStudy(const string& id, const string& field);
    void updateTotalOfPublications(const string& id, const int& pubs);

    // statistics
    int count() const;
};
