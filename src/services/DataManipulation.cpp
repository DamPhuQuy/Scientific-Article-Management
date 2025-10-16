#include "services/DataManipulation.h"
#include "models/articles/CONFERENCE_Article.h"
#include "models/articles/SCIE_Article.h"
#include "models/articles/SCOPUS_Article.h"
#include "models/articles/OTHER_Article.h"
#include "models/articles/Author.h"
#include "utilities/Constants.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <regex>
#include <sstream>
#include <vector>

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

unordered_map<string, Article*> DataManipulation::fetchArticles(const fs::path& file_path) {
    ifstream in; 
    if (!fileCheck(file_path, in)) 
        return {}; 

    string line; 
    
    while (getline(in, line)) {
        stringstream ss;
           
        string token; 
        while (getline(ss, token, ',')) {
            if (token.front() == '"' && token.back() == '"') {
                token = token.substr(1, token.length() - 2); 

                if (token.front() == '[' && token.back() == ']') {
                    token.substr(1, token.length() - 2); 

                    regex pattern("'([^']+)'"); 
                    sregex_iterator start(token.begin(), token.end(), pattern);
                    sregex_iterator end; 
                
                    vector<string> authors; 
                    for (auto it = start; it != end; it++) {
                        authors.push_back((*it)[1].str()); 
                    }
                }
            }
        }
    }
}
