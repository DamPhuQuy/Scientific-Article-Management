#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include "AuthorArticleRepo.h"
#include "UUID_Generator.h"

using namespace std;

// Type for article
enum class Type
{
    SCIE = 1,
    SCOPUS = 2,
    CONFERENCE = 3,
    OTHER = 4
};

// Show the current status
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
protected:
    string article_id;
    string abstract;
    int n_citation;
    string title;
    string venue;
    int year;
    Type type;
    ArticleStatus status;
    vector<string> refs;
    static int count;

    vector<string> wrapText(const string &text, int maxWidth = 200);
    void printAbstract(const string &abstract, int width = 200);

public:
    Article(string abstract = "",
            int n_citation = 0,
            string title = "",
            string venue = "",
            int year = 0,
            string id = UUID_Generator::generateUUID(),
            Type t = Type::OTHER,
            ArticleStatus st = ArticleStatus::DRAFT,
            const vector<string> &r = {});

    Article(const Article &other);

    virtual ~Article() = default;

    // getters
    string getId() const;
    string getArticleTitle() const;
    string getVenueName() const;
    string getAbstract() const;
    int getCitation() const;
    int getYear() const;
    Type getType();
    ArticleStatus getStatus(int order);
    vector<string>& getReferences();

    // utilities
    virtual string typeToString() const;
    string typeToString(Type type);
    virtual string statusToString() const;
    string statusToString(ArticleStatus status);
    void addReference(const string &title) { refs.push_back(title); }

    // setters
    void setArticleId(const string &id) { article_id = id; }
    void setAbstract(const string &abs) { abstract = abs; }
    void setNCitation(int n) { n_citation = n; }
    void setTitle(const string &t) { title = t; }
    void setVenue(const string &v) { venue = v; }
    void setYear(int y) { year = y; }
    void setStatus(ArticleStatus status) { this->status = status; }

    // Workflow
    void submit();
    void startReview();
    void requestRevisions();
    void accept();
    void reject();
    void publish();

    // utilities
    void virtual showDescription() = 0;
    [[nodiscard]] virtual Article *clone() const = 0;
};
