// usermanager.h
#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <string>
#include "../utils/nlohmann/json.hpp"

class UserManager {
public:
    static bool registerUser(const std::string& username, const std::string& password);
    static bool login(const std::string& username, const std::string& password);
    static std::string getPassword();  // trả về std::string
    static bool verifyLogin(const std::string& username, const std::string& password);
private:
    static nlohmann::json loadUsers();
    static void saveUsers(const nlohmann::json& users);
};

#endif
