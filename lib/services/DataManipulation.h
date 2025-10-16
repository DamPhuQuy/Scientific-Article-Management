#pragma once

#include <string>
#include <map>
#include <vector>
#include <filesystem>

namespace fs = std::filesystem;
using namespace std;

class DataManipulation {
private:
    static bool fileCheck(const fs::path &file_path, ifstream &in);
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

    unordered_map<string, Article*> fetchArticles(
        const fs::path& file_path,
        vector<string>& AuthorArticle,
        vector<string>& ArticleReference
    ); 
    vector<Article*> fetchFromArticle();
    vector<Author*> fetchFromAuthors();
};

