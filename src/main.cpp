#include "RepositoryManager.h"
#include "DataManipulation.h"
#include "Constants.h"

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

void init_data() {
    DataManipulation data_m; 

    AuthorsRepo au_repo(
        data_m.fetchAuthorInformation(Constants::AuthorInfo)
    ); 

    vector<AuthorArticle> au_ar; 
    vector<ArticleReference> ar_ref; 
    ArticlesRepo a_repo(
        data_m.fetchArticles(Constants::DataSet, au_ar, ar_ref)
    );

    RepositoryManager repo(a_repo, au_repo, ar_ref, au_ar); 
}

void start() {
    init_data(); 
}

int main() {
    start();
    return 0;
}