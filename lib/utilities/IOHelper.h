#pragma once

#include <iostream> 
#include <string>
#include <unordered_map>
#include "models/Article.h"
#include "models/Author.h" 
#include "models/Journal.h"

using namespace std; 

class Article; 
class Author;
class Journal; 

class DataWrapper {
private:
    unordered_map<int, Article>* articles;
    unordered_map<int, Author>* authors;
    unordered_map<int, Journal>* journals;

public:
    DataWrapper(unordered_map<int, Article>* articles,
                unordered_map<int, Author>* authors,
                unordered_map<int, Journal>* journals) {
		this->articles = articles; 
		this->authors = authors; 
		this->journals = journals; 
	}

	// dereference and refer to the original data
    unordered_map<int, Article>& getArticles() { return *articles; }
    unordered_map<int, Author>& getAuthors()   { return *authors; }
    unordered_map<int, Journal>& getJournals() { return *journals; }
};

// abstract class 

class IOHelper {
public:
	template <typename T> 
	static int chooseFromMap(const unordered_map<int, T> &data, const string &label);
}; 