#include "MenuUtilities.h"
#include "ArticleService.h" 
#include "Statistics.h"
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
                MenuUtilities::article_sub_menu(a_service);
                break;
            case 1:
                cout << "-> Opening Author Management...\n";
                MenuUtilities::author_sub_menu(a_service.getRepo());
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
                for (const auto& element : a_service.getRepo().getArticles().getAll()) {
                    element->showDescription();
                }
                break;
            }
            case 2: {
                cout << "-> Updating article...\n";
                MenuUtilities::article_update_menu(a_service.getRepo());
                break;
            }
            case 3: {
                cout << "-> Deleting article...\n";
                MenuUtilities::article_delete_menu(a_service.getRepo());
                break;
            }
            case 4: {
                cout << "-> Searching articles...\n";
                a_service.getRepo().getArticles().searchMenu();
                break;
            }
            case 5: {
                cout << "-> Viewing article statistics...\n";
                MenuUtilities::statisticArticleMenu(a_service.getRepo());
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
                for (const auto& [id, author] : repo.getAuthors().getAuthorContainer()) {
                    author.showAuthorDetails();
                }
                break;
            }
            case 2: {
                cout << "-> Updating author...\n";
                MenuUtilities::author_update_menu(repo);
                break;
            }
            case 3: {
                cout << "-> Deleting author...\n";
                author_delete_menu(repo);
                break;
            }
            case 4: {
                cout << "-> Searching authors...\n";
                repo.getAuthors().searchAuthorMenu();
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

void MenuUtilities::article_update_menu(RepositoryManager& repo) {
    cout << "\n=== UPDATE ARTICLE MENU ===\n";

    string id;
    cout << "Enter Article ID to update: ";
    getline(cin, id);

    auto it = repo.getArticles().getContainer().find(id);
    if (it != repo.getArticles().getContainer().end()) {
        cout << "Article not found.\n";
        return;
    }

    const vector<string> options = {
        "Update Title",
        "Update Venue",
        "Update Year",
        "Back"
    };

    while (true) {
        int selected = MenuUtilities::general_menu(options, "UPDATE ARTICLE");
        switch (selected) {
            case 0: {
                cout << "Enter new title: ";
                string title; getline(cin, title);
                it->second->setTitle(title);
                cout << "Title updated successfully.\n";
                break;
            }
            case 1: {
                cout << "Enter new venue: ";
                string venue; getline(cin, venue);
                it->second->setVenue(venue);
                cout << "Venue updated successfully.\n";
                break;
            }
            case 2: {
                cout << "Enter new year: ";
                string input; getline(cin, input);
                int year = stoi(input);
                it->second->setYear(year);
                cout << "Year updated successfully.\n";
                break;
            }
            case 3:
                cout << "Returning...\n";
                return;
        }
    }
}

void MenuUtilities::article_delete_menu(RepositoryManager& repo) {
    cout << "\n=== DELETE ARTICLE MENU ===\n";

    string id;
    cout << "Enter Article ID to delete: ";
    getline(cin, id);

    if (repo.getArticles().getContainer().erase(id))
        cout << "Article deleted successfully.\n";
    else
        cout << "Article not found.\n";
}

void MenuUtilities::author_update_menu(RepositoryManager& repo) {
    cout << "\n=== UPDATE AUTHOR MENU ===\n";

    string id;
    cout << "Enter Author ID to update: ";
    getline(cin, id);

    auto it = repo.getAuthors().getAuthorContainer().find(id);
    if (it != repo.getAuthors().getAuthorContainer().end()) {
        cout << "Author not found.\n";
        return;
    }

    const vector<string> options = {
        "Update Name",
        "Update Country",
        "Update Field of Study",
        "Update Total of Publications",
        "Back"
    };

    while (true) {
        int selected = MenuUtilities::general_menu(options, "UPDATE AUTHOR");
        switch (selected) {
            case 0: {
                cout << "Enter new name: ";
                string name; getline(cin, name);
                it->second.setFullName(name);
                cout << "Name updated successfully.\n";
                break;
            }
            case 1: {
                cout << "Enter new country: ";
                string country; getline(cin, country);
                it->second.setCountry(country);
                cout << "Country updated successfully.\n";
                break;
            }
            case 2: {
                cout << "Enter new study: ";
                string study; getline(cin, study);
                it->second.setFieldOfStudy(study);
                cout << "Study updated successfully.\n";
            }
            case 3: {
                cout << "Enter new total of publications: ";
                string total; getline(cin, total);
                it->second.setTotalPublications(stoi(total));
                cout << "Total publications updated successfully.\n";
            }
            case 4:
                cout << "Returning...\n";
                return;
        }
    }
}

void MenuUtilities::author_delete_menu(RepositoryManager& repo) {
    cout << "\n=== DELETE AUTHOR MENU ===\n";

    string id;
    cout << "Enter Author ID to delete: ";
    getline(cin, id);

    if (repo.getAuthors().getAuthorContainer().erase(id))
        cout << "Author deleted successfully.\n";
    else
        cout << "Author not found.\n";
}