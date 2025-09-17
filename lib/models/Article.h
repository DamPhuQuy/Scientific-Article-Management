#pragma once

#include <string>
#include <unordered_map>

using namespace std;

enum class Type {
    SCI,
    SCIE,
    ISI,
    SCOPUS,
    OTHER
};

enum class ArticleStatus {
    DRAFT,
    SUBMITTED,
    UNDER_REVIEW,
    REVISIONS,
    ACCEPTED,
    REJECTED,
    PUBLISHED
};

class Article {
protected:
    string articleID;
    string articleName;
    string authorID;
    string journalID;
    Type type;
    ArticleStatus status;

    static const unordered_map<Type, string> TypeNames;
    static const unordered_map<ArticleStatus, string> StatusNames;

public:
    // Constructors
    Article() = default;
    Article(const string &a_id,
            const string &a_name,
            const string &au_id,
            const string &j_id,
            Type t,
            ArticleStatus st);

    virtual ~Article() = default; // virtual destructor

    // Getters
    [[nodiscard]] string getArticleID() const;
    [[nodiscard]] string getArticleName() const;
    [[nodiscard]] string getAuthorID() const;
    [[nodiscard]] string getJournalID() const;
    [[nodiscard]] Type getType() const { return type; }
    [[nodiscard]] ArticleStatus getStatus() const { return status; }

    // Helpers
    [[nodiscard]] string getTypeName() const;
    [[nodiscard]] string getStatusName() const;

    // Workflow
    void submit();
    void startReview();
    void requestRevisions();
    void accept();
    void reject();
    void publish();

    // Abstract interface
    virtual void display() const = 0;

protected:
    void generateID(const int &count);
};

class SCI_Article : public Article {
	SCI_Article(
		const string &a_id,
    	const string &a_name,
    	const string &au_id,
    	const string &j_id,
    	ArticleStatus st = ArticleStatus::DRAFT
	);
};

class SCIE_Article : public Article {
	SCIE_Article(
		const string &a_id,
    	const string &a_name, 
    	const string &au_id,
    	const string &j_id, 
    	ArticleStatus st = ArticleStatus::DRAFT
	);
};

class ISI_Article : public Article {
	ISI_Article(
		const string &a_id,
    	const string &a_name, 
    	const string &au_id,
    	const string &j_id, 
    	ArticleStatus st = ArticleStatus::DRAFT
	);
};

class SCOPUS_Article : public Article {
	SCOPUS_Article(
		const string &a_id,
    	const string &a_name, 
    	const string &au_id,
    	const string &j_id, 
    	ArticleStatus st = ArticleStatus::DRAFT
	);
};

class OTHER_Article : public Article {
	OTHER_Article(
		const string &a_id,
    	const string &a_name, 
    	const string &au_id,
    	const string &j_id, 
    	ArticleStatus st = ArticleStatus::DRAFT
	);
};

