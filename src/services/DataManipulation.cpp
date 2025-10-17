#include <iostream>
#include <fstream>
#include <filesystem>
#include <regex>
#include <sstream>
#include <vector>
#include <cctype>
#include "services/DataManipulation.h"
#include "models/articles/CONFERENCE_Article.h"
#include "models/articles/SCIE_Article.h"
#include "models/articles/SCOPUS_Article.h"
#include "models/articles/OTHER_Article.h"
#include "models/articles/Author.h"
#include "utilities/Constants.h"

using namespace std;
namespace fs = std::filesystem;

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

    if (file_path.extension() != ".csv") {
        cout << "ERROR: Invalid file extension (expected .csv): " << file_path << "\n";
        return false;
    }

    in.open(file_path, std::ios::in);
    if (!in.is_open()) {
        cout << "ERROR: Cannot open file: " << fs::absolute(file_path) << "\n";
        return false;
    }

    return true;
}

void DataManipulation::parseArray(const string &line, vector<string>& AuthorArticle, vector<string>& ArticleReference) {
    regex array_pattern(R"(\[([^\]]+)\])"); // [^\]]: \] is escape character of ] so that mean [ ^\] ] 

    sregex_iterator start(line.begin(), line.end(), array_pattern); 
    sregex_iterator end; 

    int order = 0; // order of array
    for (auto it = start; it != end; ++it, order++) {
        smatch match = *it; 
        string content = match.str();
        
        regex content_pattern(R"'('([^']+)')'"); 
        sregex_iterator start_content(content.begin(), content.end(), content_pattern);
        sregex_iterator end_content; 
        for (auto it2 = start_content; it2 != end_content; ++it2) {
            smatch match2 = *it2; 
            string value = match2.str(); 
            if (order == 0) {
                AuthorArticle.emplace_back(value);
            } else if (order == 1) {
                ArticleReference.emplace_back(value); 
            }
        }
    }
}

void DataManipulation::parseAbstract(const string& line, string& abstract) {
    regex abstract_pattern(R"(\"([^.?])\")"); 

    sregex_iterator start(line.begin(), line.end(), abstract_pattern);
    sregex_iterator end;
    for (auto it = start; it != end; ++it) {
        smatch match = *it; 
        abstract = match.str(); 
    }
}

bool DataManipulation::isNumber(const string& token) {
    regex pattern(R"(^-?\d+(\.\d+)?$)"); 
    return regex_match(token, pattern); 
}

unordered_map<string, Article*> DataManipulation::fetchArticles(
    const fs::path& file_path,
    vector<string>& AuthorArticle,
    vector<string>& ArticleReference
) {
    ifstream in; 
    if (!fileCheck(file_path, in))
        cout << "Khong tim thay file!";  
        return {}; 

    string line;     
    while (getline(in, line)) {
        string abstract;
        int n_citation = 0;
        string title;
        string venue;
        int year = 0;
        string id; 
        int type = 0; 

        parseAbstract(line, abstract); 
        parseArray(line, AuthorArticle, ArticleReference);
        
        stringstream ss; 
        string token; 
        while (getline(ss, token, ',')) {
            if (token.front() == '[' && token.back() == ']') continue; 
            else if (token.front() == '"' && token.back() == '"') continue;

            int index = 0; 
            if (isNumber(token)) {
                int value = stoi(token); 
                if (index == 0) {
                    n_citation = value; 
                } else if (index == 1) {
                    year = value; 
                } else if (index == 2) {
                    type = value; 
                }
            }
            index++; 

            
        }
    }
}
