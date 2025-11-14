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

    // MenuUtilities::data_menu(service, a_repo, au_repo, au_ar);
    RepositoryManager repo(a_repo, au_repo, au_ar);

    MenuUtilities::start(repo);

    // bool isConsistent = repo.validateDataConsistency();

    // if (isConsistent)
    //     MenuUtilities::main_menu(repo);

    // cout << "Ket thuc chuong trinh...";
    // return;
}

int main() {
    start();
    return 0;
}