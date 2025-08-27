#pragma once 

#include <string> 
#include <vector> 
#include <iostream>

using namespace std; 

enum class journalTypes {
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
	vector<int> articlesID; 
public: 
	Journal(); 
	Journal(int j_id, 
        	string j_name,
        	journalTypes j_type,
        	int pNum,
        	string pYear,
        	string p,
        	vector<int> ids);
	Journal(const Journal &j); 	
	~Journal(); 

	void setJournalID(int journalID); 
	int getJournalID() const; 

	void setJournalName(string journalName); 
	string getJournalName() const; 

	void setTypes(journalTypes types); 
	journalTypes getTypes() const; 

	void setPublishNumber(int publishNumber); 
	int getPublishNumber() const; 

	void setPublishYear(string publishYear); 
	string getPublishYear() const; 

	void setPublisher(string publisher); 
	string getPublisher() const;
	
	string toString(journalTypes type) const; 

	vector<int> getArticlesID() const; 
};