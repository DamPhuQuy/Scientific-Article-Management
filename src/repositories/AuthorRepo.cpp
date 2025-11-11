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

string AuthorRepo::findAuthorIdByName(const string &name) const
{
    for (const auto& [id, author] : authors_container) {
        if (author.getFullName() == name)
            return id;
    }
    return "";
}

void AuthorRepo::createAuthor()
{
    Author newAuthor;
    newAuthor.inputFromUser();
    add(newAuthor);
}

void AuthorRepo::updateName(const string& id) {
    auto it = this->authors_container.find(id);
    if (it == this->authors_container.end()) {
        // cout << "This id does not exist!";
        return;
    } else {
        cout << "Enter new name: ";
        string name;
        getline(cin, name);
        it->second.setFullName(name);
        json data;
        for (auto& [thisid, author] : this->authors_container) {
            data.push_back(author.to_json());
        }
        ofstream outfile("../../data/authors_dataset.json");
        outfile << data.dump(4);
        outfile.close();
    }
}

void AuthorRepo::updateCountry(const string& id) {
    auto it = this->authors_container.find(id);
    if (it == this->authors_container.end()) {
        // cout << "This id does not exist!";
        return;
    } else {
        cout << "Enter new country: ";
        string country;
        getline(cin, country);
        it->second.setCountry(country);
        json data;
        for (auto& [thisid, author] : this->authors_container) {
            data.push_back(author.to_json());
        }
        ofstream outfile("../../data/authors_dataset.json");
        outfile << data.dump(4);
        outfile.close();
    }
}

void AuthorRepo::updateFieldOfStudy(const string& id) {
    auto it = this->authors_container.find(id);
    if (it == this->authors_container.end()) {
        // cout << "This id does not exist!";
        return;
    } else {
        cout << "Enter new field of study: ";
        string fieldofstudy;
        getline(cin, fieldofstudy);
        it->second.setFieldOfStudy(fieldofstudy);
        json data;
        for (auto& [thisid, author] : this->authors_container) {
            data.push_back(author.to_json());
        }
        ofstream outfile("../../data/authors_dataset.json");
        outfile << data.dump(4);
        outfile.close();
    }
}

void AuthorRepo::updateTotalOfPublications(const string& id) {
    auto it = this->authors_container.find(id);
    if (it == this->authors_container.end()) {
        // cout << "This id does not exist!";
        return;
    } else {
        cout << "Enter new total of publications: ";
        string pubs;
        getline(cin, pubs);
        it->second.setTotalPublications(stoi(pubs));
        json data;
        for (auto& [thisid, author] : this->authors_container) {
            data.push_back(author.to_json());
        }
        ofstream outfile("../../data/authors_dataset.json");
        outfile << data.dump(4);
        outfile.close();
    }
}

void AuthorRepo::removeAuthor(const string & id)
{
    auto it = this->authors_container.find(id);
    if (it == this->authors_container.end()) {
        return;
    } else {
        this->authors_container.erase(id);
        json data;
        for (auto& [thisid, author] : this->authors_container) {
            data.push_back(author.to_json());
        }
        ofstream outfile("../../data/authors_dataset.json");
        outfile << data.dump(4);
        outfile.close();
    }
}
