#include "RepositoryManager.h"
#include "DataManipulation.h"
#include "Constants.h"
#include <iostream> 
using namespace std;
namespace fs = std::filesystem; 

void start() {
    // fetch data
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

int main(){
    start();
    return 0;
}