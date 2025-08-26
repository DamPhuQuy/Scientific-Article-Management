#include "services/DataManipulation.h"

namespace fs = std::filesystem;
bool DataManipulation::fileCheck(const fs::path &filePath, std::ifstream &in) {
    if (!fs::exists(filePath)) {
        std::cout << "ERROR: File not found: " << fs::absolute(filePath) << "\n";
        return false;
    }

    if (filePath.extension() != ".csv") {
        std::cout << "ERROR: Invalid file extension (expected .csv): " << filePath << "\n";
        return false;
    }

    in.open(filePath, std::ios::in);
    if (!in.is_open()) {
        std::cout << "ERROR: Cannot open file: " << fs::absolute(filePath) << "\n";
        return false;
    }

    return true;
}

ArticleStatus DataManipulation::parseStatus(const string &s) {
	if (s == "DRAFT") 
		return ArticleStatus::DRAFT; 
	else if (s == "SUBMITTED") 
		return ArticleStatus::SUBMITTED; 
	else if (s == "UNDER_REVIEW")
		return ArticleStatus::UNDER_REVIEW; 
	else if (s == "REVISIONS")
		return ArticleStatus::REVISIONS; 
	else if (s == "ACCEPTED") 
		return ArticleStatus::ACCEPTED;
	else if (s == "REJECTED") 
		return ArticleStatus::REJECTED; 
	else if (s == "PUBLISHED") 
		return ArticleStatus::PUBLISHED; 
	else
		throw invalid_argument("Unknown status: " + s); 
}

journalTypes DataManipulation::parseJournalType(const string &s) {
	if (s == "SCI") 
		return journalTypes::SCI; 
	else if (s == "SCIE") 
		return journalTypes::SCIE; 
	else if (s == "ISI") 
		return journalTypes::ISI; 
	else if (s == "SCOPUS") 
		return journalTypes::SCOPUS; 
	else if (s == "OTHER") 
		return journalTypes::OTHER; 
	else 
		throw invalid_argument("Unknown type: " + s);
}

vector<int> DataManipulation::parseVectorInt(const string& s) {
	// format that is parsed: [x; xx; xxx; ...]

	vector<int> result; 
	string temp = ""; 
	for (int i = 0; i < s.length(); i++) {
		char c = s.at(i); 
		if (c == '[' || c == ' ') 
			continue; 
		else if (isdigit(c)) 
			temp += c; 
		else if (c == ';' || c == ']') {
			if (!temp.empty()) {
				int element = stoi(temp); 
				result.push_back(element); 
				temp = ""; 
			} 
		}
	}

	return result;
}

// Specialization

template<> 
unordered_map<int, Article> DataManipulation::init<Article>() {
	unordered_map<int, Article> data;

	fs::path filePath = Constants::ARTICLE; 
	ifstream in; 

	if (!fileCheck(filePath, in)) {
		return data;
	} 

	string line = ""; 
	getline(in, line);

	while (getline(in, line)) {
		stringstream ss(line); 
		string token; 

		int articleID, authorID, journalID; 
		string articleName;
		ArticleStatus currStatus;

		getline(ss, token, ','); 
		articleID = stoi(token); // parse string to int

		getline(ss, articleName, ',');  

		getline(ss, token, ','); 
		authorID = stoi(token); 

		getline(ss, token, ','); 
		journalID = stoi(token); 

		getline(ss, token, ','); 
		currStatus = parseStatus(token);

		Article article(articleID, articleName, authorID, journalID, currStatus); 

		data.insert({articleID, article}); 
	}

	return data; 
}	

template<>
unordered_map<int, Author> DataManipulation::init<Author>() {
	unordered_map<int, Author> data; 

	fs::path filePath = Constants::AUTHOR; 
	ifstream in; 

	if (!fileCheck(filePath, in)) {
		return data; 
	}

	string line = ""; 
	getline(in, line); 

	while (getline(in, line)) { 
		stringstream ss(line); 
		string token; 

		int authorID, authorGender; 
		string authorName, authorEmail, dob, country; 
		vector<int> articlesID; 

		getline(ss, token, ','); 
		authorID = stoi(token); 

		getline(ss, authorName, ','); 

		getline(ss, authorEmail, ','); 

		getline(ss, dob, ','); 

		getline(ss, country, ','); 

		getline(ss, token, ','); 
		authorGender = stoi(token);

		getline(ss, token, ','); 
		articlesID = parseVectorInt(token); 

		Author author(authorID, authorName, authorEmail, dob, country, authorGender, articlesID); 

		data.insert({authorID, author}); 	
	}
	return data; 
}

template<>
unordered_map<int, Journal> DataManipulation::init<Journal>() {
	unordered_map<int, Journal> data;  

	fs::path filePath = Constants::JOURNAL;

	ifstream in; 

	if (!fileCheck(filePath, in)) {
		return data; 
	}

	string line = ""; 
	getline(in, line); 

	while (getline(in, line)) {
		stringstream ss(line); 
		string token; 

		int journalID, publishNumber; 
		string journalName, publishYear, publisher; 
		journalTypes types; 
		vector<int> articlesID;

		getline(ss, token, ','); 
		journalID = stoi(token); 

		getline(ss, journalName, ','); 

		getline(ss, token, ','); 
		types = parseJournalType(token);

		getline(ss, token, ','); 
		publishNumber = stoi(token); 

		getline(ss, publishYear, ','); 

		getline(ss, publisher, ','); 

		getline(ss, token, ',');
		articlesID = parseVectorInt(token);

		cout << "DEBUG: "; 
		for (const int &e : articlesID) {
			cout << e << " "; 
		}
		cout << "\n"; 

		Journal journal(journalID, journalName, types, publishNumber, publishYear, publisher, articlesID); 

		data.insert({journalID, journal});
	}

	return data; 
}

