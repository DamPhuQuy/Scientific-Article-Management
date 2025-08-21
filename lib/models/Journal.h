#pragma once 

#include <string> 
#include <vector> 

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
	vector<int> articlesID; 
public: 
	Journal(); 
	Journal(int journalID, 
			string journalName, 
			journalTypes types, 
			int publishNumber, 
			string publishYear, 
			string publisher,
			vector<int> articlesID = {});
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
};