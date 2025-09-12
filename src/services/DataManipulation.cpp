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
map<int, Article> DataManipulation::init<Article>() {
	map<int, Article> data;

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

		string articleID, authorID, journalID; 
		string articleName;
		ArticleStatus currStatus;

		getline(ss, token, ','); 

		getline(ss, articleName, ',');  

		getline(ss, token, ',');  

		getline(ss, token, ',');  

		getline(ss, token, ','); 
		currStatus = parseStatus(token);

		Article article(articleID, articleName, authorID, journalID, currStatus); 

		data.insert({articleID, article}); 
	}

	return data; 
}	

template<>
map<int, Author> DataManipulation::init<Author>() {
	map<int, Author> data;

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

		string authorID; 
		int authorGender; 
		string authorName, authorEmail, dob, country; 
		vector<string> articlesID; 

		getline(ss, token, ','); 

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
map<int, Journal> DataManipulation::init<Journal>() {
	map<int, Journal> data;

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

		string journalID;
		int publishNumber; 
		string journalName, publishYear, publisher; 
		Type type; 
		vector<string> articlesID;

		getline(ss, token, ','); 
		journalID = stoi(token); 

		getline(ss, journalName, ','); 

		getline(ss, token, ','); 
		type = parseType(token);

		getline(ss, token, ','); 
		publishNumber = stoi(token); 

		getline(ss, publishYear, ','); 

		getline(ss, publisher, ','); 

		getline(ss, token, ',');
		articlesID = parseVectorInt(token);

		Journal journal(journalID, journalName, type, publishNumber, publishYear, publisher, articlesID);  

		data.insert({journalID, journal});
	}

	return data; 
}

