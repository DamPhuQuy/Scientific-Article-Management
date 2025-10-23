#include <iostream>

#include <filesystem>
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

void DataManipulation::fetchArticleDataSet(
    const fs::path& file_path,
    ArticleRepo& ar_repo,
    AuthorArticleRepo& au_ar,
    ArticleReferenceRepo& ar_ref
) {
    ifstream in; 
    if (!fileCheck(file_path, in)) 
        return; 

    json data;
    in >> data;

    for (auto& item : data) {
        for (auto element : item["authors"]) {
            au_ar.add(item["id"], element); 
        }
        
        for (auto element : item["references"]) {
            ar_ref.addReference(item["id"], element);  
        }

        ar_repo.add(createArticle(item["abstract"],
                                  item["n_citation"],
                                  item["title"],
                                  item["venue"],
                                  item["year"],
                                  item["id"],
                                  static_cast<Type>(item["type"]))); 
    } 
}

void DataManipulation::fetchAuthorInformation(const fs::path& file_path, AuthorRepo& au_repo) {
    ifstream in;
    if (!fileCheck(file_path, in))
        return;

    json data = json::parse(in); 

    for (auto& item : data) {
        au_repo.add(Author(item["id"],
                     item["fullName"], 
                     item["country"],
                     item["fieldOfStudy"],
                     item["totalPublications"])); 
    } 
}



void DataManipulation::findArticleByRegex(const Article *article,
    const unordered_map<string, Article*> articles_container,
    string find,
    const fs::path& file_path,
    ArticleRepo& ar_repo,
    AuthorArticleRepo& au_ar,
    ArticleReferenceRepo& ar_ref){

    regex pattern(find,regex_constants::icase);    

    DataManipulation::fetchArticleDataSet(file_path,ar_repo,au_ar,ar_ref);
    bool found = false;

    for (const auto& articleRead : ar_repo.getAll()) {
        if (regex_search(articleRead.getTitle().c_str(), pattern) ||
            regex_search(articleRead.getAbstract().c_str(), pattern) ||
            regex_search(articleRead.getVenue().c_str(), pattern)) {
            found = true;
            cout << "----------------------------------\n";
            cout << "ID: " << articleRead.getId() << "\n";
            cout << "Title: " << articleRead.getTitle() << "\n";
            cout << "Venue: " << articleRead.getVenue() << "\n";
            cout << "Year: " << articleRead.getYear() << "\n";
            cout << "Abstract: " << articleRead.getAbstract().substr(0, 100) << "...\n";
        }
    }
    if (!found){
        cout << "Khong tim thay bai bao tuong ung .\n";
    }
}


    


