// #pragma once 

// #include <string> 


// using namespace std; 

// enum class Role {
//     AUTHOR = 1,
//     ADMIN = 2, 
//     READER = 3
// };

// enum class Status {
//     OFFLINE = 1,
//     ONLINE = 2
// };

// class User {
// protected: 
//     string username;
//     string password; 
//     Role role;
//     Status status;
// public: 
//     User(
//         string username,
//         string password, 
//         Role role = Role::READER,
//         Status status = Status::ONLINE
//     ); 

//     User(const User& user); 

//     string roleToString() const; 
//     string statusToString() const; 
// };