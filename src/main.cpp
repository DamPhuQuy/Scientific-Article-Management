#include "repositories/ArticleRepository.h"
#include "repositories/AuthorRepository.h"
#include "repositories/JournalRepository.h"
#include "services/DataManipulation.h"

using namespace std;

int main(void) {    
    ArticleRepository a_repo(DataManipulation::init<Article>());
    AuthorRepository au_repo(DataManipulation::init<Author>());
    JournalRepository j_repo(DataManipulation::init<Journal>());

    cout << a_repo.getArticle(1).getArticleName() << endl;
    int au_id = a_repo.getArticle(1).getAuthorID();
    int j_id = a_repo.getArticle(1).getJournalID();
    cout << au_repo.getAuthor(au_id).getAuthorName() << endl;
    cout << j_repo.getJournal(j_id).getJournalName() << endl;
}