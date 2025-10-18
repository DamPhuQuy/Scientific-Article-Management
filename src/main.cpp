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

void start() {
    DataManipulation data_m;
    vector<AuthorArticle> author_article; 
    vector<ArticleReference> article_reference;
    fs::path file_path(Constants::DataSet); 
    unordered_map<string, Article*> articles = data_m.fetchArticles(file_path, author_article, article_reference);
    
    for (auto element : articles) {
        element.second->showDescription(); 
    }

    vector<Author> authors = data_m.fetchAuthorInformation(Constants::AuthorInfo);
    for (const auto& author : authors) {
        author.showAuthorDetails(); 
    }
}

int main() {
    start();
    return 0;
}