#pragma once 

#include <string> 

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
	int publishID; 
	string publishName; 
	string publishYear; 
	string publisher; 
public: 
	Journal(); 
	Journal(int journalID, 
			string journalName,
			journalTypes types, 
			int publishID, 
			string publishName,
			string publishYear,
			string publisher); 
	Journal(const Journal& j); 
	~Journal(); 

	void setJournalID(int journalID);
	int getJournalID(); 

	void setJournalName(string journalName); 
	string getJournalName(); 

	void setJournalTypes(journalTypes types); 
	journalTypes getJournalTypes(); 

	void setPublishID(int publishID); 
	int getPublishID(); 

	void setPublishName(string publishName); 
	string getPublishName(); 

	void setPublishYear(string publishYear); 
	string getPublishYear(); 

	void setPublisher(string publisher); 
	string getPublisher();
};