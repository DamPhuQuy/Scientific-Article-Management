#pragma once

#include <string>
#include <map>
#include <vector>
#include <filesystem>
#include "ArticleRepo.h" 
#include "AuthorRepo.h"
#include "ArticleReference.h"
#include "AuthorArticle.h"
#include "ArticleReferenceRepo.h"
#include "AuthorArticleRepo.h"
#include "Article.h" 

namespace fs = std::filesystem;
using namespace std;

class DataManipulation {
private:
    // Assist 
    static bool fileCheck(const fs::path &file_path, ifstream &in);
    static bool isNumber(const string& token); 
public:
    DataManipulation() = default;
    ~DataManipulation() = default;

    // Assist to create article depending on Type
    static Article* createArticle(string abstract = "",
		                          int n_citation = 0,
		                          string title = "",
		                          string venue = "",
		                          int year = 0,
    		                      string a_id = "",
                                  Type t = Type::OTHER,
                                  ArticleStatus st = ArticleStatus::DRAFT);

    // Fetch data from file 
    void fetchArticleDataSet(
        const fs::path& file_path,
        ArticleRepo& ar_repo,
        AuthorArticleRepo& au_ar,
        ArticleReferenceRepo& ar_ref
    );
    void fetchAuthorInformation(const fs::path &file_path, AuthorRepo& au_repo);
};

