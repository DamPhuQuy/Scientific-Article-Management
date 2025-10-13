#pragma once

#include <string>
#include <map>
#include <vector>

using namespace std;

class DataManipulation {
private:
    static bool fileCheck(const fs::path &filePath, ifstream &in);
public:
    DataManipulation() = default;
    ~DataManipulation() = default;

    static Article* createArticle(string abstract = "",
		                          int n_citation = 0,
		                          string title = "",
		                          string venue = "",
		                          int year = 0,
    		                      string a_id = "",
                                  Type t = Type::OTHER,
                                  ArticleStatus st = ArticleStatus::DRAFT);

    template<typename T>
    map<string, T> init();
};

