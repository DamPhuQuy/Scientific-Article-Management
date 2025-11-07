#include "AuthorRepo.h"
#include "SearchByRegex.h"
#include "MenuUtilities.h"
#include <iostream>
#include <regex>
#include <functional>
#include <conio.h> // getch()
#include <thread>           // sleep_for
#include <chrono>           // milliseconds

using namespace std;
using namespace std::this_thread;
using namespace std::chrono_literals;

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

unordered_map<string, Author> &AuthorRepo::getAuthorContainer()
{
    return this->authors_container;
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

string AuthorRepo::searchAuthorMenu() {
    vector<string> options = {
        "Search by Name",
        "Search by Country",
        "Search by Field of Study",
        "Back to Main Menu"
    };

    while (true) {
        int choice = MenuUtilities::general_menu(options, "Search Authors", true);

        if (choice == -1) {
            cout << "Returning to main menu...\n";
            sleep_for(800ms);
            break;
        }

        string selectedId;

        switch (choice) {
            case 0: {
                string selectedId = liveSearchByName();
                if (!selectedId.empty()) {
                    cout << "\nSelected author ID: " << selectedId << "\n";
                    system("pause");
                    return selectedId;
                }
                break;
            }
            case 1: {
                string selectedId = liveSearchByCountry();
                if (!selectedId.empty()) {
                    cout << "\nSelected author ID: " << selectedId << "\n";
                    system("pause");
                    return selectedId;
                }
                break;
            }
            case 2: {
                string selectedId = liveSearchByFieldOfStudy();
                if (!selectedId.empty()) {
                    cout << "\nSelected author ID: " << selectedId << "\n";
                    system("pause");
                    return selectedId;
                }
                break;
            }
            case 3: // Back
                cout << "Returning to main menu...\n";
                sleep_for(800ms);
                return "";
            default:
                break;
        }
    }
    return "";
}

void AuthorRepo::createAuthor()
{
    Author newAuthor;
    newAuthor.inputFromUser();
    add(newAuthor);
}
