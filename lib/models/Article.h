#pragma once

#include <string> 
#include "Journal.h"
#include "Author.h"

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
	Article(int articleID, string articleName, Author author, Journal journal); 
	Article(const Article &a); 
	~Article(); 

	void setArticleID(int articleID); 
	int getArticleID(); 

	void setArticleName(string articleName); 
	string getArticleName(); 

	void setAuthor(Author author); 
	Author getAuthor(); 

	void setJournal(Journal journal); 
	Journal getJournal(); 

	void submit(); 
	void startReview(); 
	void requestRevisions();
	void accept();
	void reject(); 
	void publish(); 
	ArticleStatus getStatus() const;
}; 