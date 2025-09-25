#pragma once 

#include <string> 
#include <vector> 
#include <iostream>
#include "models/Article.h"

using namespace std; 

enum class Type; 

class Journal {
private: 
	string journalID; 
	string journalName; 
	Type type = Type::OTHER;
	int publishNumber{};
	int publishYear{};
	string publisher; 
	vector<string> articlesID; 
public: 
	Journal() = default;
	Journal(string j_id,
        	string j_name,
        	Type j_type,
        	int pNum,
        	int pYear,
        	string p,
        	const vector<string> &ids);
	~Journal(); 

	void setJournalID(const string &j_id);
	[[nodiscard]] string getJournalID() const;

	void setJournalName(const string &j_name);
	[[nodiscard]] string getJournalName() const;

	void setPublishNumber(int pNum);
	[[nodiscard]] int getPublishNumber() const;

	void setPublishYear(const int &pYear);
	[[nodiscard]] int getPublishYear() const;

	static string getJournalType(const Type type) {
		return Article::TypeNames.at(type);
	}

	void setPublisher(const string &p);
	[[nodiscard]] string getPublisher() const;

	[[nodiscard]] vector<string> getArticlesID() const;
	string getTypeName() const;
};