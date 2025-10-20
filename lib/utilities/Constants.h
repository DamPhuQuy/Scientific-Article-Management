#pragma once

#include <filesystem>  
#include <string> 

namespace fs = std::filesystem;
using namespace std;

class Constants {
private: 
    inline static const fs::path MODELS_PATH = "../data"; 
public: 
    static fs::path getModelsPath(const std::string &file) {
        return MODELS_PATH / file; 
    }

    // Dataset.json
    inline static const fs::path DataSet = getModelsPath("dataset.json");

    // Authors_dataset.json 
    inline static const fs::path AuthorInfo = getModelsPath("authors_dataset.json"); 
};