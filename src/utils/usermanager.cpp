// usermanager.cpp
#include "usermanager.h"
#include <iostream>
#include <fstream>
#include <cctype>

using json = nlohmann::json;
using namespace std;

bool UserManager::loadUsers(json& users)
{
    ifstream file("../../data/accounts.json");
    if (!file.is_open()) {
        users = json::object();
        return true;
    }
    try {
        file >> users;
        return true;
    } catch (...) {
        users = json::object();
        return false;
    }
}

bool UserManager::saveUsers(const json& users) {
    ofstream file("../../data/accounts.json");
    if (!file.is_open()) {
        // std::cerr << "Không thể mở file accounts.json để ghi!\n";
        return false;
    }
    file << users.dump(4);
    return true;
}

bool UserManager::verifyLogin(const std::string& username, const std::string& password) {
    if (username.empty() || password.empty()) return false;

    json users;
    bool isWorked = loadUsers(users);
    for (const auto& user : users) {
        if (user.contains("username") && user.contains("password") &&
            user["username"] == username && user["password"] == password) {

            // saveSession(username);  // Lưu session
            return true;
        }
    }
    return false;
}

bool UserManager::registerUser(const string& username, const string& password) {
    if (username.empty() || password.empty()) {
        cout << "Tên đăng nhập và mật khẩu không được để trống!\n";
        return false;
    }
    json users;
    bool isWorked = loadUsers(users);
    for (const auto& user : users) {
        if (user["username"] == username) {
            cout << "Tên đăng nhập đã tồn tại!\n";
            return false;
        }
    }
    json newUser = { {"username", username}, {"password", password} };
    users.push_back(newUser);
    saveUsers(users);
    cout << "Đăng ký thành công!\n";
    return true;
}

bool UserManager::login(const string& username, const string& password) {
    json users;
    bool isWorked = loadUsers(users);
    for (const auto& user : users) {
        if (user["username"] == username && user["password"] == password) {
            cout << "Đăng nhập thành công! Chào " << username << "!\n";
            return true;
        }
    }
    cout << "Sai tên đăng nhập hoặc mật khẩu!\n";
    return false;
}

string UserManager::getPassword() {
    string password;
    char ch;
    cout << "Nhập mật khẩu: ";
    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (ch == 127 || ch == 8) {
            if (!password.empty()) {
                password.pop_back();
                cout << "\b \b";
            }
        } else if (isprint(ch)) {
            password += ch;
            cout << '*';
        }
    }
    cout << endl;
    return password;
}

bool UserManager::addUser(const QString& username, const QString& password)
{
    json users;
    if (!loadUsers(users)) return false;

    std::string user = username.toStdString();
    if (users.contains(user)) return false;

    users[user] = password.toStdString();
    return saveUsers(users);
}
