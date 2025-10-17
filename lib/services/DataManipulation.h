#pragma once

#include <string>
#include <map>
#include <vector>
#include <filesystem>
#include "ArticleReference.h"
#include "AuthorArticle.h"
#include "Article.h" 

namespace fs = std::filesystem;
using namespace std;

class DataManipulation {
private:
    static bool fileCheck(const fs::path &file_path, ifstream &in);
    static bool isNumber(const string& token); 
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
        vector<AuthorArticle>& author_article,
        vector<ArticleReference>& article_reference
    ); 
    // vector<Article*> fetchFromArticle();
    // vector<Author*> fetchFromAuthors();
};

