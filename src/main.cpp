#include "RepositoryManager.h"
#include "DataManipulation.h"
#include "Constants.h"
#include <iostream> 
using namespace std;
namespace fs = std::filesystem; 

void showMainMenu() {
    cout << "\n==============================\n";
    cout << "    ARTICLE MANAGEMENT MENU  \n";
    cout << "==============================\n";
    cout << "  1. Manage Articles\n";
    cout << "  2. Manage Authors\n";
    cout << "  3. Data Manipulation\n";
    cout << "  0. Exit\n";
    cout << "==============================\n";
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

    showMainMenu(); 
    int choice; cin >> choice; cin.ignore(); 

    switch (choice) {
    case 1:
        repo.getArticles().traverse(); 
        break;
    case 2: 
        repo.getAuthors().liveSearchByCountry(); 
    case 0: 
        break; 
    default:
        break;
    }
}

int main(){
    start();
    return 0;
}