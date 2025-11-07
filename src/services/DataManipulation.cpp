#include <iostream>

#include <filesystem>
#include <sstream>
#include <vector>
#include <cctype>
#include <iomanip> // std::quoted
#include <nlohmann/json.hpp>
#include "DataManipulation.h"
#include "CONFERENCE_Article.h"
#include "SCIE_Article.h"
#include "SCOPUS_Article.h"
#include "OTHER_Article.h"
#include "Constants.h"
#include <thread>
#include <chrono>

using namespace std::this_thread;
using namespace std::chrono_literals;
using namespace std;
namespace fs = std::filesystem;
using json = nlohmann::json;

Article* DataManipulation::createArticle(Type t) {
    switch (t) {
        case Type::CONFERENCE:      return new CONFERENCE_Article();
        case Type::SCIE:            return new SCIE_Article();
        case Type::SCOPUS:          return new SCOPUS_Article();
        default:                    return new OTHER_Article();
    }
}

Article* DataManipulation::createArticle(
    string abstract,
	int n_citation,
	string title,
	string venue,
	int year,
    string a_id,
    Type t,
    ArticleStatus st,
    const vector<string>& r) {

    switch (t) {
        case Type::CONFERENCE:      return new CONFERENCE_Article(abstract, n_citation, title, venue, year, a_id, t, st, r);
        case Type::SCIE:            return new SCIE_Article(abstract, n_citation, title, venue, year, a_id, t, st, r);
        case Type::SCOPUS:          return new SCOPUS_Article(abstract, n_citation, title, venue, year, a_id, t, st, r);
        default:                    return new OTHER_Article(abstract, n_citation, title, venue, year, a_id, t, st, r);
    }
}

bool DataManipulation::fileCheck(const fs::path &file_path, ifstream &in) {
    if (!fs::exists(file_path)) {
        cout << "ERROR: File not found: " << fs::absolute(file_path) << "\n";
        return false;
    }

    bool isCSV  = (file_path.extension() == ".csv");
    bool isJSON = (file_path.extension() == ".json");

    if (!isCSV && !isJSON) {
        std::cout << "ERROR: Invalid file extension (expected .json or .csv): "
                  << file_path << "\n";
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
    AuthorRepo& au_repo
) {
    ifstream in;
    if (!fileCheck(file_path, in))
        return;

    cout << "Loading data from the system..." << endl;
    json data;
    in >> data;
    for (auto& item : data) {

        const string& articleId = item["id"];
        for (const auto& authorName : item["authors"]) {
            string authorId = au_repo.findAuthorIdByName(authorName);
            if (!authorId.empty())
                au_ar.add(articleId, authorId);
        }

        vector<string> refs;
        for (auto element : item["references"]) {
            refs.push_back(element);
        }
        ar_repo.add(createArticle(item["abstract"],
                                  item["n_citation"],
                                  item["title"],
                                  item["venue"],
                                  item["year"],
                                  item["id"],
                                  static_cast<Type>(item["type"]),
                                  ArticleStatus::DRAFT,
                                  refs));
    }
    cout << "Successfully loaded data from " << file_path.filename() << "!\n";
    sleep_for(2s);
}

void DataManipulation::fetchAuthorInformation(const fs::path& file_path, AuthorRepo& au_repo, int option) {
    ifstream in;
    if (!fileCheck(file_path, in))
        return;

    cout << "Loading data from the system...\n";

    if (option == 1) {
        json data = json::parse(in);

        for (auto& item : data) {
            au_repo.add(Author(item["id"],
                         item["fullName"],
                         item["country"],
                         item["fieldOfStudy"],
                         item["totalPublications"]));
        }
    }
    else if (option == 2) {
        string line; getline(in, line);
        while (getline(in, line)) {
            stringstream ss(line);
            vector<string> data;
            string field;
            while(ss.good()) {
                // neu bat dau la "
                if (ss.peek() == '"') {
                    ss >> quoted(field); // doc het cho toi khi gap lai dau "
                }
                else {
                    getline(ss, field, ',');
                }
                data.push_back(field);
                if (ss.peek() == ',') ss.ignore(); // bo qua dau phay
            }

            string id;
            string name;
            string country;
            string fieldOfStudy;
            int pub = 0;

            for (int i = 0; i < data.size(); i++) {
                string value = data[i];
                switch(i) {
                    case 0:
                        id = value;
                        break;
                    case 1:
                        name = value;
                        break;
                    case 2:
                        country = value;
                        break;
                    case 3:
                        fieldOfStudy = value;
                        break;
                    case 4:
                        pub = stoi(value);
                }
            }

            au_repo.add(Author(id, name, country, fieldOfStudy, pub));
        }
    }
    cout << "Successfully loaded data from " << file_path.filename() << "!\n";
    sleep_for(2s);
}