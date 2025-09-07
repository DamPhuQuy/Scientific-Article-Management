#include "repositories/AuthorRepository.h"

#include <ranges> // for views::values

AuthorRepository::AuthorRepository(map<string, Author> &au) :
    authors(au) {}

AuthorRepository::~AuthorRepository() = default;

void AuthorRepository::setAuthorsMap(const map<string, Author> &authors) const {
    this->authors = authors; 
}

map<string, Author> AuthorRepository::getAuthorsMap() const {
    return this->authors;
}

void AuthorRepository::addAuthor(const Author &author) const {
    this->authors.insert({author.getAuthorID(), author});
}

void AuthorRepository::removeAuthor(const string &authorID) const {
    this->authors.erase(authorID);
}

Author* AuthorRepository::getAuthor(const string &authorID) const {
    if (!authors.contains(authorID)) {
        cout << "This author ID : " << authorID << " does not exist!\n";
        return nullptr;
    }
    else {
        return &authors.at(authorID);
    }
}

vector<Author> AuthorRepository::getAllAuthors() const {
    vector<Author> temp; 

    for (auto &val: authors | views::values) {
        temp.emplace_back(val);
    }

    return temp; 
}

Author AuthorRepository::input(const string &authorID, const string &newArticleID) const {
    if (auto it = this->authors.find(authorID); it != authors.end()) {
        Author author = it->second; 

        author.getArticlesID().emplace_back(newArticleID);

        return author; 
    }
    else {
        string authorName;
        string authorEmail;
        string dob;
        string country;
        int authorGender = 0; 
        vector<string> articlesID;

        cout << "Enter author name: "; getline(cin, authorName); 

        cout << "Enter author email: "; getline(cin, authorEmail); 

        cout << "Enter DOB (format dd/mm/yyyy): "; getline(cin, dob); 

        cout << "Enter author country: "; getline(cin, country); 

        cout << "Enter gender (M/F): "; 
        string temp; getline(cin, temp); 
        if (temp != "M") authorGender = 1; 

        articlesID.emplace_back(newArticleID); // add articleID to sync

        Author author(authorID, authorName, authorEmail, dob, country, authorGender, articlesID); 

        return author; 
    }
}

void AuthorRepository::showAuthorDescriptionByID(
    const map<string, Article*> &articles,
    const string &authorID)
const {
    if (const auto it = authors.find(authorID); it == authors.end()) {
        cout << "ERROR: " << authorID << " not found!"; 
        return; 
    } 
    else {
        const Author author = it->second;

        cout << "Author ID: " << authorID << "\n"; 
        cout << "Name of author: " << author.getAuthorName() << "\n"; 
        cout << "Email of author: " << author.getAuthorEmail() << "\n"; 
        cout << "Day of birth of author: " << author.getDob() << "\n"; 
        cout << "Country of author: " << author.getCountry() << "\n"; 
        cout << "Gender: " << ((author.getAuthorGender() == 0) ? "Male" : "Female") << "\n";

        const vector<string> articlesID = author.getArticlesID();
        cout << "Articles that " << author.getAuthorName() << " takes part in: \n"; 
        for (int i = 0; i < articlesID.size(); i++) {
            cout << articlesID.at(i);  
            if (i != articlesID.size() - 1) {
                cout << ", "; 
            }
        }
        cout << "\n"; 
    }
}
