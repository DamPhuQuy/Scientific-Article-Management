// UserManager.h
#pragma once
#include "src/lib/hashmap.h"
#include <string>
#include <QString>

struct User {
    std::string username;
    std::string password;
    std::string role;
    std::string fullname;
    std::string email;
    std::string phone;
    std::string keyManipulation;
};

class UserManager {
private:
    std::vector<User> userList;
    HashMap<std::string, size_t> usernameToIndex;  // username → index

    bool loadFromFile();
    bool saveToFile();

public:
    UserManager();
    ~UserManager() = default;

    // Load/Save operations
    void load();
    void save();

    bool registerUser(const std::string& username="", const std::string& password="", const std::string& fullname="", const std::string& email="", const std::string& phone="", const std::string& role="User");
    bool registerUser(const QString& u="", const QString& p="", const QString& f="", const QString& e="", const QString& ph="", const QString& r="User");

    bool updateUserInfo(const std::string& username, const std::string& fullname, const std::string& email, const std::string& phone);
    bool updateUserInfo(const QString& username, const QString& fullname, const QString& email, const QString& phone);

    bool login(const std::string& username, const std::string& password);
    bool login(const QString& username, const QString& password);

    bool userExists(const std::string& username);
    bool userExists(const QString& username);

    bool emailExists(const std::string& email);
    bool emailExists(const QString& email);

    bool phoneExists(const std::string& phone);
    bool phoneExists(const QString& phone);

    bool changePassword(const std::string& username, const std::string& newPassword);

    int getUserCount();

    std::string getUsernameFromIdentifier(const std::string& identifier);
    QString getUsernameFromIdentifier(const QString& identifier);

    // Fullname
    std::string getFullName(const std::string& username);
    QString getFullName(const QString& username);

    void setFullName(const std::string& username, const std::string& fullname);
    void setFullName(const QString& username, const QString& fullname);

    // Email
    std::string getEmail(const std::string& username);
    QString getEmail(const QString& username);

    void setEmail(const std::string& username, const std::string& email);
    void setEmail(const QString& username, const QString& email);

    // Phone
    std::string getPhone(const std::string& username);
    QString getPhone(const QString& username);

    void setPhone(const std::string& username, const std::string& phone);
    void setPhone(const QString& username, const QString& phone);

    // Role
    std::string getRole(const std::string& username);
    QString getRole(const QString& username);

    // Key Manipulation
    std::string getKeyManipulation(const std::string& username);
    QString getKeyManipulation(const QString& username);
};
