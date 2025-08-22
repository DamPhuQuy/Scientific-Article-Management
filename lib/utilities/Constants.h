#pragma once

#include <filesystem>  
#include <string> 

using namespace std;
namespace fs = std::filesystem;

class Constants {
private: 
	inline static const fs::path MODELS_PATH = "models/"; 

public: 
	static fs::path getModelsPath(const string &file) {
		return MODELS_PATH / file; 
	}

	inline static const fs::path ARTICLE = getModelsPath("article.csv"); 
	inline static const fs::path AUTHOR = getModelsPath("author.csv"); 
	inline static const fs::path JOURNAL = getModelsPath("journal.csv"); 
}; 