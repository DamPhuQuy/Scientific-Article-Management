// UserManager.h
#pragma once
#include "src/lib/hashmap.h"
#include <string>
#include <QString>

class UserManager {
private:
    struct User {
        std::string username;
        std::string password;
        std::string role;
        std::string fullname;
        std::string email;
        std::string phone;
        std::string keyManipulation;
    };

    static std::vector<User> userList;
    static HashMap<std::string, size_t> usernameToIndex;  // username → index trong vector

    static bool loadFromFile();
    static bool saveToFile();

    UserManager() = delete; // không cho tạo instance

public:

    static bool registerUser(const std::string& username="", const std::string& password="", const std::string& fullname="", const std::string& email="", const std::string& phone="", const std::string& role="User");
    static bool registerUser(const QString& u="", const QString& p="", const QString& f="", const QString& e="", const QString& ph="", const QString& r="User");

    static bool login(const std::string& username, const std::string& password);
    static bool login(const QString& username, const QString& password);

    static bool userExists(const std::string& username);
    static bool userExists(const QString& username);

    static bool changePassword(const std::string& username, const std::string& newPassword);

    static int getUserCount();

    // Fullname
    static std::string getFullName(const std::string& username);
    static QString getFullName(const QString& username);

    // Email
    static std::string getEmail(const std::string& username);
    static QString getEmail(const QString& username);

    // Phone
    static std::string getPhone(const std::string& username);
    static QString getPhone(const QString& username);

    // Key Manipulation
    static std::string getKeyManipulation(const std::string& username);
    static QString getKeyManipulation(const QString& username);
};
