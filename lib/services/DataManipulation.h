#pragma once

#include <string>
#include <unordered_map>
#include <vector>

#include "utilities/Constants.h"

using namespace std;

class DataManipulation {
private:
    static bool fileCheck(const fs::path &filePath, ifstream &in);
    static vector<string> parseString(const string &s);
public:
    DataManipulation() = default;
    ~DataManipulation() = default;

    static Type convertStringToType(const string &temp);
    static ArticleStatus convertStringToStatus(const string &s);

    static Article* createArticle(const Type type,
                                  const string& articleID,
                                  const string& articleName,
                                  const string& authorID,
                                  const string& journalID,
                                  const ArticleStatus status);
    template<typename T>
    unordered_map<string, T> init();
};

