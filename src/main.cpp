#include "repositories/ArticleRepository.h"
#include "repositories/AuthorRepository.h"
#include "../lib/repositories/JournalRepository.h"
#include "services/DataManipulation.h"

using namespace std;

int main(void) {
    map<string, Article*> articles;
    map<string, Author> authors;
    map<string, Journal> journals;

    ArticleRepository articleRepo(articles);
    AuthorRepository authorRepo(authors);
    JournalRepository journalRepo(journals);
    return 0;
}