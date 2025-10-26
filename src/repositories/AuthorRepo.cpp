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

string AuthorRepo::liveSearchByName() const {
    auto getName = [](const Author& au) { return au.getFullName(); }; 

    auto printAuthor = [](const Author& au, bool highlight) -> void{
        if (highlight)
            cout << "-> [" << au.getFullName() << "] (" << au.getCountry() << ", " << au.getFieldOfStudy() << ")\n";
        else
            cout << "    " << "[" << au.getFullName() << "] (" << au.getCountry() << ", " << au.getFieldOfStudy() << ")\n";
    };

    return SearchByRegex::liveSearch<Author>(
        this->authors_container, 
        getName,
        printAuthor
    ); 
}

string AuthorRepo::liveSearchByCountry() const {
    auto getCountry = [](const Author& au) { return au.getCountry(); }; 

    auto printAuthor = [](const Author& au, bool highlight) -> void {
        if (highlight)
            cout << "-> " << "[" << au.getCountry() << "] (" << au.getFullName() << ", " << au.getFieldOfStudy() << ")\n";
        else
            cout << "    " << "[" << au.getCountry() << "] (" << au.getFullName() << ", " << au.getFieldOfStudy() << ")\n";
    };

    return SearchByRegex::liveSearch<Author>(
        this->authors_container,
        getCountry,
        printAuthor
    );
}

string AuthorRepo::liveSearchByFieldOfStudy() const {
    auto getField = [](const Author& au) { return au.getFieldOfStudy(); }; 

    auto printAuthor = [](const Author& au, bool highlight) -> void {
        if (highlight) 
            cout << "-> [" << au.getFieldOfStudy() << "] (" << au.getFullName() << ", " << au.getCountry() << ")\n";
        else
            cout << "    " << "[" << au.getFieldOfStudy() << "] (" << au.getFullName() << ", " << au.getCountry() << ")\n";
    };

    return SearchByRegex::liveSearch<Author>(
        this->authors_container,
        getField,
        printAuthor
    );
}

void AuthorRepo::searchAuthorMenu()
{
    int choice;
    do {
        system("cls");
        cout << "\n===== Search Authors =====\n";
        cout << "     1. Search by Name\n";
        cout << "     2. Search by Country\n";
        cout << "     3. Search by Field of Study\n";
        cout << "     0. Back to main menu\n";
        cout << "---------------------------\n";
        cout << "Your choice: ";
        cin >> choice; cin.ignore(); 

        switch (choice) {
        case 1:
            liveSearchByName();
            break;
        case 2:
            liveSearchByCountry();
            break;
        case 3:
            liveSearchByFieldOfStudy();
            break;
        case 0:
            cout << "Returning to main menu...\n";
            break;
        default:
            cout << "Invalid option. Try again.\n";
        }
        if (choice != 0) {
            cout << "\nPress any key to continue...";
            _getch();
        }
    } while (choice != 0);
}
