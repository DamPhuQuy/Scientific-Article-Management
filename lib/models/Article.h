#pragma once

#include <string>
#include <unordered_map>


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
    // format id: TYPE-XXX (XXX: 000 - 999)
    std::string articleID;
    std::string articleName;
    std::string authorID;
    std::string journalID;
    Type type;
    ArticleStatus status;

    static const std::unordered_map<Type, std::string> TypeNames;
    static const std::unordered_map<ArticleStatus, std::string> StatusNames;

public:
    // Constructors
    Article() = default;
    Article(const std::string &a_id,
            const std::string &a_name,
            const std::string &au_id,
            const std::string &j_id,
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
    virtual void showDescription() const = 0;
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

	void showDescription() const override {

	}

	void display() const override {

	}
};

class SCIE_Article : public Article {
	SCIE_Article(
		const string &a_id,
    	const string &a_name, 
    	const string &au_id,
    	const string &j_id, 
    	ArticleStatus st = ArticleStatus::DRAFT
	); 

	void showDescription() const override {

	}

	void display() const override {

	}
};

class ISI_Article : public Article {
	ISI_Article(
		const string &a_id,
    	const string &a_name, 
    	const string &au_id,
    	const string &j_id, 
    	ArticleStatus st = ArticleStatus::DRAFT
	); 

	void showDescription() const override {

	}

	void display() const override {

	}
};

class SCOPUS_Article : public Article {
	SCOPUS_Article(
		const string &a_id,
    	const string &a_name, 
    	const string &au_id,
    	const string &j_id, 
    	ArticleStatus st = ArticleStatus::DRAFT
	); 

	void showDescription() const override {

	}

	void display() const override {

	}
};

class OTHER_Article : public Article {
	OTHER_Article(
		const string &a_id,
    	const string &a_name, 
    	const string &au_id,
    	const string &j_id, 
    	ArticleStatus st = ArticleStatus::DRAFT
	); 

	void showDescription() const override {

	}

	void display() const override {

	}
};

