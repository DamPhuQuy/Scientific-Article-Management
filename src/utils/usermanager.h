// usermanager.h
#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <string>
#include "../utils/nlohmann/json.hpp"
#include <QString>

class UserManager {
public:
    static bool registerUser(const std::string& username, const std::string& password);
    static bool login(const std::string& username, const std::string& password);
    static std::string getPassword();  // trả về std::string
    static bool verifyLogin(const std::string& username, const std::string& password);
    static bool loadUsers(nlohmann::json& users);
    static bool saveUsers(const nlohmann::json& users);
    static bool addUser(const QString& username, const QString& password);
    static bool userExists(const QString& username)
    {
        nlohmann::json users;
        if (!loadUsers(users)) return false;
        return users.contains(username.toStdString());
    }
};

#endif
