#include "MenuUtilities.h"
#include "Statistics.h"
#include <iostream>
#include <vector>
#include <conio.h> // getch(), kbhit()
#include <thread>  // sleep_for
#include <chrono>  // milliseconds
#include <string>
#include "../utilities/ftxui/component/component.hpp"
#include "../utilities/ftxui/component/screen_interactive.hpp"
#include "../utilities/ftxui/dom/elements.hpp"
#include "../utilities/ftxui/component/event.hpp"

using namespace std;
using namespace std::this_thread;
using namespace std::chrono_literals;
using namespace ftxui;

void MenuUtilities::start(RepositoryManager& repo) {
    auto screen = ScreenInteractive::TerminalOutput();

    bool quit = false;

    // Minimal button style
    ButtonOption minimal_btn = ButtonOption::Animated();
    minimal_btn.transform = [](const EntryState& s) {
        auto label = text(s.label);
        if (s.focused) {
            label |= bgcolor(Color::RGB(30, 30, 40)) | color(Color::White) | bold;
        } else {
            label |= color(Color::GrayLight);
        }
        return label | center;
    };

    auto btn_start = Button("Start", screen.ExitLoopClosure(), minimal_btn);
    auto btn_exit  = Button("Exit", [&] { quit = true; screen.Exit(); }, minimal_btn);

    // Minimal layout
    auto layout = Container::Vertical({
        btn_start,
        btn_exit,
    });

    // Renderer
    auto renderer = Renderer(layout, [&] {
        return vbox({
            text("MENU") | bold | color(Color::White) | center,
            separatorEmpty(),

            text("ĐẠI HỌC BÁCH KHOA - ĐÀ NẴNG") | center | color(Color::GrayLight),
            text("PBL2 • QUẢN LÝ BÀI BÁO KHOA HỌC") | center | color(Color::GrayLight),
            separatorEmpty(),

            // Authors
            text("SV: Đàm Phú Quý • Đàm Vinh Quang") | center | color(Color::GrayDark),
            text("GVHD: ThS. Đỗ Thị Tuyết Hoa") | center | color(Color::GrayDark),
            separatorEmpty(),

            layout->Render() | center
        })
        | center
        | bgcolor(Color::RGB(12, 12, 16));
    });

    screen.Loop(renderer);

    if (quit) {
        return;
    }
}

int MenuUtilities::general_menu(const vector<string> &options, const string &title, bool allowEsc)
{
    int selected = 0;
    int key = 0;

    while (true)
    {
        system("cls");
        cout << "\n";
        for (int i = 0; i < 40; ++i)
            cout << "=";
        cout << "\n    " << title << "    \n";
        for (int i = 0; i < 40; ++i)
            cout << "=";
        cout << "\n\n";

        for (int i = 0; i < options.size(); ++i)
        {
            if (i == selected)
                cout << "-> [" << options[i] << "]\n";
            else
                cout << "   " << options[i] << "\n";
        }

        cout << "\n";
        for (int i = 0; i < 40; ++i)
            cout << "-";
        cout << "\n";
        cout << "Use Up/Down to move, ENTER to select";
        if (allowEsc)
            cout << ", ESC to go back";
        cout << "\n";

        while (!kbhit())
        {
            sleep_for(50ms);
        }
        key = getch();

        if (key == 224 || key == 0 || key == 27)
        {
            if (key == 27)
            { // ESC
                if (allowEsc)
                    return -1;
                continue;
            }
            key = getch();
            switch (key)
            {
            case 72: // Up
                selected = (selected - 1 + options.size()) % options.size();
                break;
            case 80: // Down
                selected = (selected + 1) % options.size();
                break;
            }
        }
        else if (key == 13)
        { // Enter
            return selected;
        }
        else if (key == 27 && allowEsc)
        {
            return -1;
        }
    }
}

