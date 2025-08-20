#include "Article.h"

Article::Article() {}

Article::Article(int articleID, string articleName, Author author, Journal journal) {
    this->articleID = articleID;
    this->articleName = articleName;
    this->author = author;
    this->journal = journal;
}

Article::Article(const Article &a) {
    this->articleID = a.articleID;
    this->articleName = a.articleName;
    this->author = a.author;
    this->journal = a.journal;
}

Article::~Article() {}

void Article::setArticleID(int articleID) {
    this->articleID = articleID;
}

int Article::getArticleID() {
    return this->articleID;
}

void Article::setArticleName(string articleName) {
    this->articleName = articleName;
}

string Article::getArticleName() {
    return this->articleName;
}

void Article::setAuthor(Author author) {
    this->author = author;
}

Author Article::getAuthor() {
    return this->author;
}

void Article::setJournal(Journal journal) {
    this->journal = journal;
}

Journal Article::getJournal() {
    return this->journal;
}

