#pragma once

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// Type for article
enum class Type {
    SCIE = 1, 
	SCOPUS = 2,
	CONFERENCE = 3, 
    OTHER = 4 
};

// Show the current status
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
    Article(string abstract = "",
		    int n_citation = 0,
		    string title = "",
		    string venue = "",
		    int year = 0,
            string id = "",
            Type t = Type::OTHER,
            ArticleStatus st = ArticleStatus::DRAFT);

    Article(string abstract = "",
		    int n_citation = 0,
		    string title = "",
		    string venue = "",
		    int year = 0,
            Type t = Type::OTHER,
            ArticleStatus st = ArticleStatus::DRAFT);
            
	Article(const Article &other);

    virtual ~Article() = default; 

    // getters
    [[nodiscard]] string getId() const;
    [[nodiscard]] string getArticleTitle() const;
    [[nodiscard]] string getVenueName() const;
	[[nodiscard]] string getAbstract() const; 
	[[nodiscard]] int getCitation() const;  
	[[nodiscard]] int getYear() const;
    [[nodiscard]] Type getType(int order); 
    [[nodiscard]] ArticleStatus getStatus(int order); 
    [[nodiscard]] virtual string typeToString() const; 
	[[nodiscard]] string typeToString(Type type);
    [[nodiscard]] virtual string statusToString() const;
	[[nodiscard]] string statusToString(ArticleStatus status);

    // setters
    

    // Workflow
    void submit();
    void startReview();
    void requestRevisions();
    void accept();
    void reject();
    void publish();

    // utilities
    void virtual showDescription() const = 0;
	[[nodiscard]] virtual Article* clone() const = 0;

    // input
	[[nodiscard]] virtual Article* input() const;
};
