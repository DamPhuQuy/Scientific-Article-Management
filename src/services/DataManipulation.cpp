#include "services/DataManipulation.h"
#include "models/articles/CONFERENCE_Article.h"
#include "models/articles/SCIE_Article.h"
#include "models/articles/SCOPUS_Article.h"
#include "models/articles/OTHER_Article.h"
#include "utilities/Constants.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <regex>

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

// Specialization
