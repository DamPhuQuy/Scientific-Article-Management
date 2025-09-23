#include "repositories/AuthorRepository.h"
#include <iostream>
#include <algorithm>
#include <regex>

AuthorRepository::AuthorRepository(const unordered_map<string, Author> &authors) : authors(authors) {

}

void AuthorRepository::addAuthor(const Author& author) {
    const string authorID = author.getAuthorID();

    if (const auto it = authors.find(authorID); it == authors.end()) {
        authors[authorID] = author;
    } else {
        cout << "This authorID existed";
    }
}

Author AuthorRepository::getAuthorById(const string& id) const {
    if (const auto it = authors.find(id); it == authors.end()) {
        cout << "This authorID doesn't exist";
        return {};
    } else {
        return it->second;
    }
}

vector<Author> AuthorRepository::getAllAuthors() const {
    vector<Author> authors;
    ranges::for_each(this->authors, [&](const pair<string, Author> &element) -> void {
        authors.push_back(element.second);
    });
    return authors;
}

void AuthorRepository::updateAuthor(const Author& author) {
    const string authorID = author.getAuthorID();
    if (const auto it = authors.find(authorID); it == authors.end()) {
        cout << "This authorID doesn't exist";
        return;
    }
    else {
        it->second = author;
    }
}

void AuthorRepository::deleteAuthor(const string& id) {
    if (const auto it = authors.find(id); it == authors.end()) {
        cout << "This authorID doesn't exist";
        return;
    } else {
        authors.erase(it);
    }
}

vector<Author> AuthorRepository::findByName(const string &keyword) const {
    vector<Author> result;

    const regex pattern(keyword, regex_constants::icase);

    ranges::for_each(this->authors, [&](const pair<string, Author> &element) -> void {
        if (regex_search(element.second.getAuthorName(), pattern)) {
            result.push_back(element.second);
        }
    });

    return result;
}
