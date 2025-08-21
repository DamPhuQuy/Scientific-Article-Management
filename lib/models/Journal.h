#pragma once 

#include <string> 
#include <vector> 
#include "Article.h" 

using namespace std; 

enum journalTypes {
	SCI,
	SCIE, 
	ISI, 
	SCOPUS, 
	OTHER
}; 

class Journal {
private: 
	int journalID; 
	string journalName; 
	journalTypes types; 
	int publishNumber;  
	string publishYear; 
	string publisher; 
	vector<Article> articles; 
public: 
	Journal(); 
	Journal(int journalID, string journalName, journalTypes types, int publishNumber, string publishYear, string publisher); 
	Journal(const Journal &j); 
	~Journal(); 

	void setJournalID(int journalID); 
	int getJournalID(); 

	void setJournalName(string journalName); 
	string getJournalName(); 

	void setTypes(journalTypes types); 
	journalTypes getTypes(); 

	void setPublishNumber(int publishNumber); 
	int getPublishNumber(); 

	void setPublishYear(string publishYear); 
	string getPublishYear(); 

	void setPublisher(string publisher); 
	string getPublisher(); 

	void addArticle(const Article &article); 
	vector<Article> getArticles() const;
};