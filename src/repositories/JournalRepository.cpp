#include "repositories/JournalRepository.h"

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

	if (it == journals.end()) {
		cout << "ERROR: " << journalID << " not found!\n"; 
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

Journal JournalRepository::input(const int &journalID, const int &newArticleID) {
	auto it = this->journals.find(journalID); 

	if (it != journals.end()) {
		Journal journal = it->second; 

		journal.getArticlesID().push_back(newArticleID); 

		return journal; 
	} 
	else {
		string journalName; 
		journalTypes type; 
		int publishNumber; 
		string publishYear; 
		string publisher; 
		vector<int> articlesID; 

		// journal name
		cout << "Enter journal name: "; getline(cin, journalName); 

		// journal type
		unordered_map<int, string> journalTypesMapping = {
			{0, "SCI"}, 
			{1, "SCIE"},
			{2, "ISI"},
			{3, "SCOPUS"},
			{4, "OTHER"}
		};

		cout << "List of journal types: \n"; 
		for (auto it = journalTypesMapping.begin(); it != journalTypesMapping.end(); it++) {
			cout << it->first << " - Type: " << it->second << "\n"; 
		}
		cout << "Enter type of journal: "; 
		int choice; cin >> choice; cin.ignore(); 
		type = DataManipulation::parseJournalType(journalTypesMapping.at(choice)); 

		// publish number
		cout << "Enter publish number: "; cin >> publishNumber; cin.ignore(); 

		// publish year
		cout << "Enter publish year: "; 
		getline(cin, publishYear); 

		// publisher
		cout << "Enter publisher: "; 
		getline(cin, publisher); 

		articlesID.push_back(newArticleID); 
	
		Journal journal(journalID, journalName, type, publishNumber, publishYear, publisher, articlesID); 

		return journal;
	}
}