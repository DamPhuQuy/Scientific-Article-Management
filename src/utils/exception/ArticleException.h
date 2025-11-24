#pragma once

#include <exception>
#include <string>

class ArticleException : public std::exception {
private:
    std::string msg;
public:
    explicit ArticleException(const std::string& m) : msg(m) {}

    const char* what() const noexcept override {
        return msg.c_str();
    }
};