void MenuUtilities::main_menu(RepositoryManager& repo)
{
    auto screen = ScreenInteractive::TerminalOutput();

    const std::vector<std::string> options = {
        "Manage Articles",
        "Manage Authors",
        "Exit"
    };

    while (true) {
        int selected = general_menu(options, "ARTICLE MANAGEMENT MENU");

        switch (selected) {
            case 0:
                article_sub_menu(repo);
                break;
            case 1:
                author_sub_menu(repo);
                break;
            case 2:
            case -1:  // ESC
                return;
        }
    }
}

void MenuUtilities::article_sub_menu(RepositoryManager& repo) {
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
        int selected = general_menu(options, "ARTICLE MANAGEMENT");

        switch (selected) {
            case 0: repo.createArticle(); break;
            case 1:
                for (const auto &element : repo.getArticles().getAll()) {
                    element->showDescription();
                    std::cout << "\n";
                }
                std::cout << "Press any key to continue...";
                _getch();
                break;
            case 2: article_update_menu(repo); break;
            case 3: article_delete_menu(repo); break;
            case 4: {
                string selectedId = searchArticleMenu(repo);
                if (!selectedId.empty()) {
                    char ans = getYesNo("Show the references of article: ");
                    if (ans == 'y') show_refs_through_authorId(repo, selectedId);
                }
                break;
            }
            case 5: statisticArticleMenu(repo); break;
            case 6:
            case -1: return; // Back
        }
    }
}

char MenuUtilities::getYesNo(const string& prompt) {
    string input;
    while (true) {
        cout << prompt << " (y/n): ";
        getline(cin, input);

        if (input.empty()) continue;

        char choice = tolower(input[0]);

        if (choice == 'y' || choice == 'n') {
            return choice;
        }

        cout << "Invalid input. Please enter 'y' or 'n'." << endl;
    }
}

void MenuUtilities::author_sub_menu(RepositoryManager &repo)
{
    auto screen = ScreenInteractive::TerminalOutput();

    const vector<string> options = {
        "Create Author",
        "View All Authors",
        "Update Author",
        "Delete Author",
        "Search Author",
        "Statistics",
        "Back"};

    string selectedId;

    while (true)
    {
        int selected = MenuUtilities::general_menu(options, "AUTHOR MANAGEMENT");
        switch (selected)
        {
        case 0:
        {
            cout << "-> Creating new author...\n";
            repo.getAuthors().createAuthor();
            break;
        }
        case 1:
        {
            cout << "-> Viewing all authors...\n";
            for (const auto &[id, author] : repo.getAuthors().getAuthorContainer())
            {
                author.showAuthorDetails();
                cout << "\n";
            }
            cout << "Press any key to continue...";
            _getch();
            break;
        }
        case 2:
        {
            cout << "-> Updating author...\n";
            MenuUtilities::author_update_menu(repo);
            break;
        }
        case 3:
        {
            cout << "-> Deleting author...\n";
            author_delete_menu(repo);
            break;
        }
        case 4:
        {
            cout << "-> Searching authors...\n";
            selectedId = searchAuthorMenu(repo);

            if (selectedId != "") {
                char ans = getYesNo("Show the article that author attended?: ");
                if (ans == 'y') show_article_through_authorId(repo, selectedId);
            }
            break;
        }
        case 5:
        {
            cout << "-> Viewing author statistics...\n";
            MenuUtilities::statisticAuthorMenu(repo);
            break;
        }
        case 6:
        {
            cout << "Returning to main menu...\n";
            return;
        }
        }
    }
}

void MenuUtilities::data_menu(DataManipulation &service, ArticleRepo &a_repo, AuthorRepo &au_repo, AuthorArticleRepo &au_ar)
{
    auto screen = ScreenInteractive::TerminalOutput();
    const vector<string> options = {
        "Import dataset from JSON",
        "Automatically import from system",
        "Back to main menu"};
    int selected = MenuUtilities::general_menu(options, "DATA MANIPULATION MENU");
    switch (selected)
    {
    case 0:
    {
        string file;
        cout << "Insert authors dataset: ";
        getline(cin, file);
        service.fetchAuthorInformation(Constants::getModelsPath(file), au_repo);
        sleep_for(1s);

        cout << "Insert dataset: ";
        getline(cin, file);
        service.fetchArticleDataSet(Constants::getModelsPath(file), a_repo, au_ar, au_repo);
        sleep_for(1s);


        return;
    }
    case 1:
        service.fetchAuthorInformation(Constants::AuInfoJson, au_repo);
        sleep_for(1s);

        service.fetchArticleDataSet(Constants::DataSetJson, a_repo, au_ar, au_repo);
        sleep_for(1s);

        return;
    case 2:
        cout << "Exit...\n";
        exit(0);
    }
}

