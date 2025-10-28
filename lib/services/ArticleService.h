#pragma once 
#include "RepositoryManager.h"
#include "UUID_Generator.h" 
#include "DataManipulation.h"

class ArticleService {
private:
    RepositoryManager& repo; 
public:
    ArticleService(RepositoryManager& r) : repo(r) {}

    void createArticle() {
        int typeChoice;
        do {
            cout << "Choose the type of article (1: SCIE, 2: SCOPUS, 3: CONFERENCE, 4: OTHER): ";
            cin >> typeChoice; cin.ignore();
            if (cin.fail() || typeChoice < 1 || typeChoice > 4) {
                cout << "Loai bai bao khong hop le. Vui long nhap lai.\n";
                cin.clear();    
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                break;
            }
        } while (true);
        Type type = static_cast<Type>(typeChoice); 
        Article* article = DataManipulation::createArticle(type);

        inputArticle(article);    // xử lý liên kết với Author
    }

private:
    void inputArticleReferences(Article* article)
    {
        int numReferences = 0;
        while (true) {
            cout << "Enter the number of reference documents (0 or more): ";
            if (cin >> numReferences && numReferences >= 0) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            cout << "Invalid input. Please enter a non-negative integer.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        article->refs.clear();

        // pick or add
        for (int i = 0; i < numReferences; ++i) {
            cout << "\n=== Reference " << (i + 1) << " of " << numReferences << " ===\n";

            while (true) {
                // Show available titles
                cout << "Available reference titles:\n";
                int idx = 1;
                vector<string> titles;
                for (const auto& [id, element] : repo.getArticles().getContainer()) {
                    cout << idx << ". " << element.getTitle() << "\n";
                    titles.push_back(element.getTitle());
                    ++idx;
                }
                cout << idx << ". Add new reference title\n";

                string choice;
                cout << "Choose (or " << idx << " to add new): ";
                getline(cin >> ws, choice);

                int sel;
                try { sel = stoi(choice); }
                catch (...) { cout << "Please enter a number.\n"; continue; }

                if (sel == idx) {
                    string newTitle;
                    cout << "Enter the reference title: ";
                    getline(cin >> ws, newTitle);

                    if (newTitle.empty()) {
                        cout << "Title cannot be empty.\n";
                        continue;
                    }

                    article->refs.push_back(newTitle);
                    cout << "Added: " << newTitle << "\n";
                    break;
                }
                else if (sel > 0 && sel < idx) {
                    const string& chosen = titles[sel - 1];
                    article->refs.push_back(chosen);
                    cout << "Selected: " << chosen << "\n";
                    break;
                }
                else {
                    cout << "Invalid choice.\n";
                }
            }
        }

        cout << "\nAll references added to article.\n";
    }

    void inputArticle(Article* article) {

        cout << "Enter title of article: ";
        string title; getline(cin, title); article->setTitle(title);

        cout << "Enter abstract of article: ";
        string abstract; getline(cin, abstract); article->setAbstract(abstract); 

        cout << "Enter the venue of article: ";
        string venue; getline(cin, venue); article->setVenue(venue);

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
        article->setYear(year);

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
        article->setNCitation(n_citation);

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
        article->setStatus(status); 

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

        while (true) {
            cout << "Available authors:\n";
            int index = 1;
            vector<string> keys;
            for (const auto& element : repo.getAuthors().getAuthorContainer()) {
                cout << index << ". " << element.second.getFullName() << "\n";
                keys.push_back(element.first);  // Save the ID
                ++index;
            }
            cout << index << ". Add new author\n";

            cout << "Choose an author (or " << index << " to add new): ";
            cin >> choice; cin.ignore();

            int selected;
            try {
                selected = stoi(choice);
            } catch (...) {
                cout << "Invalid input. Please enter a number.\n";
                continue;
            }

            if (selected == index) {
                // Add new author
                Author newAuthor;
                newAuthor.inputFromUser();
                repo.getAuthors().add(newAuthor);
                cout << "Added new author: " << newAuthor.getFullName() << "\n";

                repo.getAuthorArticles().add(article->getId(), newAuthor.getId());
            } else if (selected > 0 && selected < index) {
                const string& chosenId = keys[selected - 1];
                const Author& chosen = repo.getAuthors().getAuthorContainer().at(chosenId);
                    
                cout << "You selected: " << chosen.getFullName() << "\n";

                repo.getAuthorArticles().add(article->getId(), chosen.getId());
                break; 
            } else {
                cout << "Invalid choice.\n";
            }
        }

        inputArticleReferences(article);
        repo.getArticles().add(article);
    }
};
