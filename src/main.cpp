#include "repositories/ArticleRepository.h"
#include "repositories/AuthorRepository.h"
#include "repositories/JournalRepository.h"
#include "services/DataManipulation.h"

using namespace std;

int main(void) {    
    map<int, Article> articleMap = DataManipulation::init<Article>();
    map<int, Author> authorMap = DataManipulation::init<Author>();
    map<int, Journal> journalMap = DataManipulation::init<Journal>();

    DataWrapper dw(&articleMap, &authorMap, &journalMap); 

    ArticleRepository a_repo(&dw.getArticles()); 
    AuthorRepository au_repo(&dw.getAuthors()); 
    JournalRepository j_repo(&dw.getJournals()); 

    a_repo.showArticleDescriptionByID(dw, 1);
    Article article = dw.getArticles().at(1); 
    
    int authorID = article.getAuthorID(); 
    int journalID = article.getJournalID(); 

    cout << "--------------------------------------\n"; 
    au_repo.showAuthorDescriptionByID(dw, authorID); 
    cout << "--------------------------------------\n";
    j_repo.showJournalDescriptionByID(dw, journalID); 

    Article newArticle = a_repo.input(dw);
    a_repo.addArticle(newArticle); 
    
    a_repo.showArticleDescriptionByID(dw, newArticle.getArticleID()); 

    return 0; 
}