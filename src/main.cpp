#include "repositories/RepositoryManager.h"
#include "services/DataManipulation.h"

using namespace std;

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
    RepositoryManager repo(
        data_m.init<Article*>(),
        data_m.init<Author>(),
    );
}

int main() {
    start();
    return 0;
}