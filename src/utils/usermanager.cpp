// UserManager.cpp
#include "UserManager.h"
#include <fstream>
#include <QDir>
#include "src/utils/nlohmann/json.hpp"
#include "src/utils/constants.h"
#include <QDebug>

using namespace std;
using json = nlohmann::json;

vector<UserManager::User> UserManager::userList;
HashMap<string, size_t> UserManager::usernameToIndex;

bool UserManager::loadFromFile() {
    ifstream file(Constants::accountsData());
    if (!file.is_open()) {
        qCritical() << "Cannot open file for loading: " << Constants::accountsData();
        return false;
    }

    json j;
    try {
        file >> j;
        userList.clear();
        usernameToIndex.clear();

        for (size_t i = 0; i < j.size(); ++i) {
            User u;
            u.username = j[i]["username"].get<string>();
            u.password = j[i]["password"].get<string>();
            u.role = j[i]["role"].get<string>();
            u.fullname = j[i]["fullname"].get<string>();
            u.email = j[i]["email"].get<string>();
            u.phone = j[i]["phone"].get<string>();
            if (j[i].contains("keyManipulation")) {
                u.keyManipulation = j[i]["keyManipulation"].get<string>();
            } else {
                u.keyManipulation = "";
            }
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
            {"password", user.password},
            {"role", user.role},
            {"fullname", user.fullname},
            {"email", user.email},
            {"phone", user.phone},
            {"keyManipulation", user.keyManipulation}
        });
    }

    QDir().mkpath("../../../data");
    ofstream file(Constants::accountsData());
    if (!file.is_open()) return false;
    file << j.dump(4);
    return true;
}

bool UserManager::registerUser(const std::string& username, const std::string& password, const std::string& fullname, const std::string& email, const std::string& phone, const std::string& role) {
    if (username.empty() || password.empty()) return false;

    loadFromFile();
    if (usernameToIndex.containsKey(username)) return false;

    // Generate random key
    std::string key = "";
    const char charset[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < 6; ++i) {
        key += charset[rand() % (sizeof(charset) - 1)];
    }

    User newUser{username, password, role, fullname, email, phone, key};
    userList.push_back(newUser);
    usernameToIndex.put(username, userList.size() - 1);
    return saveToFile();
}

bool UserManager::registerUser(const QString& u, const QString& p, const QString& f, const QString& e, const QString& ph, const QString& r) {
    return registerUser(u.toStdString(), p.toStdString(), f.toStdString(), e.toStdString(), ph.toStdString(), r.toStdString());
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

// fullname
std::string UserManager::getFullName(const std::string& username) {
    // Kiểm tra user có tồn tại trong Hashmap không
    if (usernameToIndex.containsKey(username)) {
        size_t index = usernameToIndex.get(username); // Lấy index từ map
        return userList[index].fullname;              // Trả về dữ liệu từ vector
    }
    return ""; // Trả về rỗng nếu không tìm thấy
}

QString UserManager::getFullName(const QString& username) {
    return QString::fromStdString(getFullName(username.toStdString()));
}

// email
std::string UserManager::getEmail(const std::string& username) {
    if (usernameToIndex.containsKey(username)) {
        size_t index = usernameToIndex.get(username);
        return userList[index].email;
    }
    return "";
}

QString UserManager::getEmail(const QString& username) {
    return QString::fromStdString(getEmail(username.toStdString()));
}

// phone
std::string UserManager::getPhone(const std::string& username) {
    if (usernameToIndex.containsKey(username)) {
        size_t index = usernameToIndex.get(username);
        return userList[index].phone;
    }
    return "";
}

QString UserManager::getPhone(const QString& username) {
    return QString::fromStdString(getPhone(username.toStdString()));
}

// keyManipulation
std::string UserManager::getKeyManipulation(const std::string& username) {
    if (usernameToIndex.containsKey(username)) {
        size_t index = usernameToIndex.get(username);
        return userList[index].keyManipulation;
    }
    return "";
}

QString UserManager::getKeyManipulation(const QString& username) {
    return QString::fromStdString(getKeyManipulation(username.toStdString()));
}
