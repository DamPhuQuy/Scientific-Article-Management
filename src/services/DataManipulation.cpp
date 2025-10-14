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

bool DataManipulation::fileCheck(const fs::path &filePath, ifstream &in) {
    if (!fs::exists(filePath)) {
        std::cout << "ERROR: File not found: " << fs::absolute(filePath) << "\n";
        return false;
    }

    if (filePath.extension() != ".csv") {
        std::cout << "ERROR: Invalid file extension (expected .csv): " << filePath << "\n";
        return false;
    }

    in.open(filePath, std::ios::in);
    if (!in.is_open()) {
        std::cout << "ERROR: Cannot open file: " << fs::absolute(filePath) << "\n";
        return false;
    }

    return true;
}

vector<Article*> DataManipulation::fetchFromArticle(){
    filesystem::path filePath = fs::current_path() / "data" / "articles.csv";
    ifstream in; 
    vector<Article*> articles; 

    if(!fileCheck(filePath,in)){
        cout << "khong the mo duoc du lieu articles!" << endl;
        return {};
    }
    string line;
    getline(in,line);

    while(getline(in,line)){
        stringstream ss(line);
        string abstract, title, venue, a_id;
        int n_citation, year;
        string t_str, st_str;
        Type t;
        ArticleStatus st;

        // Parse the CSV line
        getline(ss, abstract, ',');
        ss >> n_citation;
        getline(ss, title, ',');
        getline(ss, venue, ',');
        ss >> year;
        getline(ss, a_id, ',');
        getline(ss, t_str, ',');
        getline(ss, st_str, ',');

        // Convert t_str to Type enum
        if (t_str == "CONFERENCE") t = Type::CONFERENCE;
        else if (t_str == "SCIE") t = Type::SCIE;
        else if (t_str == "SCOPUS") t = Type::SCOPUS;
        else t = Type::OTHER;

        // Convert st_str to ArticleStatus enum
        if (st_str == "PUBLISHED") st = ArticleStatus::PUBLISHED;
        else if (st_str == "IN_REVIEW") st = ArticleStatus::UNDER_REVIEW;
        else st = ArticleStatus::DRAFT;

        Article* article = createArticle(abstract, n_citation, title, venue, year, a_id, t, st);
        articles.push_back(article);
    }

    return articles;
}

vector<Author*> DataManipulation::fetchFromAuthors(){
    filesystem::path filePath = fs::current_path() / "data" / "authors.csv";
    ifstream in;
    vector<Author*> authors;

    if(!fileCheck(filePath,in)){
        cout << "khong the mo duoc du lieu authors!" << endl;
        return {};
    }
    string line;
    getline(in,line);

    while(getline(in,line)){
        stringstream ss(line);
        string name, email, a_id;
        int h_index;
        getline(ss, name, ',');
        getline(ss, email, ',');
        ss >> h_index;
        getline(ss, a_id, ',');

        Author* author = new Author(name, email, h_index, a_id);
        authors.push_back(author);
    }

    return authors;
}

// Specialization
