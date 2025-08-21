#include "lib/models/Article.h"

Article::Article() {}

Article::Article(int articleID, string articleName, int authorID, int journalID, ArticleStatus status) {
    this->articleID = articleID; 
    this->articleName = articleName;
    this->authorID = authorID;
    this->journalID = journalID;
    this->status = status;
}

Article::~Article() {}

void Article::setArticleID(int articleID) {
    this->articleID = articleID;
}

int Article::getArticleID() const {
    return this->articleID;
}

void Article::setArticleName(string articleName) {
    this->articleName = articleName;
}

string Article::getArticleName() const {
    return this->articleName;
}

void Article::setAuthorID(int authorID) {
    this->authorID = authorID;
}

int Article::getAuthorID() const {
    return this->authorID;
}

void Article::setJournalID(int journalID) {
    this->journalID = journalID;
}

int Article::getJournalID() const {
    return this->journalID;
}

void Article::submit() {
    if (this->status == ArticleStatus::DRAFT) {
        this->status = ArticleStatus::SUBMITTED;
    }
}

void Article::startReview() {
    if (this->status == ArticleStatus::SUBMITTED) {
        this->status = ArticleStatus::UNDER_REVIEW; 
    }
}

void Article::requestRevisions() {
    if (this->status == ArticleStatus::UNDER_REVIEW) {
        this->status = ArticleStatus::REVISIONS;
    }
}

void Article::accept() {
    if (this->status == ArticleStatus::REVISIONS) {
        this->status = ArticleStatus::ACCEPTED; 
    }
}

void Article::reject() {
    if (this->status == ArticleStatus::UNDER_REVIEW || this->status == ArticleStatus::REVISIONS) {
        this->status = ArticleStatus::REJECTED; 
    }
}

void Article::publish() {
    if (this->status == ArticleStatus::ACCEPTED) {
        this->status = ArticleStatus::PUBLISHED; 
    }
}

ArticleStatus Article::getStatus() const {
    return this->status;
}