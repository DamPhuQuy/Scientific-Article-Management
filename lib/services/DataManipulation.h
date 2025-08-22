#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <sstream> 
#include <vector>
#include <cctype> 

#include "utilities/Constants.h"
#include "models/Article.h"
#include "models/Author.h"
#include "models/Journal.h"

using namespace std;

class DataManipulation {
private:
    static bool fileCheck(const fs::path &filePath, ifstream &in);
    static ArticleStatus parseStatus(const string &s); 
    static journalTypes parseJournalType(const string &s); 
public:
    DataManipulation() = default;
    ~DataManipulation() = default;

    template<typename T>
    static unordered_map<int, T> init(); 
};
