#pragma once 

#include <map>
#include <iostream> 
#include <repositories/DataWrapper.h>	
#include "utilities/IOHelper.h" 
#include "services/DataManipulation.h"


using namespace std;

class JournalRepository {
private:
	DataWrapper &data;
public:
	JournalRepository(DataWrapper &data);
	~JournalRepository();

	void setJournalsMap(map<string, Journal> &journals);
	[[nodiscard]] map<string, Journal> getJournalsMap() const;

	[[nodiscard]] Journal getJournal(const string& journalID); 
	[[nodiscard]] vector<Journal> getAllJournals() const; 

	[[nodiscard]] Journal input(const string &journalID, const string &newArticleID);
	
	void showJournalDescriptionByID(map<string, Article*> articles, map<string, Author> authors, const string &journalID); 
};

