#include "authorrepo.h"
#include "../utils/nlohmann/json.hpp"
#include "../utils/constants.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <filesystem>
#include <iomanip>
#include <exception>
#include <QDebug>
#include <QString>

using json = nlohmann::json;
namespace fs = std::filesystem;

AuthorRepo::AuthorRepo(unordered_map<string, Author> au_con)
    : authors_container(std::move(au_con)) {}

// Thêm tác giả
void AuthorRepo::add(const Author& au) {
    if (!au.getId().empty()) {
        authors_container[au.getId()] = au;
    }
}

// Xóa tác giả
void AuthorRepo::remove(const string& id) {
    authors_container.erase(id);
}

// Lấy container (non-const)
unordered_map<string, Author>& AuthorRepo::getAuthorContainer() {
    return authors_container;
}

// === Import & Export ===

// Tải dữ liệu từ file JSON
void AuthorRepo::load()
{
    const fs::path file_path = Constants::AuInfoJson;
    ifstream in(file_path);

    if (!in.is_open()) {
        qCritical() << "ERROR: Cannot open file: "
                    << QString::fromStdString(fs::absolute(file_path).string());
        return;
    }

    try {
        json data;
        in >> data;

        if (!data.is_array()) {
            qCritical() << "JSON format error: expected array of authors";
            return;
        }

        authors_container.clear();

        for (const auto& item : data)
        {
            string id      = item.value("id", "");
            string name    = item.value("fullName", "");
            string country = item.value("country", "");
            string field   = item.value("fieldOfStudy", "");
            int pubs       = item.value("totalPublications", 0);

            // id bắt buộc phải tồn tại
            if (id.empty())
                continue;

            // emplace trực tiếp, không copy tạm
            authors_container.emplace(
                id,
                Author(id, name, country, field, pubs)
            );
        }

        qInfo() << "Loaded" << authors_container.size()
                << "authors from"
                << QString::fromStdString(file_path.filename().string());
    }
    catch (const json::exception& e) {
        qCritical() << "JSON parse error:" << e.what();
    }
    catch (const exception& e) {
        qCritical() << "Error loading authors:" << e.what();
    }
}


// Lưu dữ liệu ra file JSON
void AuthorRepo::save() {
    try {
        json data = json::array();

        for (const auto& [id, author] : authors_container) {
            data.push_back({
                {"id", author.getId()},
                {"fullName", author.getFullName()},
                {"country", author.getCountry()},
                {"fieldOfStudy", author.getFieldOfStudy()},
                {"totalPublications", author.getTotalPublications()}
            });
        }

        const fs::path file_path = Constants::AuInfoJson;

        std::ofstream out(file_path, ios::trunc);
        if (!out.is_open()) {
            qCritical() << "ERROR: Cannot open file: "
                        << QString::fromStdString(fs::absolute(file_path).string());
            return;
        }

        out << setw(2) << data << endl;
        out.close();

        qInfo() << "Saved" << authors_container.size()
                << "authors to"
                << QString::fromStdString(file_path.filename().string());
    } catch (const json::exception& e) {
        qCritical() << "JSON serialization error:" << e.what();
    }
    catch (const exception& e) {
        qCritical() << "Error saving authors:" << e.what();
    }
    catch (...) {
        qCritical() << "Unknown error occurred while saving authors.";
    }
}


// === Search ===

Author AuthorRepo::findById(const string& id) const {
    auto it = authors_container.find(id);
    return (it != authors_container.end()) ? it->second : Author();
}

Author AuthorRepo::findByName(const string& name) const {
    for (const auto& [id, au] : authors_container) {
        if (au.getFullName() == name) {
            return au;
        }
    }
    return Author(); // default empty
}

Author AuthorRepo::findByCountry(const string& country) const {
    for (const auto& [id, au] : authors_container) {
        if (au.getCountry() == country) {
            return au;
        }
    }
    return Author();
}

// === Filter ===

vector<Author> AuthorRepo::filterByField(const string& field) const {
    vector<Author> res;
    for (const auto& [id, au] : authors_container) {
        if (au.getFieldOfStudy() == field) {
            res.push_back(au);
        }
    }
    return res;
}

vector<Author> AuthorRepo::filterByMinPublications(int minPubs) const {
    vector<Author> res;
    for (const auto& [id, au] : authors_container) {
        if (au.getTotalPublications() >= minPubs) {
            res.push_back(au);
        }
    }
    return res;
}

// === Sort ===

vector<Author> AuthorRepo::sortedByName(bool ascending) const {
    vector<Author> vec;
    vec.reserve(authors_container.size());
    for (const auto& [id, au] : authors_container) {
        vec.push_back(au);
    }

    std::sort(vec.begin(), vec.end(),
              [ascending](const Author& a, const Author& b) {
                  return ascending ? a.getFullName() < b.getFullName()
                                   : a.getFullName() > b.getFullName();
              });

    return vec;
}

vector<Author> AuthorRepo::sortedByPublications(bool ascending) const {
    vector<Author> vec;
    vec.reserve(authors_container.size());
    for (const auto& [id, au] : authors_container) {
        vec.push_back(au);
    }

    std::sort(vec.begin(), vec.end(),
              [ascending](const Author& a, const Author& b) {
                  return ascending ? a.getTotalPublications() < b.getTotalPublications()
                                   : a.getTotalPublications() > b.getTotalPublications();
              });

    return vec;
}

// === Update ===

void AuthorRepo::updateName(const string& id, const string& name) {
    auto it = authors_container.find(id);
    if (it != authors_container.end()) {
        it->second.setFullName(name);
    }
}

void AuthorRepo::updateCountry(const string& id, const string& country) {
    auto it = authors_container.find(id);
    if (it != authors_container.end()) {
        it->second.setCountry(country);
    }
}

void AuthorRepo::updateFieldOfStudy(const string& id, const string& field) {
    auto it = authors_container.find(id);
    if (it != authors_container.end()) {
        it->second.setFieldOfStudy(field);
    }
}

void AuthorRepo::updateTotalOfPublications(const string& id, const int& pubs) {
    auto it = authors_container.find(id);
    if (it != authors_container.end()) {
        it->second.setTotalPublications(pubs);
    }
}

// === Statistics ===

int AuthorRepo::count() const {
    return static_cast<int>(authors_container.size());
}
