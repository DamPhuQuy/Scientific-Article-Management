#include <utility>

#include "models/Article.h"

// Constructor

Article::Article(): status() {
}

Article::Article(string a_id, 
                 string a_name,
                 string au_id,
                 string j_id,
                 const ArticleStatus st) :
    articleID(std::move(a_id)), articleName(std::move(a_name)), authorID(std::move(au_id)), journalID(std::move(j_id)), status(st) {
}

Article::Article(const Article &a) {
    this->articleID = a.articleID;
    this->articleName = a.articleName;
    this->authorID = a.authorID;
    this->journalID = a.journalID;
    this->status = a.status;
}

// Destructor

Article::~Article() = default;

// Getter and setter

void Article::setArticleID(const string &articleID) {
    this->articleID = articleID;
}

string Article::getArticleID() const {
    return this->articleID;
}

void Article::setArticleName(const string &articleName) {
    this->articleName = articleName;
}

string Article::getArticleName() const {
    return this->articleName;
}

void Article::setAuthorID(const string &authorID) {
    this->authorID = authorID;
}

string Article::getAuthorID() const {
    return this->authorID;
}

void Article::setJournalID(const string &journalID) {
    this->journalID = journalID;
}

string Article::getJournalID() const {
    return this->journalID;
}

// status working flow

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

string Article::parseString() const {
    switch (status) {
        case ArticleStatus::DRAFT: return "DRAFT";
        case ArticleStatus::SUBMITTED: return "SUBMITTED";
        case ArticleStatus::UNDER_REVIEW: return "UNDER_REVIEW";
        case ArticleStatus::REVISIONS: return "REVISIONS";
        case ArticleStatus::ACCEPTED: return "ACCEPTED";
        case ArticleStatus::REJECTED: return "REJECTED";
        case ArticleStatus::PUBLISHED: return "PUBLISHED";
        default: return "UNKNOWN";
    }
}

// abstract method

void Article::display() const {
    cout << "Article ID: " << getArticleID() << "\n"; 
    cout << "Article Name: " << getArticleName() << "\n"; 
    cout << "Article Status: " << parseString() << "\n"; 
}

// SCI
string SCIArticle::getType() const {
    return "SCI";
}

void SCIArticle::showDescription() const {
    cout << "SCI (Science Citation Index)\n"; 
    cout << "Thuoc Web of Science (Clarivate Analytics)."; 
    cout << "Bao gom nhung tap chi khoa hoc uy tin, lau doi nhat."; 
    cout << "Co Impact Factor(IF).";
    cout << "Co phan hang Quartile(Q1-Q4)."; 
    cout << "Duoc dung de danh gia nghien cuu o muc cao nhat."; 
}

void SCIArticle::display() const {
    Article::display(); // super
    cout << "Article Type: " << getType() << "\n"; 
}

// SCIE
string SCIEArticle::getType() const {
    return "SCIE";
}

void SCIEArticle::showDescription() const {
    cout << "Thuoc Web of Science."; 
    cout << "Mo rong hon SCI, bao gom nhieu tap chi hon."; 
    cout << "Co Impact Factor."; 
    cout << "Co Quartile(Q1-Q4)."; 
    cout << "Thuong gan tuong duong SCI trong nhieu he thong danh gia."; 
}

void SCIEArticle::display() const {
    Article::display(); // super 
    cout << "Article Type: " << getType() << "\n"; 
}

// ISI
string ISIArticle::getType() const {
    return "ISI";
}

void ISIArticle::showDescription() const {
    cout << "La ten cu cua he thong Web of Science."; 
    cout << "Khi noi ISI thuong chi ca SCI va SCIE.";
    cout << "Khong con la mot index doc lap."; 
    cout << "Bai bao ISI thuong la cac bai bao cu.";
}

void ISIArticle::display() const {
    Article::display(); // super 
    cout << "Article Type: " << getType() << "\n";
}

// SCOPUS
string SCOPUSArticle::getType() const {
    return "SCOPUS";
}

void SCOPUSArticle::showDescription() const {
    cout << "Do Elsevier quan ly."; 
    cout << "La he thong indexing lon, phu rong nhieu linh vuc."; 
    cout << "Co chi so rieng: CiteScore, SJR, SNIP."; 
    cout << "Co Quartile(Q1-Q4) theo linh vuc."; 
    cout << "Duoc nhieu truong va co quan nghien cuu chap nhan, nhung thuong danh gia thap hon SCI/SCIE."; 
}

void SCOPUSArticle::display() const {
    Article::display(); // super
    cout << "Article Type: " << getType() << "\n"; 
}

// OTHER
string OTHERArticle::getType() const {
    return "OTHER";
}

void OTHERArticle::showDescription() const {
    cout << "Cac bai bao / tap chi ngoai SCI, SCIE, ISI, SCOPUS."; 
    cout << "Co the la tap chi trong nuoc."; 
    cout << "Thuong khong co Impact Factor / CiteScore."; 
    cout << "Gia tri khoa hoc co the thap hon (tuy chat luong)."; 
}

void OTHERArticle::display() const {
    Article::display(); // super
    cout << "Article Type: " << getType() << "\n"; 
}

void SCIArticle::generateID(const int count) {
    articleID = getType() + "-" + to_string(count); 
}

string SCIArticle::nextID(const int count) {
    return getType() + "-" + to_string(count + 1); 
}

void SCIEArticle::generateID(const int count) {
    articleID = getType() + "-" + to_string(count);
}

string SCIEArticle::nextID(const int count) {
    return getType() + "-" + to_string(count + 1); 
}

void ISIArticle::generateID(const int count) {
    articleID = getType() + "-" + to_string(count);
}

string ISIArticle::nextID(const int count) {
    return getType() + "-" + to_string(count + 1); 
}

void SCOPUSArticle::generateID(const int count) {
    articleID = getType() + "-" + to_string(count); 
}

string SCOPUSArticle::nextID(const int count) {
    return getType() + "-" + to_string(count + 1); 
}

void OTHERArticle::generateID(const int count) {
    articleID = getType() + "-" + to_string(count); 
}

string OTHERArticle::nextID(const int count) {
    return getType() + "-" + to_string(count + 1); 
}
