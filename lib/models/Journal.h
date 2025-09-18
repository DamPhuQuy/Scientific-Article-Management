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
	int publishYear;
	string publisher; 
	vector<string> articlesID; 
public: 
	Journal() = default; 
	Journal(const string &j_id,
        	const string &j_name,
        	Type j_type,
        	int pNum,
        	int pYear,
        	const string &p,
        	const vector<string> &ids);
	~Journal(); 

	void setJournalID(const string &journalID);
	string getJournalID() const; 

	void setJournalName(const string &journalName);
	string getJournalName() const;

	void setPublishNumber(const int publishNumber);
	int getPublishNumber() const; 

	void setPublishYear(const string &publishYear);
	int getPublishYear() const;

	void setPublisher(const string &publisher);
	string getPublisher() const;

	vector<string> getArticlesID() const;

	void generateID(const int &count);
	string nextID(const int &count) const;
};