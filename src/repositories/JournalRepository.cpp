#include "repositories/JournalRepository.h"

JournalRepository::JournalRepository(map<string, Journal> &j) :
	journals(j) {} 

JournalRepository::~JournalRepository() {} 

void JournalRepository::setJournalsMap(map<string, Journal> &journals) {
	this->journals = journals; 
}

map<string, Journal> JournalRepository::getJournalsMap() const {
	return this->journals; 
}

Journal JournalRepository::getJournal(const string& journalID) {
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

Journal JournalRepository::input(const string &journalID, const string &newArticleID) {
	auto it = this->journals.find(journalID); 

	// neu journal da co thi them vao
	if (it != journals.end()) {
		Journal journal = it->second; 

		journal.getArticlesID().push_back(newArticleID); 

		return journal; 
	} 
	else {
		string journalName; 
		Type type; 
		int publishNumber; 
		string publishYear; 
		string publisher; 
		vector<string> articlesID; 

		// journal name
		cout << "Enter journal name: "; getline(cin, journalName); 

		// journal type
		map<int, string> journalTypesMapping = {
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

		articlesID.emplace_back(newArticleID); // add articleID to sync
	
		Journal journal(journalID, journalName, type, publishNumber, publishYear, publisher, articlesID); 

		return journal;
	}
}

void JournalRepository::showJournalDescriptionByID(map<string, Article*> articles, map<string, Author> authors, const string &journalID) {
	auto it = journals.find(journalID);

	if (it == journals.end()) {
		cout << "ERROR: " << journalID << " not found!\n"; 
		return; 
	}
	else {
		Journal journal = it->second; 
		cout << "Journal ID: " << journalID << "\n"; 
		cout << "Journal name: " << journal.getJournalName() << "\n"; 
		cout << "Journal type: " << journal.getType() << "\n"; 
		cout << "Publish Number: " << journal.getPublishNumber() << "\n"; 
		cout << "Publisher: " << journal.getPublisher() << "\n"; 
		
		vector<string> articlesID = journal.getArticlesID(); 
		cout << "Articles that " << journal.getJournalName() << " takes part in: \n"; 
		for (const string &element : articlesID) {
		    cout << "Article ID: " << element 
				 << " - Name: " << articles.at(element)->getArticleName() << "\n"; 
		}
	}
}