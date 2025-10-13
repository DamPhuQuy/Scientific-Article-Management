#pragma once

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

enum class Type {
    SCIE = 1, 
	SCOPUS = 2,
	CONFERENCE = 3, 
    OTHER = 4 
};

enum class ArticleStatus {
    DRAFT = 11,
    SUBMITTED = 12,
    UNDER_REVIEW = 13,
    REVISIONS = 14,
    ACCEPTED = 15,
    REJECTED = 16,
    PUBLISHED = 17
};

class Article {
protected:
	string article_id;
    string abstract;
	int n_citation;
	string title;
	string venue;
	int year;
	Type type;
    ArticleStatus status;
	static int count;
public:
    // Constructors
    Article(string abstract = "",
		    int n_citation = 0,
		    string title = "",
		    string venue = "",
		    int year = 0,
    		string a_id = "",
            Type t = Type::OTHER,
            ArticleStatus st = ArticleStatus::DRAFT);
	Article(const Article &other);
    virtual ~Article() = default; // virtual destructor

    // Getters
    [[nodiscard]] string getArticleID() const;
    [[nodiscard]] string getArticleTitle() const;
    [[nodiscard]] string getVenueName() const;
	[[nodiscard]] string getAbstract() const; 
	[[nodiscard]] int getCitation() const;  
	[[nodiscard]] int getYear() const;
	[[nodiscard]] string typeToString() const;
	[[nodiscard]] string statusToString() const;

    // Workflow
    void submit();
    void startReview();
    void requestRevisions();
    void accept();
    void reject();
    void publish();

    // Abstract interface
    void display() const;
	[[nodiscard]] virtual Article* clone() const = 0;
	[[nodiscard]] virtual Article* input() const = 0;
};
