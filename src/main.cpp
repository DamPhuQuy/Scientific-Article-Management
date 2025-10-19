#include "RepositoryManager.h"
#include "DataManipulation.h"
#include "Constants.h"
#include <iostream> 
using namespace std;
namespace fs = std::filesystem; 

void begin(){ 
    cout<<"Chao mung den voi he thong quan ly bai bao"<<endl;
    cout<<"-----------------------------------------------"<<endl;
    cout<<"1. Quan ly bai bao"<<endl;
    cout<<"2. Quan ly tac gia"<<endl;
    cout<<"3. Quan ly tap chi"<<endl;
    cout<<"4. Thoat"<<endl;
    cout<<"-----------------------------------------------"<<endl;
    cout<<"Hay chon mot lua chon (1-4): ";
    int choice;
    cin>>choice;
    switch(choice){
        case 1:
            cout<<" Quan ly bai bao"<<endl;
            
            break;
        case 2:
            cout<<" Quan ly tac gia"<<endl;
            
            break;
        case 3:
            cout<<" Quan ly tap chi"<<endl;
            break;
        case 4:
            cout<<"Thoat!"<<endl;
            exit(0);
        default:
            cout<<"hay thu lai."<<endl;
            begin();
    }
}

void start() {
    DataManipulation data_m; 

    ArticleRepo a_repo; 
    AuthorRepo au_repo; 
    ArticleReferenceRepo ar_ref; 
    AuthorArticleRepo au_ar; 

    data_m.fetchArticleDataSet(Constants::DataSet, a_repo, au_ar, ar_ref); 
    data_m.fetchAuthorInformation(Constants::AuthorInfo, au_repo); 

    RepositoryManager repo(a_repo, au_repo, au_ar, ar_ref);
    repo.getArticles().traverse(); 
}

int main() {
    start();
    return 0;
}