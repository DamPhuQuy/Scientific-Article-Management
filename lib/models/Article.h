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
private: 
	int articleID;
	string articleName;
	int authorID; 
	int journalID; 
	ArticleStatus status; 
public: 
	Article(); 
	Article(int a_id, 
                 	 string a_name,
                 	 int au_id,
                 	 int j_id,
                 	 ArticleStatus st);
	Article(const Article &a); 
	~Article(); 

	void setArticleID(int articleID); 
	int getArticleID() const; 

	void setArticleName(string articleName); 
	string getArticleName() const; 

	void setAuthorID(int authorID); 
	int getAuthorID() const; 

	void setJournalID(int journalID); 
	int getJournalID() const; 
	
	void submit(); 
	void startReview(); 
	void requestRevisions();
	void accept();
	void reject(); 
	void publish(); 
	ArticleStatus getStatus() const;
	string parseString();
}; 