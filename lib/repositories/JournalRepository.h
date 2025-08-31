#pragma once 

#include <map>
#include <iostream> 
#include "models/Journal.h"
#include "utilities/IOHelper.h" 
#include "services/DataManipulation.h"

using namespace std;

class JournalRepository {
private:
	map<int, Journal> *journals;
public:
	JournalRepository();
	JournalRepository(map<int, Journal> *j);
	JournalRepository(const JournalRepository &current);
	~JournalRepository();

	void setJournalsMap(map<int, Journal> *journals);
	map<int, Journal> getJournalsMap() const;

	Journal getJournal(int journalID); 
	vector<Journal> getAllJournals() const; 

	Journal input(const int &journalID, const int &newArticleID);
	
	void showJournalDescriptionByID(DataWrapper &dw, const int &journalID); 
};

