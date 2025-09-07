#pragma once 

#include <map>
#include <iostream> 
#include <models/Article.h>
#include <models/Journal.h>
#include "utilities/IOHelper.h" 
#include "services/DataManipulation.h"
#include "models/Article.h"
#include "models/Journal.h"

using namespace std;

class JournalRepository {
private:
	map<string, Journal> &journals;
	shared_ptr<ArticleRepository*> articleRepos;
public:
	JournalRepository(map<string, Journal> &j);
	~JournalRepository();

	void setJournalsMap(map<string, Journal> &journals);
	[[nodiscard]] map<string, Journal> getJournalsMap() const;

	[[nodiscard]] Journal getJournal(const string& journalID); 
	[[nodiscard]] vector<Journal> getAllJournals() const; 

	[[nodiscard]] Journal input(const string &journalID, const string &newArticleID);
	
	void showJournalDescriptionByID(map<string, Article*> articles, map<string, Author> authors, const string &journalID); 
};

