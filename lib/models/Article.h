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

public:
    static const unordered_map<Type, string> TypeNames;
    static const unordered_map<ArticleStatus, string> StatusNames;
    // Constructors
    Article(const string &a_id,
            const string &a_name,
            const string &au_id,
            const string &j_id,
            Type t = Type::OTHER,
            ArticleStatus st = ArticleStatus::DRAFT);
	Article(const Article &other);
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
    void display() const;
	[[nodiscard]] virtual Article* clone() const = 0;
};

class SCI_Article : public Article {
public:
	SCI_Article(
		const string &a_id,
    	const string &a_name,
    	const string &au_id,
    	const string &j_id,
    	ArticleStatus st = ArticleStatus::DRAFT
	);

	explicit SCI_Article(const Article& other);

	[[nodiscard]] Article *clone() const override;
};

class SCIE_Article : public Article {
public:
	SCIE_Article(
		const string &a_id,
    	const string &a_name, 
    	const string &au_id,
    	const string &j_id, 
    	ArticleStatus st = ArticleStatus::DRAFT
	);
	explicit SCIE_Article(const Article& other);

	[[nodiscard]] Article *clone() const override;
};

class ISI_Article : public Article {
public:
	ISI_Article(
		const string &a_id,
    	const string &a_name, 
    	const string &au_id,
    	const string &j_id, 
    	ArticleStatus st = ArticleStatus::DRAFT
	);
	explicit ISI_Article(const Article& other);

	[[nodiscard]] Article *clone() const override;
};

class SCOPUS_Article : public Article {
public:
	SCOPUS_Article(
		const string &a_id,
    	const string &a_name, 
    	const string &au_id,
    	const string &j_id, 
    	ArticleStatus st = ArticleStatus::DRAFT
	);

	explicit SCOPUS_Article(const Article& other);

	[[nodiscard]] Article* clone() const override;
};

class OTHER_Article : public Article {
public:
	OTHER_Article(
		const string &a_id,
    	const string &a_name, 
    	const string &au_id,
    	const string &j_id, 
    	ArticleStatus st = ArticleStatus::DRAFT
	);

	explicit OTHER_Article(const Article& other);
	[[nodiscard]] Article* clone() const override;
};

