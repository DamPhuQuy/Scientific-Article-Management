#pragma once 

#include <string> 
#include <vector> 
#include <iostream>

#include "models/Article.h"

using namespace std; 

enum class Type; 

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
	Journal() = default; 
	Journal(string j_id,
        	string j_name,
        	Type j_type,
        	int pNum,
        	string pYear,
        	string p,
        	vector<string> ids);	
	~Journal(); 

	void setJournalID(const string &journalID);
	string getJournalID() const; 

	void setJournalName(const string &journalName);
	string getJournalName() const;

	void setPublishNumber(const int publishNumber);
	int getPublishNumber() const; 

	void setPublishYear(const string &publishYear);
	string getPublishYear() const; 

	void setPublisher(const string &publisher);
	string getPublisher() const;

	vector<string> getArticlesID() const;

	void generateID(const int &count);
	string nextID(const int &count) const;
};