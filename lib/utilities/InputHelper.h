#include <iostream> 
#include <string>
#include <unordered_map>
#include "models/Article.h"
#include "models/Author.h" 
#include "models/Journal.h"

using namespace std; 

class DataWrapper {
public: 
	/* articles: address; *articles: real data */
	unordered_map<int, Article> *articles; 
	unordered_map<int, Author> *authors; 
	unordered_map<int, Journal> *journals; 
}; 

// abstract class 

class InputHelper {
public:
	template <typename T> 
	static int chooseFromMap(const unordered_map<int, T> &data, const string &label);
}; 