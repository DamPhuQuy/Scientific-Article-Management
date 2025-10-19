#include "AuthorRepo.h"
#include <iostream> 

AuthorRepo::AuthorRepo(unordered_map<string, Author> au_con)
: authors_container(au_con)
{
}

void AuthorRepo::add(const Author &au)
{
    string id = au.getId(); 
    auto it = this->authors_container.find(id); 
    if (it != this->authors_container.end()) {
        cout << "Id nay da ton tai!" << endl; 
        return; 
    }
    else {
        this->authors_container[id] = au; 
    }
}

void AuthorRepo::remove(const Author &au)
{
    string id = au.getId(); 
    auto it = this->authors_container.find(id); 
    if (it != this->authors_container.end()) {
        this->authors_container.erase(id); 
    } 
    else {
        cout << "Id nay khong ton tai!" << endl; 
    }
}