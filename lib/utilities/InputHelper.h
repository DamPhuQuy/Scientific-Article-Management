#include "models/Article.h"
#include "models/Author.h" 
#include "models/Journal.h"

class DataWrapper {
public: 
	/* articles: address; *articles: real data */
	unordered_map<int, Article> *articles; 
	unordered_map<int, Author> *authors; 
	unordered_map<int, Journal> *journals; 
}; 

// abstract class 

class InputHelper {
	template <typename T> 
	static T input(DataWrapper &data); 
}; 