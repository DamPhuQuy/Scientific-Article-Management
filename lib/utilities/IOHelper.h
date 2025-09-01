#pragma once

#include <string>
#include <map>

using namespace std; 

class Article; 
class Author;
class Journal;

class IOHelper {
public:
	template <typename T> 
	static string chooseFromMap(const map<string, T> &data, const string &label);
};