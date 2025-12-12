#pragma once

#include <string>
#include "../utils/uuid_generator.h"
#include "../utils/nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

class Author {
private:
    string id;
    string fullName;
    string country;
    string fieldOfStudy;
    int totalPublications;
public:

    Author(
        string id = UUID_Generator::generateUUID(),
        string fullName = "",
        string country = "",
        string fieldOfStudy = "",
        int totalPublications = 0
        );
    Author(const Author& other);

    ~Author() = default;

    // getters
    string getId() const {
        return this->id;
    }
    string getFullName() const {
        return this->fullName;
    }
    string getCountry() const {
        return this->country;
    }
    string getFieldOfStudy() const {
        return this->fieldOfStudy;
    }
    int getTotalPublications() const {
        return this->totalPublications;
    }

    // setters
    void setId(const string& newId) {
        this->id = newId;
    }
    void setFullName(const string& newFullName) {
        this->fullName = newFullName;
    }
    void setCountry(const string& newCountry) {
        this->country = newCountry;
    }
    void setFieldOfStudy(const string& newFieldOfStudy) {
        this->fieldOfStudy = newFieldOfStudy;
    }
    void setTotalPublications(int newTotal) {
        this->totalPublications = newTotal;
    }

    // convert
    json to_json() const;
};
