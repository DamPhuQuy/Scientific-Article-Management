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

enum class Type {
	SCI, 
	SCIE,
	ISI,
	SCOPUS,
	OTHER
};

class Article {
protected:
	// format id: Type-XXX (XXX: 000 - 999)
	string articleID;
	string articleName;
	string authorID; 
	string journalID; 
	ArticleStatus status; 
public: 
	// constructor

	Article(); 
	Article(string a_id, 
            string a_name,
            string au_id,
            string j_id,
            ArticleStatus st);
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

	[[nodiscard]] string parseString() const;

	// abstract method 
	[[nodiscard]] virtual string getType() const;
	virtual void showDescription() const; 
	virtual void display() const; 
	virtual void generateID(int count); 
	virtual string nextID(int count); 
}; 

class SCI_Article : public Article {
private: 
	Type type{ Type::SCI };
public:
	SCI_Article(const string &a_id,
		const string &a_name,
		const string &au_id,
		const string &j_id,
		const ArticleStatus st) : Article(a_id, a_name, au_id, j_id, st) {}

	[[nodiscard]] string getType() const override;
	void showDescription() const override;
	void display() const override;
	void generateID(int count) override;
	string nextID(int count) override;
};

class SCIE_Article : public Article {
private: 
	Type type{ Type::SCIE };
public:
	SCIE_Article(const string &a_id,
		const string &a_name,
		const string &au_id,
		const string &j_id,
		const ArticleStatus st) : Article(a_id, a_name, au_id, j_id, st) {}

	[[nodiscard]] string getType() const override;

	void showDescription() const override;
	void display() const override; 
	void generateID(int count) override; 
	string nextID(int count) override;
};

class ISI_Article : public Article {
private: 
	Type type{ Type::ISI }; 
public:
	ISI_Article(const string &a_id,
		const string &a_name,
		const string &au_id,
		const string &j_id,
		const ArticleStatus st) : Article(a_id, a_name, au_id, j_id, st) {}

	[[nodiscard]] string getType() const override;

	void showDescription() const override;
	void display() const override; 
	void generateID(int count) override; 
	string nextID(int count) override;
};

class SCOPUS_Article : public Article {
private:
	Type type{ Type::SCOPUS };
public:
	SCOPUS_Article(const string &a_id,
		const string &a_name,
		const string &au_id,
		const string &j_id,
		const ArticleStatus st) : Article(a_id, a_name, au_id, j_id, st) {}

	[[nodiscard]] string getType() const override;

	void showDescription() const override;
	void display() const override; 
	void generateID(int count) override; 
	string nextID(int count) override;
};

class OTHER_Article : public Article {
private: 
	Type type{ Type::OTHER };
public:
	OTHER_Article(const string &a_id,
		const string &a_name,
		const string &au_id,
		const string &j_id,
		const ArticleStatus st) : Article(a_id, a_name, au_id, j_id, st) {}

	[[nodiscard]] string getType() const override;

	void showDescription() const override;
	void display() const override; 
	void generateID(int count) override; 
	string nextID(int count) override;
};

