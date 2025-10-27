#pragma once 
#include "RepositoryManager.h"
#include "UUID_Generator.h" 

class ArticleService {
private:
    RepositoryManager& repo; 
public:
    ArticleService(RepositoryManager& r) : repo(r) {}

    Article createArticle() {
        Article* article;

        inputAuthors(article);    // xử lý liên kết với Author
        return article;
    }

private:
    void inputAuthors(Article* article) {
        Article* new_article; 

        cout << "Enter title of article: ";
        string title; getline(cin, title);

        cout << "Enter abstract of article: ";
        string abstract; getline(cin, abstract);

        cout << "Enter the venue of article: ";
        string venue; getline(cin, venue);

        int year = 0; 
        do {
            cout << "Enter publish year: ";
            cin >> year;
            if (cin.fail() || year < 0 || year > 2025) {
                cout << "Invalid data. Please try again.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                break;
            }
        } while (true);

        int n_citation = 0; 
        do {
            cout << "Enter the number of citations: ";
            cin >> n_citation;
            if (cin.fail() || n_citation < 0) {
                cout << "Invalid citations count. Please try again.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                break;
            }
        } while (true);

        int typeChoice;
        do {
            cout << "Choose the type of article (1: SCIE, 2: SCOPUS, 3: CONFERENCE, 4: OTHER): ";
            cin >> typeChoice;
            if (cin.fail() || typeChoice < 1 || typeChoice > 4) {
                cout << "Loai bai bao khong hop le. Vui long nhap lai.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                break;
            }
        } while (true);
        Type type = static_cast<Type>(typeChoice);

        int statusChoice;
        ArticleStatus status;
        do {
            cout << "Choose the status of article (1: DRAFT, 2: SUBMITTED, 3: PUBLISHED): ";
            cin >> statusChoice;
            if (cin.fail() || statusChoice < 1 || statusChoice > 3) {
                cout << "Trang thai khong hop le. Vui long nhap lai.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                break;
            }
        } while (true);
        switch (statusChoice) {
            case 1: status = ArticleStatus::DRAFT; break;
            case 2: status = ArticleStatus::SUBMITTED; break;
            case 3: status = ArticleStatus::PUBLISHED; break;
        }

        int numAuthors;
        do {
            cout << "Enter the number of authors: ";
            cin >> numAuthors;
            if (cin.fail() || numAuthors < 0) {
                cout << "Invalid author number. Please try again.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                break;
            }
        } while (true);

        // Choose available author or add new one

        int numReferences;
        do {
            cout << "Enter the number of reference documents: ";
            cin >> numReferences;
            if (cin.fail() || numReferences < 0) {
                cout << "Invalid reference number. Please try again.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                break;
            }
        } while (true);

        // Choose available references or add external references

        
    }

    Author createNewAuthor() {
        string name;
        cout << "Nhap ten tac gia: ";
        getline(cin, name);

        string id = Utilities::generateUUID();
        return Author(id, name);
    }
};
