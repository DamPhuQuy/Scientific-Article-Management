#include "services/DataManipulation.h"
#include "models/Article.h"
#include "models/Author.h"
#include "models/Journal.h"

#include <iostream>
#include <fstream>
#include <filesystem>
#include <regex>

using namespace std;
namespace fs = std::filesystem;

Type DataManipulation::convertStringToType(const string &temp) {
    Type type;

    if (temp == "1") {
        type = Type::SCI;
    } else if (temp == "2") {
        type = Type::SCIE;
    } else if (temp == "3") {
        type = Type::ISI;
    } else if (temp == "4") {
        type = Type::SCOPUS;
    } else {
        type = Type::OTHER;
    }

    return type;
}

ArticleStatus DataManipulation::convertStringToStatus(const string &s) {
    ArticleStatus status;

    if (s == "11") {
        status = ArticleStatus::SUBMITTED;
    } else if (s == "12") {
        status = ArticleStatus::UNDER_REVIEW;
    } else if (s == "13") {
        status = ArticleStatus::REVISIONS;
    } else if (s == "14") {
        status = ArticleStatus::ACCEPTED;
    } else if (s == "16") {
        status = ArticleStatus::REJECTED;
    } else if (s == "17") {
        status = ArticleStatus::PUBLISHED;
    } else {
        status = ArticleStatus::DRAFT;
    }

    return status;
}

Article* DataManipulation::createArticle(
    const Type type,
    const string &articleID,
    const string &articleName,
    const string &authorID,
    const string &journalID,
    const ArticleStatus status) {

    switch (type) {
        case Type::SCI:      return new SCI_Article(articleID, articleName, authorID, journalID, status);
        case Type::SCIE:     return new SCIE_Article(articleID, articleName, authorID, journalID, status);
        case Type::ISI:      return new ISI_Article(articleID, articleName, authorID, journalID, status);
        case Type::SCOPUS:   return new SCOPUS_Article(articleID, articleName, authorID, journalID, status);
        default:             return new OTHER_Article(articleID, articleName, authorID, journalID, status);
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

vector<string> DataManipulation::parseString(const string &s) {
	vector<string> result;

    const regex pattern(R"([A-Z]+_\d+)"); // Pattern p = Pattern.compile()
    const auto begin = sregex_iterator(s.begin(), s.end(), pattern);
    const auto end = sregex_iterator();

    for (auto it = begin; it != end; ++it) {
        result.push_back((*it)[0].str());
    }

	return result;
}

// Specialization

template<>
map<string, Article*> DataManipulation::init<Article*>() {
    map<string, Article*> data;

    fs::path filePath = Constants::ARTICLE;
    ifstream in;

    if (!DataManipulation::fileCheck(filePath, in)) {
        return data;
    }

    string line;
    getline(in, line); // pass the first line

    while (getline(in, line)) {
        regex pattern(R"(^([A-Z]+_\d+),([^,]+),(AU_\d+),(J_\d+),([A-Z]+),([A-Z_]+)$)");
        auto begin = sregex_iterator(line.begin(), line.end(), pattern);
        auto end = sregex_iterator();

        for (auto it = begin; it != end; ++it) {
            string articleID = (*it)[1].str();
            string articleName = (*it)[2].str();
            string authorID = (*it)[3].str();
            string journalID = (*it)[4].str();
            string temp = (*it)[5].str();

            Type type = convertStringToType(temp);

            string s = (*it)[6].str();

            ArticleStatus status = convertStringToStatus(s);

            Article* newArticle = createArticle(type, articleID, articleName, authorID, journalID, status);

            data[articleID] = newArticle;
        }
    }
    return data;
}

template<>
map<string, Author> DataManipulation::init<Author>() {
    map<string, Author> data;

    fs::path filePath = Constants::AUTHOR;
    ifstream in;
    if (!DataManipulation::fileCheck(filePath, in)) {
        return data;
    }

    string line;
    getline(in, line);

    while (getline(in, line)) {
        regex pattern(R"(^(AU_\d+),([^,]+),([\w\.\-]+@[\w\.\-]+),(\d{4}-\d{2}-\d{2}),([^,]+),(\d{1}),(\[.+\])$)");
        auto begin = sregex_iterator(line.begin(), line.end(), pattern);
        auto end = sregex_iterator();

        for (auto it = begin; it != end; ++it) {
            string authorID = (*it)[1].str();
            string authorName = (*it)[2].str();
            string authorEmail = (*it)[3].str();
            string dob = (*it)[4].str();
            string country = (*it)[5].str();
            int authorGender = stoi((*it)[6].str());
            string temp = (*it)[7].str();

            vector<string> articlesIDs = parseString(temp);

            Author newAuthor(authorID, authorName, authorEmail, dob, country, authorGender, articlesIDs);

            data[authorID] = newAuthor;
        }
    }

    return data;
}

template<>
map<string, Journal> DataManipulation::init<Journal>() {
    map<string, Journal> data;

    fs::path filePath = Constants::JOURNAL;
    ifstream in;

    if (!fileCheck(filePath, in)) {
        return data;
    }

    string line;
    getline(in, line);
    while (getline(in, line)) {
        regex pattern(R"(^(J_\d+),([^,]+),([A-Z]+),(\d+),(\d+),([^,]+),(\[.+\])$)");
        auto begin = sregex_iterator(line.begin(), line.end(), pattern);
        auto end = sregex_iterator();
        for (auto it = begin; it != end; ++it) {
            string journalID = (*it)[1].str();
            string journalName = (*it)[2].str();
            Type type = convertStringToType((*it)[3].str());
            int publisherNumber = stoi((*it)[4].str());
            int year = stoi((*it)[5].str());
            string publisher = (*it)[6].str();

            string temp = (*it)[7].str();
            vector<string> articlesIDs = parseString(temp);

            Journal newJournal(journalID, journalName, type, publisherNumber, year, publisher, articlesIDs);

            data[journalID] = newJournal;
        }
    }

    return data;
}
