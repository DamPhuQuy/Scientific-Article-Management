#include <unordered_map>
#include "lib/models/Journal.h"

using namespace std;

class JournalRepository {
private:
	unordered_map<int, Journal> journals;
public:
	JournalRepository();
	JournalRepository(const unordered_map<int, Journal> &journals);
	JournalRepository(const JournalRepository &current);
	~JournalRepository();

	void setJournalsMap(const unordered_mapd<int, Journal> &journals);
	unordered_map<int, Journal> getJournalsMap() const;

	Journal getJournal(int journalID); 
	vector<Journal> getAllJournals() const; 
};