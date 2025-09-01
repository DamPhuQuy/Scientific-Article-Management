#pragma once

#include <filesystem>  
#include <string> 
#include "models/Article.h" 

namespace fs = std::filesystem;
using namespace std;

class Constants {
private: 
    inline static const fs::path MODELS_PATH = "data/models"; 

public: 
    static fs::path getModelsPath(const std::string &file) {
        return MODELS_PATH / file; 
    }

    inline static const fs::path ARTICLE = getModelsPath("articles.csv"); 
    inline static const fs::path AUTHOR  = getModelsPath("authors.csv"); 
    inline static const fs::path JOURNAL = getModelsPath("journals.csv"); 
};
