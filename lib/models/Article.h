#pragma once

#include <string> 
#include "Journal.h"
#include "Author.h"

using namespace std;

class Article {
private: 
	int articleID;
	string articleName;
	Author author; 
	Journal journal; 
public: 
	Article(); 
	Article(int articleID, string articleName, Author author, Journal journal); 
	Article(const Article &a); 
	~Article(); 

	void setArticleID(int articleID); 
	int getArticleID(); 

	void setArticleName(string articleName); 
	string getArticleName(); 

	void setAuthor(Author author); 
	Author getAuthor(); 

	void setJournal(Journal journal); 
	Journal getJournal(); 
}; 