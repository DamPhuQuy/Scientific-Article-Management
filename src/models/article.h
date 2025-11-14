#pragma once
#include <string>
#include <vector>
#include "../utils/uuid_generator.h"
#include "../utils/exception/ArticleException.h"
#include "../utils/nlohmann/json.hpp"
#include <any>
#include <memory>

using namespace std;
using json = nlohmann::json;

enum class Type
{
    SCIE = 1,
    SCOPUS = 2,
    CONFERENCE = 3,
    OTHER = 4
};

enum class ArticleStatus
{
    DRAFT = 11,
    SUBMITTED = 12,
    UNDER_REVIEW = 13,
    REVISIONS = 14,
    ACCEPTED = 15,
    REJECTED = 16,
    PUBLISHED = 17
};

class Article
{
private:
    string id;
    string abstract;
    int n_citation;
    string title;
    string venue;
    int year;
    Type type;
    ArticleStatus status;
    vector<string> refs;
public:
    Article(const string& abstract = "",
            const int& n_citation = 0,
            const string& title = "",
            const string& venue = "",
            const int& year = 0,
            const string& id = UUID_Generator::generateUUID(),
            const Type t = Type::OTHER,
            const ArticleStatus st = ArticleStatus::DRAFT,
            const vector<string> &r = {});

    Article(const Article &other);
    virtual ~Article() = default;

    // getters
    string getId() const { return this->id; }
    string getTitle() const { return this->title; }
    string getVenue() const { return this->venue; }
    string getAbstract() const { return this->abstract; }
    int getCitation() const { return this->n_citation; }
    int getYear() const { return this->year; }

    string statusToString(ArticleStatus s);
    string typeToString(Type t);

    Type getType() const { return this->type; }
    string getTypeInString() const;

    ArticleStatus getStatus() const { return this->status; }
    string getStatusInString() const;

    vector<string> getReferences() const { return this->refs; }

    // setters
    void setTitle(const string& t) {
        this->title = t;
    }
    void setVenue(const string& v) {
        this->venue = v;
    }
    void setAbstract(const string& a) {
        this->abstract = a;
    }
    void setCitation(const int& c) {
        this->n_citation = c;
    }
    void setYear(const int& y) {
        this->year = y;
    }
    void setType(const any& t);
    void setStatus(const any& st);
    void setRefs(const vector<string>& r) {
        this->refs = r;
    }

    // workflow
    string submit();
    string startReview();
    string requestRevisions();
    string accept();
    string reject();
    string publish();

    // virtual
    virtual unique_ptr<Article> clone() const = 0;
    virtual json to_json(const vector<string>& authors) const = 0;
};
