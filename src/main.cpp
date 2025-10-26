#include "RepositoryManager.h"
#include "DataManipulation.h"
#include "Constants.h"
#include <iostream> 
#include <conio.h>
using namespace std;
namespace fs = std::filesystem; 

void showMainMenu(RepositoryManager& repo) {
    const string options[] = {
        "Manage Articles",
        "Manage Authors",
        "Exit"
    };
    const int numOptions = sizeof(options) / sizeof(options[0]);

    int selected = 0; // vị trí đang chọn

    char c; 

    while (true) {
        if (_kbhit()) {
            system("cls");
            cout << "\n==============================\n";
            cout << "    ARTICLE MANAGEMENT MENU  \n";
            cout << "==============================\n";
            
            for (int i = 0; i < numOptions; i++) {
                if (i == selected) {
                    cout << "-> " << "[" << options[i] << "]" << "\n"; 
                } else {
                    cout << "    " << "[" << options[i] << "]" << "\n"; 
                }
            }
            
            cout << "==============================\n";
            cout << "Use arrow UP/DOWN key to move, Enter to select\n";
            
            c = _getch();
        
            if (c == 0 || c == -32) {
                c = _getch();
                if (c == 72 && selected > 0) selected--;          // ↑
                else if (c == 80 && selected < numOptions - 1) selected++; // ↓
            } else if (c == 13) {
                system("cls");
                switch (selected) {
                case 0:
                    cout << "→ Opening Article Management...\n";
                    repo.getArticles().searchMenu();
                    break;
                case 1:
                    cout << "→ Opening Author Management...\n";
                    repo.getAuthors().searchAuthorMenu(); 
                    break;
                case 2:
                    cout << "Exiting program...\n";
                    return;
                }
                cout << "\nPress any key to return...";
                _getch();
            } else if (c == 27) {
                break;
            }

            if (selected >= numOptions) // if index > size
                selected = numOptions - 1;
        }
    }
}

void manipulateData(DataManipulation& service, 
                    ArticleRepo& a_repo,
                    AuthorRepo& au_repo,
                    ArticleReferenceRepo& ar_ref,
                    AuthorArticleRepo& au_ar) {
    int option;
    cout << "\n--- Data Manipulation ---\n";
    cout << "1. Import dataset from JSON\n";
    cout << "2. Export dataset to CSV\n";
    cout << "3. Automatically import from system\n"; 
    cout << "0. Back to main menu\n";
    cout << "Your choice: ";
    cin >> option; cin.ignore();

    switch (option) {
        case 1: {
            cout << "Insert dataset: "; 
            string file; getline(cin, file);
            service.fetchArticleDataSet(Constants::getModelsPath(file), a_repo, au_ar, ar_ref, option);

            cout << "Insert authors dataset: "; 
            getline(cin, file); 
            service.fetchAuthorInformation(Constants::getModelsPath(file), au_repo, option); 
            break;
        }
        case 2: {
            cout << "Insert dataset: "; 
            string file; getline(cin, file); 
            service.fetchArticleDataSet(Constants::getModelsPath(file), a_repo, au_ar, ar_ref, option);

            cout << "Insert authors dataset: "; 
            getline(cin, file); 
            service.fetchAuthorInformation(Constants::getModelsPath(file), au_repo, option);  
            break;
        }
        case 3: {
            service.fetchArticleDataSet(Constants::DataSetJson, a_repo, au_ar, ar_ref); 
            service.fetchAuthorInformation(Constants::AuInfoJson, au_repo);
            break; 
        }
        case 0:
            break;
        default:
            cout << "Invalid option!\n";
    }
}

void start() {
    // fetch data
    DataManipulation service; 
    ArticleRepo a_repo; 
    AuthorRepo au_repo; 
    ArticleReferenceRepo ar_ref;    
    AuthorArticleRepo au_ar; 

    manipulateData(service, a_repo, au_repo, ar_ref, au_ar); 

    RepositoryManager repo(a_repo, au_repo, au_ar, ar_ref);

    showMainMenu(repo); 
    // int choice; cin >> choice; cin.ignore(); 

    // switch (choice) {
    // case 1:
    //     repo.getArticles().searchMenu(); 
    //     break; 
    // case 2: 
    //     repo.getAuthors().searchAuthorMenu(); 
    // case 0: 
    //     break; 
    // default:
    //     break;
    // }
}

int main() {
    start();
    return 0;
}