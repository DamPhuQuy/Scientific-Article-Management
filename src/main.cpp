#include "repositories/ArticleRepository.h"
#include "repositories/AuthorRepository.h"
#include "repositories/JournalRepository.h"
#include "services/DataManipulation.h"

using namespace std;

int main(void) {    
    unordered_map<int, Article> articleMap = DataManipulation::init<Article>(); 
    unordered_map<int, Author> authorMap = DataManipulation::init<Author>(); 
    unordered_map<int, Journal> journalMap = DataManipulation::init<Journal>(); 

    DataManipulation fetch; 
    articleMap = fetch.init<Article>();  
    authorMap = fetch.init<Author>(); 
    journalMap = fetch.init<Journal>(); 

    DataWrapper dw(&articleMap, &authorMap, &journalMap); 

    ArticleRepository a_repo(&dw.getArticles()); 
    AuthorRepository au_repo(&dw.getAuthors()); 
    JournalRepository j_repo(&dw.getJournals()); 

    
}