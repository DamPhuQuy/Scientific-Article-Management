// UserManager.h
#pragma once
#include "src/lib/hashmap.h"
#include <string>
#include <QString>

class UserManager {
private:
    // Dữ liệu thật: vector các user (dễ mở rộng)
    struct User {
        std::string username;
        std::string password;
        // Sau này thêm: std::string email, role, etc.
    };

    static std::vector<User> userList;
    static HashMap<std::string, size_t> usernameToIndex;  // username → index trong vector

    static bool loadFromFile();
    static bool saveToFile();

    UserManager() = delete; // không cho tạo instance

public:

    static bool registerUser(const std::string& username, const std::string& password);
    static bool registerUser(const QString& username, const QString& password);

    static bool login(const std::string& username, const std::string& password);
    static bool login(const QString& username, const QString& password);

    static bool userExists(const std::string& username);
    static bool userExists(const QString& username);

    static bool changePassword(const std::string& username, const std::string& newPassword);

    static int getUserCount();
};
