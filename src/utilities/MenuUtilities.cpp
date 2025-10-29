#include "MenuUtilities.h"
#include "ArticleService.h" 
#include "Statistic.h" 
#include <iostream>
#include <vector>
#include <conio.h>          // getch(), kbhit()
#include <thread>           // sleep_for
#include <chrono>           // milliseconds
#include <string>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono_literals;

int MenuUtilities::general_menu(const vector<string> &options, const string &title, bool allowEsc)
{
    int selected = 0;
    int key = 0;

    while (true) {
        system("cls");
        cout << "\n";
        for (int i = 0; i < 40; ++i) cout << "=";
        cout << "\n    " << title << "    \n";
        for (int i = 0; i < 40; ++i) cout << "=";
        cout << "\n\n";

        for (int i = 0; i < options.size(); ++i) {
            if (i == selected)
                cout << "-> [" << options[i] << "]\n";
            else
                cout << "   " << options[i] << "\n";
        }

        cout << "\n";
        for (int i = 0; i < 40; ++i) cout << "-";
        cout << "\n";
        cout << "Use Up/Down to move, ENTER to select";
        if (allowEsc) cout << ", ESC to go back";
        cout << "\n";

    
        while (!kbhit()) {
            sleep_for(50ms);  
        }
        key = getch();

        if (key == 224 || key == 0 || key == 27) {
            if (key == 27) { // ESC
                if (allowEsc) return -1;
                continue;
            }
            key = getch(); 
            switch (key) {
                case 72: // Up
                    selected = (selected - 1 + options.size()) % options.size();
                    break;
                case 80: // Down
                    selected = (selected + 1) % options.size();
                    break;
            }
        }
        else if (key == 13) { // Enter
            return selected;
        }
        else if (key == 27 && allowEsc) {
            return -1;
        }
    }
}

void MenuUtilities::main_menu(ArticleService& a_service)
{
    const vector<string> options = {
        "Manage Articles",
        "Manage Authors",
        "Exit"
    }; 

    while (true) {
        int selected = MenuUtilities::general_menu(options, "ARTICLE MANAGEMENT MENU");
        switch (selected) {
            case 0:
                cout << "-> Opening Article Management...\n";
                MenuUtilities::article_sub_menu(repo, a_service); 
                break;
            case 1:
                cout << "-> Opening Author Management...\n";
                MenuUtilities::author_sub_menu(repo); 
                break;
            case 2:
                cout << "Exiting... \n";
                return;
       }
    }
}

void MenuUtilities::article_sub_menu(ArticleService& a_service)
{
    const vector<string> options = {
        "Create Article",
        "View All Articles",
        "Update Article",
        "Delete Article",
        "Search Articles",
        "Statistics",
        "Back"
    };

    while (true) {
        int selected = MenuUtilities::general_menu(options, "ARTICLE MANAGEMENT");
        switch (selected) {
            case 0: {
                cout << "-> Creating new article...\n";
                a_service.createArticle(); 
                break;
            }
            case 1: {
                cout << "-> Viewing all articles...\n";
                for (const auto& element : repo.getArticles().getAll()) {
                    element->showDescription();
                }
                break;
            }
            case 2: {
                cout << "-> Updating article...\n";
                repo.updateArticleMenu();
                break;
            }
            case 3: {
                cout << "-> Deleting article...\n";
                repo.deleteArticleMenu();
                break;
            }
            case 4: {
                cout << "-> Searching articles...\n";
                repo.getArticles().searchMenu();
                break;
            }
            case 5: {
                cout << "-> Viewing article statistics...\n";
                MenuUtilities::statisticArticleMenu(repo); 
                break;
            }
            case 6: {
                cout << "Returning to main menu...\n";
                return;
            }
        }
    }
}

void MenuUtilities::author_sub_menu(RepositoryManager& repo)
{
    const vector<string> options = {
        "Create Author",
        "View All Authors",
        "Update Author",
        "Delete Author",
        "Search Authors",
        "Statistics",
        "Back"
    };

    while (true) {
        int selected = MenuUtilities::general_menu(options, "AUTHOR MANAGEMENT");
        switch (selected) {
            case 0: {
                cout << "-> Creating new author...\n";
                repo.getAuthors().createAuthor();
                break;
            }
            case 1: {
                cout << "-> Viewing all authors...\n";
                repo.displayAll();
                break;
            }
            case 2: {
                cout << "-> Updating author...\n";
                repo.updateAuthorMenu();
                break;
            }
            case 3: {
                cout << "-> Deleting author...\n";
                repo.deleteAuthorMenu();
                break;
            }
            case 4: {
                cout << "-> Searching authors...\n";
                repo.searchAuthorMenu();
                break;
            }
            case 5: {
                cout << "-> Viewing author statistics...\n";
                MenuUtilities::statisticAuthorMenu(repo); 
                break;
            }
            case 6: {
                cout << "Returning to main menu...\n";
                return;
            }
        }
    }
}


void MenuUtilities::data_menu(DataManipulation &service, ArticleRepo &a_repo, AuthorRepo &au_repo, AuthorArticleRepo &au_ar)
{
    const vector<string> options = {
        "Import dataset from JSON",
        "Automatically import from system",
        "Back to main menu"
    }; 
    int selected = MenuUtilities::general_menu(options, "DATA MANIPULATION MENU"); 
    switch (selected) {
        case 0: {
            cout << "Insert dataset: ";
            cin.ignore();
            string file;
            getline(cin, file);
            service.fetchArticleDataSet(Constants::getModelsPath(file), a_repo, au_ar);
            sleep_for(1s); 

            cout << "Insert authors dataset: ";
            getline(cin, file);
            service.fetchAuthorInformation(Constants::getModelsPath(file), au_repo);
            sleep_for(1s);

            return; 
        }
        case 1:
            service.fetchArticleDataSet(Constants::DataSetJson, a_repo, au_ar);
            sleep_for(1s); 

            service.fetchAuthorInformation(Constants::AuInfoJson, au_repo);
            sleep_for(1s); 
            return;
        case 2:
            cout << "Exit...\n";
            exit(0);  
    }
}

void MenuUtilities::statisticArticleMenu(RepositoryManager& repo) {
    const std::vector<std::string> options = {
        "Statistics by Year",
        "Statistics by Type",
        "Back"
    };

    while (true) {
        int selected = MenuUtilities::general_menu(options, "ARTICLE STATISTICS MENU");
        switch (selected) {
            case 0:
                Statistics::articlesByYear(repo);
                break;
            case 1:
                Statistics::articlesByType(repo);
                break;
            case 2:
                return;
        }
    }
}

void MenuUtilities::statisticAuthorMenu(RepositoryManager& repo) {
    const std::vector<std::string> options = {
        "Statistics by Country",
        "Statistics by Field of Study",
        "Top Authors by Publications",
        "Back"
    };

    while (true) {
        int selected = MenuUtilities::general_menu(options, "AUTHOR STATISTICS MENU");
        switch (selected) {
            case 0:
                Statistics::authorsByCountry(repo);
                break;
            case 1:
                Statistics::authorsByField(repo);
                break;
            case 2:
                Statistics::topAuthorsByPublication(repo);
                break;
            case 3:
                return;
            default:
                std::cout << "Invalid selection.\n";
        }
    }
}
