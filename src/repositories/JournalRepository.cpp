#include "lib/repositories/JournalRepository.h"

JournalRepository::JournalRepository() {}

JournalRepository::JournalRepository(const unordered_map<int, Journal> &journals) {
	this->journals = journals; 
}

JournalRepository::JournalRepository(const JournalRepository &current) {
	this->journals = journals; 
}

JournalRepository::~JournalRepository() {} 

void JournalRepository::setJournalsMap(const unordered_map<int, Journal> &journals) {
	this->journals = journals; 
}

unordered_map<int, Journal> JournalRepository::getJournalsMap() const {
	return this->journals; 
}

Journal JournalRepository::getJournal(int journalID) {
	auto it = journals.find(journalID); 

	if (it != jounrals.end()) {
		cout << "Not found\n"; 
		return Journal(); 
	} else {
		return it->second;
	}
}

vector<Journal> JournalRepository::getAllJournals() const {
	vector<Journal> temp; 

	for (auto it = journals.begin(); it != journals.end(); it++) {
		temp.push_back(it->second); 
	}

	return temp; 
}
