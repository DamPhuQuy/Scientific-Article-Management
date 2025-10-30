#include "RepositoryManager.h"
#include "DataManipulation.h"
#include "MenuUtilities.h" 
#include <iostream> 
#include <conio.h>
using namespace std;
namespace fs = std::filesystem; 

void start() {
    // fetch data
    DataManipulation service; 
    ArticleRepo a_repo; 
    AuthorRepo au_repo; 
    AuthorArticleRepo au_ar; 

    MenuUtilities::data_menu(service, a_repo, au_repo, au_ar); 
    RepositoryManager repo(a_repo, au_repo, au_ar);
    
    ArticleService a_service(repo);

    MenuUtilities::main_menu(a_service);  
}

int main() {
    start();
    return 0;
}