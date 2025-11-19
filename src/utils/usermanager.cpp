// UserManager.cpp
#include "UserManager.h"
#include <fstream>
#include <QDir>
#include "src/utils/nlohmann/json.hpp"
#include "src/utils/constants.h"

using namespace std;
using json = nlohmann::json;

vector<UserManager::User> UserManager::userList;
HashMap<string, size_t> UserManager::usernameToIndex;

bool UserManager::loadFromFile() {
    ifstream file(Constants::AccountsData);
    if (!file.is_open()) return false;

    json j;
    try {
        file >> j;
        userList.clear();
        usernameToIndex.clear();

        for (size_t i = 0; i < j.size(); ++i) {
            User u;
            u.username = j[i]["username"].get<string>();
            u.password = j[i]["password"].get<string>();
            userList.push_back(u);
            usernameToIndex.put(u.username, i);
        }
    } catch (...) {
        return false;
    }
    return true;
}

bool UserManager::saveToFile() {
    json j = json::array();
    for (const auto& user : userList) {
        j.push_back({
            {"username", user.username},
            {"password", user.password}
        });
    }

    QDir().mkpath("../../data");
    ofstream file(Constants::AccountsData);
    if (!file.is_open()) return false;
    file << j.dump(4);
    return true;
}

bool UserManager::registerUser(const string& username, const string& password) {
    if (username.empty() || password.empty()) return false;

    loadFromFile();
    if (usernameToIndex.containsKey(username)) return false;

    User newUser{username, password};
    userList.push_back(newUser);
    usernameToIndex.put(username, userList.size() - 1);
    return saveToFile();
}

bool UserManager::registerUser(const QString& u, const QString& p) {
    return registerUser(u.toStdString(), p.toStdString());
}

bool UserManager::login(const string& username, const string& password) {
    loadFromFile();

    size_t index = usernameToIndex.getOrDefault(username, SIZE_MAX);
    if (index == SIZE_MAX) return false;

    return userList[index].password == password;
}

bool UserManager::login(const QString& u, const QString& p) {
    return login(u.toStdString(), p.toStdString());
}

bool UserManager::userExists(const string& username) {
    loadFromFile();
    return usernameToIndex.containsKey(username);
}

bool UserManager::userExists(const QString& u) { // overload
    return userExists(u.toStdString());
}

bool UserManager::changePassword(const string& username, const string& newPass) {
    loadFromFile();
    size_t index = usernameToIndex.getOrDefault(username, SIZE_MAX);
    if (index == SIZE_MAX) return false;

    userList[index].password = newPass;

    return saveToFile();
}

int UserManager::getUserCount() {
    loadFromFile();
    return userList.size();
}
