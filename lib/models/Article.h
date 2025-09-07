#pragma once

#include <string> 
#include "models/Journal.h"
#include "models/Author.h"
#include "utilities/IOHelper.h" 

using namespace std;

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
	// format id: Type-XXX (XXX: 000 - 999)
	string articleID;
	string articleName;
	string authorID; 
	string journalID; 
	Type type; 
	ArticleStatus status; 
public: 
	// constructor

	Article() = default; 
	Article(string a_id, 
            string a_name,
            string au_id,
            string j_id,
			const Type t, 
            const ArticleStatus st);
	Article(const Article &a); 

	// destructor

	virtual ~Article();

	// getter and setter

	void setArticleID(const string &articleID);
	[[nodiscard]] string getArticleID() const;

	void setArticleName(const string &articleName);
	[[nodiscard]] string getArticleName() const;

	void setAuthorID(const string &authorID);
	[[nodiscard]] string getAuthorID() const;

	void setJournalID(const string &journalID);
	[[nodiscard]] string getJournalID() const;
	
	// status working flow

	void submit(); 
	void startReview(); 
	void requestRevisions();
	void accept();
	void reject(); 
	void publish(); 

	[[nodiscard]] string parseStringStatus() const;
	[[nodiscard]] string parseStringType() const;  

	// abstract method 
	virtual void showDescription() const; 
	virtual void display() const; 

protected:
	[[nodiscard]] string getType() const;
	void generateID(const int &count);  
}; 

class SCI_Article : public Article {
public:
	SCI_Article() = default; 
	SCI_Article(const string &a_id,
		const string &a_name,
		const string &au_id,
		const string &j_id,
		const Type t = Type::SCI,
		const ArticleStatus st = ArticleStatus::DRAFT) : Article(a_id, a_name, au_id, j_id, t, st) {}

	void showDescription() const override;
	void display() const override;
};

class SCIE_Article : public Article {
public:
	SCIE_Article() = default; 
	SCIE_Article(const string &a_id,
		const string &a_name,
		const string &au_id,
		const string &j_id,
		const Type t = Type::SCIE,
		const ArticleStatus st) : Article(a_id, a_name, au_id, j_id, t, st) {}

	void showDescription() const override;
	void display() const override; 
};

class ISI_Article : public Article {
public:
	ISI_Article() = default; 
	ISI_Article(const string &a_id,
		const string &a_name,
		const string &au_id,
		const string &j_id,
		const Type t = Type::ISI, 
		const ArticleStatus st) : Article(a_id, a_name, au_id, j_id, t, st) {}

	void showDescription() const override;
	void display() const override; 
};

class SCOPUS_Article : public Article {
public:
	SCOPUS_Article() = default; 
	SCOPUS_Article(const string &a_id,
		const string &a_name,
		const string &au_id,
		const string &j_id,
		const Type t = Type::SCOPUS,
		const ArticleStatus st = ArticleStatus::DRAFT) : Article(a_id, a_name, au_id, j_id, t, st) {}

	void showDescription() const override;
	void display() const override; 
};

class OTHER_Article : public Article {
public:
	OTHER_Article() = default; 
	OTHER_Article(const string &a_id,
		const string &a_name,
		const string &au_id,
		const string &j_id,
		const Type t = Type::OTHER,
		const ArticleStatus st = ArticleStatus::DRAFT) : Article(a_id, a_name, au_id, j_id, t, st) {}

	void showDescription() const override;
	void display() const override; 
};

