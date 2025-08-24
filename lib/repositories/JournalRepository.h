#pragma once 

#include <unordered_map>
#include <iostream> 
#include "models/Journal.h"
#include "utilities/IOHelper.h" 
#include "services/DataManipulation.h"

using namespace std;

class JournalRepository {
private:
	unordered_map<int, Journal> *journals;
public:
	JournalRepository();
	JournalRepository(unordered_map<int, Journal> *journals);
	JournalRepository(const JournalRepository &current);
	~JournalRepository();

	void setJournalsMap(unordered_map<int, Journal> *journals);
	unordered_map<int, Journal> getJournalsMap() const;

	Journal getJournal(int journalID); 
	vector<Journal> getAllJournals() const; 

	Journal input(const int &journalID, const int &newArticleID); 
};