void MenuUtilities::statisticArticleMenu(RepositoryManager &repo)
{
    const vector<string> options = {
        "Statistics by Year",
        "Statistics by Type",
        "Back"};

    while (true)
    {
        int selected = MenuUtilities::general_menu(options, "ARTICLE STATISTICS MENU");
        switch (selected)
        {
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

void MenuUtilities::statisticAuthorMenu(RepositoryManager &repo)
{
    const vector<string> options = {
        "Statistics by Country",
        "Statistics by Field of Study",
        "Top Authors by Publications",
        "Back"};

    while (true)
    {
        int selected = MenuUtilities::general_menu(options, "AUTHOR STATISTICS MENU");
        switch (selected)
        {
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
            cout << "Invalid selection.\n";
        }
    }
}

void MenuUtilities::show_refs_through_authorId(RepositoryManager &repo, const string& selectedId) {
    Article* temp = repo.getArticles().getContainer().at(selectedId);
    for (const auto& ref : temp->getReferences()) {
        cout << ref << endl;
    }
 }

 string MenuUtilities::searchAuthorMenu(RepositoryManager& repo) {
    vector<string> options = {
        "Search by Name",
        "Search by Country",
        "Search by Field of Study",
        "Back to Main Menu"
    };

    while (true) {
        int choice = MenuUtilities::general_menu(options, "Search Authors");

        if (choice == -1) {
            cout << "Returning to main menu...\n";
            sleep_for(800ms);
            break;
        }

        string selectedId;

        switch (choice) {
            case 0: {
                string selectedId = repo.getAuthors().liveSearchByName();
                if (!selectedId.empty()) {
                    cout << "\nSelected author ID: " << selectedId << "\n";
                    system("pause");
                    return selectedId;
                }
                break;
            }
            case 1: {
                string selectedId = repo.getAuthors().liveSearchByCountry();
                if (!selectedId.empty()) {
                    cout << "\nSelected author ID: " << selectedId << "\n";
                    system("pause");
                    return selectedId;
                }
                break;
            }
            case 2: {
                string selectedId = repo.getAuthors().liveSearchByFieldOfStudy();
                if (!selectedId.empty()) {
                    cout << "\nSelected author ID: " << selectedId << "\n";
                    system("pause");
                    return selectedId;
                }
                break;
            }
            case 3: // Back
                cout << "Returning to main menu...\n";
                sleep_for(800ms);
                return "";
            default:
                break;
        }
    }
    return "";
}

void MenuUtilities::article_update_menu(RepositoryManager &repo)
{
    const vector<string> options = {
        "Update Title",
        "Update Venue",
        "Update Year",
        "Back"};

    while (true)
    {
        int selected = MenuUtilities::general_menu(options, "UPDATE ARTICLE MENU");
        switch (selected)
        {
        case 0:
        {
            string id = repo.getArticles().liveSearchByTitle();
            auto it = repo.getArticles().getContainer().find(id);
            if (it == repo.getArticles().getContainer().end())
            {
                cout << "This id does not exist!";
                selected = 0;
                continue;
            }
            cout << "Enter new title: ";
            string title;
            getline(cin, title);
            it->second->setTitle(title);
            cout << "Title updated successfully.\n";
            break;
        }
        case 1:
        {
            string id = repo.getArticles().liveSearchByTitle();
            auto it = repo.getArticles().getContainer().find(id);
            if (it == repo.getArticles().getContainer().end())
            {
                cout << "This id does not exist!";
                selected = 0;
                continue;
            }
            cout << "Enter new venue: ";
            string venue;
            getline(cin, venue);
            it->second->setVenue(venue);
            cout << "Venue updated successfully.\n";
            break;
        }
        case 2:
        {
            string id = repo.getArticles().liveSearchByTitle();
            auto it = repo.getArticles().getContainer().find(id);
            if (it == repo.getArticles().getContainer().end())
            {
                cout << "This id does not exist!";
                selected = 0;
                continue;
            }
            cout << "Enter new year: ";
            string input;
            getline(cin, input);
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

void MenuUtilities::article_delete_menu(RepositoryManager &repo)
{
    cout << "\n=== DELETE ARTICLE MENU ===\n";

    string id = repo.getArticles().liveSearchByTitle();
    auto it = repo.getArticles().getContainer().find(id);

    if (repo.getArticles().getContainer().erase(id))
        cout << "Article deleted successfully.\n";
    else
        cout << "Article not found.\n";
}

void MenuUtilities::author_update_menu(RepositoryManager &repo)
{
    cout << "\n=== UPDATE AUTHOR MENU ===\n";

    const vector<string> options = {
        "Update Name",
        "Update Country",
        "Update Field of Study",
        "Update Total of Publications",
        "Back"};

    while (true)
    {
        int selected = MenuUtilities::general_menu(options, "UPDATE AUTHOR");
        switch (selected)
        {
        case 0:
        {
            string id = repo.getAuthors().liveSearchByName();
            repo.getAuthors().updateName(id);
            cout << "Name updated successfully.\n";
            break;
        }
        case 1:
        {
            string id = repo.getAuthors().liveSearchByName();
            repo.getAuthors().updateCountry(id);
            cout << "Country updated successfully.\n";
            break;
        }
        case 2:
        {
            string id = repo.getAuthors().liveSearchByName();
            repo.getAuthors().updateFieldOfStudy(id);
            cout << "Study updated successfully.\n";
        }
        case 3:
        {
            string id = repo.getAuthors().liveSearchByName();
            repo.getAuthors().updateTotalOfPublications(id);
            cout << "Total publications updated successfully.\n";
        }
        case 4:
            cout << "Returning...\n";
            return;
        }
    }
}

void MenuUtilities::author_delete_menu(RepositoryManager &repo)
{
    cout << "\n=== DELETE AUTHOR MENU ===\n";

    string id = repo.getAuthors().liveSearchByName();
    repo.getAuthors().removeAuthor(id);
}

void MenuUtilities::show_article_through_authorId(RepositoryManager &repo, const string& selectedId)
{
    Article* a = repo.getArticles().getContainer().at(selectedId);
    a->showDescription();
}

string MenuUtilities::searchArticleMenu(RepositoryManager& repo) {
    vector<string> options = {
        "Search by Title",
        "Search by Year",
        "Search by Type",
        "Back to Main Menu"
    };

    while (true) {
        int choice = MenuUtilities::general_menu(options, "Search Articles");

        if (choice == -1) {
            cout << "Returning to main menu...\n";
            sleep_for(800ms);
            break;
        }

        string selectedId;

        switch (choice) {
            case 0: // Search by Title
                selectedId = repo.getArticles().liveSearchByTitle();
                if (!selectedId.empty()) {
                    cout << "\nSelected article ID: " << selectedId << "\n";
                    system("pause");
                    return selectedId;
                }
                break;

            case 1: // Search by Year
                selectedId = repo.getArticles().liveSearchByYear();
                if (!selectedId.empty()) {
                    cout << "\nSelected article ID: " << selectedId << "\n";
                    system("pause");
                    return selectedId;
                }
                break;

            case 2: // Search by Type
                selectedId = repo.getArticles().liveSearchByType();
                if (!selectedId.empty()) {
                    cout << "\nSelected article ID: " << selectedId << "\n";
                    system("pause");
                    return selectedId;
                }
                break;

            case 3: // Back
                cout << "Returning to main menu...\n";
                sleep_for(800ms);
                return "";

            default:
                break;
        }
    }
    return "";
}