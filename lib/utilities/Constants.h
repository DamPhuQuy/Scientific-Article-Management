#pragma once

#include <filesystem>  
#include <string> 
#include <vector> 

namespace fs = std::filesystem;
using namespace std;

class Constants {
private: 
    inline static const fs::path MODELS_PATH = "../data"; 
public: 
    static fs::path getModelsPath(const std::string &file) {
        return MODELS_PATH / file; 
    }

    inline static fs::path DataSetCsv = getModelsPath("dataset.csv"); 

    inline static fs::path DataSetJson = getModelsPath("dataset.json"); 

    inline static fs::path AuInfoCsv = getModelsPath("authors_dataset.csv"); 

    inline static fs::path AuInfoJson = getModelsPath("authors_dataset.json"); 
};