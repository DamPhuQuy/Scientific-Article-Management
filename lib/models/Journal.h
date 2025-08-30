#pragma once 

#include <string> 
#include <vector> 
#include <iostream>

using namespace std; 

class Journal {
private: 
	string journalID; 
	string journalName; 
	Type type; 
	int publishNumber;  
	string publishYear; 
	string publisher; 
	vector<string> articlesID; 
public: 
	Journal(); 
	Journal(string j_id, 
        	string j_name,
        	Type j_type,
        	int pNum,
        	string pYear,
        	string p,
        	vector<string> ids);
	Journal(const Journal &j); 	
	~Journal(); 

	void setJournalID(int journalID); 
	string getJournalID() const; 

	void setJournalName(string journalName); 
	string getJournalName() const;

	void setType(Type type); 
	string getType() const; 

	void setPublishNumber(int publishNumber); 
	int getPublishNumber() const; 

	void setPublishYear(string publishYear); 
	string getPublishYear() const; 

	void setPublisher(string publisher); 
	string getPublisher() const;

	vector<string> getArticlesID() const; 
};