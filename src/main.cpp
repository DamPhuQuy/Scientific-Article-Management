#include "repositories/ArticleRepository.h"
#include "repositories/AuthorRepository.h"
#include "repositories/JournalRepository.h"
#include "services/DataManipulation.h"

using namespace std;

int main(void) {    
    unordered_map<int, Article> articleMap = DataManipulation::init<Article>(); 
    unordered_map<int, Author> authorMap = DataManipulation::init<Author>(); 
    unordered_map<int, Journal> journalMap = DataManipulation::init<Journal>(); 

    ArticleRepository a_repo(articleMap); 
    AuthorRepository au_repo(authorMap); 
    JournalRepository j_repo(journalMap);

    auto repo = make_shared<unordered_map<int, Article>>;
    auto au_repo = make_shared<unordered_map<int, Author>> authors;  
    
    DataWrapper data; 
    

}