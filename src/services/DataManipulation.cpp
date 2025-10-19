#include <iostream>
#include <fstream>
#include <filesystem>
#include <regex>
#include <sstream>
#include <vector>
#include <cctype>
#include <stack> 
#include <nlohmann/json.hpp>
#include "DataManipulation.h"
#include "CONFERENCE_Article.h"
#include "SCIE_Article.h"
#include "SCOPUS_Article.h"
#include "OTHER_Article.h"
#include "Constants.h"
#include "ArticleReferenceRepo.h"
#include "AuthorArticleRepo.h" 

using namespace std;
namespace fs = std::filesystem;
using json = nlohmann::json;

Article* DataManipulation::createArticle(
    string abstract,
	int n_citation,
	string title,
	string venue,
	int year,
    string a_id,
    Type t,
    ArticleStatus st) {

    switch (t) {
        case Type::CONFERENCE:      return new CONFERENCE_Article(abstract, n_citation, title, venue, year, a_id, t, st);
        case Type::SCIE:            return new SCIE_Article(abstract, n_citation, title, venue, year, a_id, t, st);
        case Type::SCOPUS:          return new SCOPUS_Article(abstract, n_citation, title, venue, year, a_id, t, st);
        default:                    return new OTHER_Article(abstract, n_citation, title, venue, year, a_id, t, st);
    }
}

bool DataManipulation::fileCheck(const fs::path &file_path, ifstream &in) {
    if (!fs::exists(file_path)) {
        cout << "ERROR: File not found: " << fs::absolute(file_path) << "\n";
        return false;
    }

    if (file_path.extension() != ".json") {
        cout << "ERROR: Invalid file extension (expected.json): " << file_path << "\n";
        return false;
    }

    in.open(file_path, std::ios::in);
    if (!in.is_open()) {
        cout << "ERROR: Cannot open file: " << fs::absolute(file_path) << "\n";
        return false;
    }

    return true;
}

bool DataManipulation::isNumber(const string& token) {
    regex pattern(R"(^-?\d+(\.\d+)?$)"); 
    return regex_match(token, pattern); 
}

unordered_map<string, Article*> DataManipulation::fetchArticles(
    const fs::path& file_path,
    vector<AuthorArticle>& author_article,
    vector<ArticleReference>& article_reference
) {
    ifstream in; 
    if (!fileCheck(file_path, in)) 
        return {}; 

    unordered_map<string, Article*> store; 

    json data;
    in >> data;

    for (auto& item : data) {
        for (auto element : item["authors"]) {
            AuthorArticle temp(item["id"], element); 
            author_article.push_back(temp); 
        }
        
        for (auto element : item["references"]) {
            ArticleReference temp(item["id"], element); 
            article_reference.push_back(temp); 
        }
        store[item["id"]] = createArticle(item["abstract"],
                                          item["n_citation"],
                                          item["title"],
                                          item["venue"],
                                          item["year"],
                                          item["id"],
                                          static_cast<Type>(item["type"])
        );
    }
    
    return store; 
}

unordered_map<string, Author> DataManipulation::fetchAuthorInformation(const fs::path& file_path) {
    ifstream in;
    if (!fileCheck(file_path, in))
        return {};

    unordered_map<string, Author> info;  
    json data = json::parse(in); 

    for (auto& item : data) {
        info[item["id"]] = Author(item["id"],
                                  item["fullName"], 
                                  item["country"],
                                  item["fieldOfStudy"],
                                  item["totalPublications"]); 
    }

    return info; 
}