#include "RepositoryManager.h"
#include "DataManipulation.h"
#include "MenuUtilities.h" 
#include <iostream> 
#include <conio.h>
#include <thread>
#include <chrono>

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

void end() {
    system("cls");

    cout << "\n";
    cout << "----------------------------------------------------------------------------------------------------------\n";
    cout <<"|                          Cam on da su dung ung dung cua chung toi                                      |\n";
    cout <<"|                                                                                                        |\n";
    cout << "----------------------------------------------------------------------------------------------------------\n";
    cout << "\n";

    this_thread::sleep_for(chrono::milliseconds(800));
}

void intro(){
        system("cls"); 

    cout << "\n"; 
    cout <<("----------------------------------------------------------------------------------------------------------\n");
    cout <<("|                               Truong Dai Hoc Bach Khoa - Dai Hoc Da Nang                               |\n");
    cout <<("+--------------------------------------------------------------------------------------------------------+\n");
    cout <<("|   PBL2:  Du an co so lap trinh      |           Xay dung ung dung quan ly bai bao khoa hoc             |\n");
    cout <<("+--------------------------------------------------------------------------------------------------------+\n");
    cout <<("|         Sinh vien thuc hien         |                                                                  |\n");
    cout <<("|             Dam Phu Quy             |                     GVHD. Do Thi Tuyet Hoa                       |\n");
    cout <<("|            Dam Vinh Quang           |                                                                  |\n");
    cout <<("----------------------------------------------------------------------------------------------------------\n");

    this_thread::sleep_for(chrono::milliseconds(800));
    
    cout<<("Nhan phim bat ki de bat dau...");    

    _getch();
}

int main() {
    intro();
    start();
    end();
    return 0;
}