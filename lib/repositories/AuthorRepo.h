#pragma once
#include "Author.h" 
#include <vector>
#include <unordered_map>

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
    void remove(const Author& au);
    
    // search functions
    
    string liveSearchByName() const;
    string liveSearchByCountry() const; 
    string liveSearchByFieldOfStudy() const; 
};