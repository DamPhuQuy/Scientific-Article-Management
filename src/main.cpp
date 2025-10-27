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

    int selected = 0; 

    char c; 

    while (true) {
        system("cls");
        cout << "\n==============================\n";
        cout << "    ARTICLE MANAGEMENT MENU  \n";
        cout << "==============================\n";
        
        for (int i = 0; i < numOptions; i++) {
            if (i == selected)
                cout << "-> [" << options[i] << "]\n";
            else
                cout << "   " << options[i] << "\n";
        }

        cout << "==============================\n";
        cout << "Use arrow UP/DOWN key to move, Enter to select\n";

        while (true) {
            if (_kbhit()) {
                c = _getch();
                break; 
            }
        }
        
        if (c == 0 || c == -32 || c == 224) {
            c = _getch();
            switch (c) {
                case 72: selected = (selected - 1 + numOptions) % numOptions; break; 
                case 80: selected = (selected + 1) % numOptions; break;  
            }
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
                    cout << "Exiting... \n";
                    return;
            }
            // cout << "\nPress any key to return...";
            // _getch();
        } else if (c == 27) {
            cin.ignore(); 
            break;
        } else {
            continue; 
        }
    }
}

void fetchData(
    DataManipulation& service,
    ArticleRepo& a_repo,
    AuthorRepo& au_repo,
    AuthorArticleRepo& au_ar
) {
    const string options[] = {
        "Import dataset from JSON",
        "Export dataset to CSV",
        "Automatically import from system",
        "Back to main menu"
    };

    const int numOptions = sizeof(options) / sizeof(options[0]);
    int selected = 0;
    char c;

    while (true) {
        system("cls");
        cout << "\n==============================\n";
        cout << "    DATA MANIPULATION MENU   \n";
        cout << "==============================\n";

        for (int i = 0; i < numOptions; i++) {
            if (i == selected)
                cout << "-> [" << options[i] << "]\n";
            else
                cout << "   " << options[i] << "\n";
        }

        cout << "==============================\n";
        cout << "Use arrow UP/DOWN to move, Enter to select\n";

        while (true) {
            if (_kbhit()) {
                c = _getch();
                break; 
            }
        }

        if (c == 0 || c == 224 || c == -32) {
            c = _getch();
            switch (c) {
                case 72: selected = (selected - 1 + numOptions) % numOptions; break; 
                case 80: selected = (selected + 1) % numOptions; break;      
            }
        } else if (c == 13) {
            switch (selected) {
                case 0: {
                    cout << "Insert dataset: ";
                    cin.ignore();
                    string file;
                    getline(cin, file);
                    service.fetchArticleDataSet(Constants::getModelsPath(file), a_repo, au_ar);

                    cout << "Insert authors dataset: ";
                    getline(cin, file);
                    service.fetchAuthorInformation(Constants::getModelsPath(file), au_repo);
                    return; 
                }
                case 1: {
                    cout << "Insert dataset: ";
                    cin.ignore();
                    string file;
                    getline(cin, file);
                    service.fetchArticleDataSet(Constants::getModelsPath(file), a_repo, au_ar);

                    cout << "Insert authors dataset: ";
                    getline(cin, file);
                    service.fetchAuthorInformation(Constants::getModelsPath(file), au_repo);
                    return;
                }
                case 2:
                    service.fetchArticleDataSet(Constants::DataSetJson, a_repo, au_ar);
                    service.fetchAuthorInformation(Constants::AuInfoJson, au_repo);
                    return;
                case 3:
                    cout << "Exit...\n";
                    exit(0); 
            }
        } else if (c == 27) {
            exit(0);   
        } else {
            continue; 
        }
    }
}


void start() {
    // fetch data
    DataManipulation service; 
    ArticleRepo a_repo; 
    AuthorRepo au_repo; 
    AuthorArticleRepo au_ar; 

    fetchData(service, a_repo, au_repo, au_ar); 

    RepositoryManager repo(a_repo, au_repo, au_ar);

    showMainMenu(repo); 
}

int main() {
    start();
    return 0;
}