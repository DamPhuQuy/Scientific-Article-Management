#include "repositories/AuthorRepository.h"

AuthorRepository::AuthorRepository() {}  

AuthorRepository::AuthorRepository(unordered_map<int, Author> *au) :
    authors(au) {} 

AuthorRepository::AuthorRepository(const AuthorRepository &current) {
    this->authors = current.authors; 
}

AuthorRepository::~AuthorRepository() {}

void AuthorRepository::setAuthorsMap(unordered_map<int, Author> *authors) {
    this->authors = authors; 
}

unordered_map<int, Author> AuthorRepository::getAuthorsMap() const {
    return *(this->authors);
}

void AuthorRepository::addAuthor(const Author &author) {
    this->authors->insert({author.getAuthorID(), author}); 
}

void AuthorRepository::removeAuthor(int authorID) {
    this->authors->erase(authorID); 
}

Author AuthorRepository::getAuthor(int authorID) const {
    auto it = this->authors->find(authorID); 
        
    if (it == authors->end()) {
        cout << "ERROR: " << authorID << " not found!\n"; 
        return Author(); 
    } else {
        return it->second; 
    }
}

vector<Author> AuthorRepository::getAllAuthors() const {
    vector<Author> temp; 

    for (auto it = authors->begin(); it != authors->end(); it++) {
        temp.push_back(it->second);
    }

    return temp; 
}

Author AuthorRepository::input(const int &authorID, const int &newArticleID) {
    auto it = this->authors->find(authorID); 

    if (it != authors->end()) {
        Author author = it->second; 

        author.getArticlesID().push_back(newArticleID); 

        return author; 
    }
    else {
        string authorName;
        string authorEmail;
        string dob;
        string country;
        int authorGender = 0; 
        vector<int> articlesID; 

        cout << "Enter author name: "; getline(cin, authorName); 

        cout << "Enter author email: "; getline(cin, authorEmail); 

        cout << "Enter DOB (format dd/mm/yyyy): "; getline(cin, dob); 

        cout << "Enter author country: "; getline(cin, country); 

        cout << "Enter gender (M/F): "; 
        string temp; getline(cin, temp); 
        if (temp != "M") authorGender = 1; 

        articlesID.push_back(newArticleID); // add articleID to sync

        Author author(authorID, authorName, authorEmail, dob, country, authorGender, articlesID); 

        return author; 
    }
}

void AuthorRepository::showAuthorDescriptionByID(DataWrapper &dw, const int &authorID) {
    auto it = authors->find(authorID); 

    if (it == authors->end()) {
        cout << "ERROR: " << authorID << " not found!"; 
        return; 
    } 
    else {
        Author author = it->second; 

        cout << "Author ID: " << authorID << "\n"; 
        cout << "Name of author: " << author.getAuthorName() << "\n"; 
        cout << "Email of author: " << author.getAuthorEmail() << "\n"; 
        cout << "Day of birth of author: " << author.getDob() << "\n"; 
        cout << "Country of author: " << author.getCountry() << "\n"; 
        cout << "Gender: " << ((author.getAuthorGender() == 0) ? "Male" : "Female") << "\n";

        vector<int> articlesID = author.getArticlesID(); 
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