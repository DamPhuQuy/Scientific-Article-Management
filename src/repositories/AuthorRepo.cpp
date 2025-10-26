#include "AuthorRepo.h"
#include "SearchByRegex.h"
#include <iostream> 
#include <regex> 
#include <functional>
#include <conio.h> // getch()

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

// ---------------- Search functions ---------------- //

void AuthorRepo::liveSearchByName() const {
    auto getName = [](const Author& au) { return au.getFullName(); }; 

    auto printAuthor = [](const Author& au, bool highlight) {
        if (highlight)
            cout << "-> [" << au.getFullName() << "] (" << au.getCountry() << ", " << au.getFieldOfStudy() << ")\n";
        else
            cout << "    " << "[" << au.getFullName() << "] (" << au.getCountry() << ", " << au.getFieldOfStudy() << ")\n";
    };

    SearchByRegex::liveSearch<Author>(
        this->authors_container, 
        getName,
        printAuthor
    ); 
}

void AuthorRepo::liveSearchByCountry() const {
    auto getCountry = [](const Author& au) { return au.getCountry(); }; 

    auto printAuthor = [](const Author& au, bool highlight) {
        if (highlight)
            cout << "-> [" << au.getCountry() << "] (" << au.getFullName() << ", " << au.getFieldOfStudy() << ")\n";
        else
            cout << "    " << "[" << au.getCountry() << "] (" << au.getFullName() << ", " << au.getFieldOfStudy() << ")\n";
    };

    SearchByRegex::liveSearch<Author>(
        this->authors_container,
        getCountry,
        printAuthor
    );
}

void AuthorRepo::liveSearchByFieldOfStudy() const {
    auto getField = [](const Author& au) { return au.getFieldOfStudy(); }; 

    auto printAuthor = [](const Author& au, bool highlight) {
        if (highlight) 
            cout << "-> [" << au.getFieldOfStudy() << "] (" << au.getFullName() << ", " << au.getCountry() << ")\n";
        else
            cout << "    " << "[" << au.getFieldOfStudy() << "] (" << au.getFullName() << ", " << au.getCountry() << ")\n";
    };

    SearchByRegex::liveSearch<Author>(
        this->authors_container,
        getField,
        printAuthor
    );
}
