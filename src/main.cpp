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
    cout << au_repo.getAuthor(1).getAuthorName() << endl;
    cout << j_repo.getJournal(1).getJournalName() << endl;
}