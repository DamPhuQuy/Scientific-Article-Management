#pragma once

#include <string> 
#include <vector>

using namespace std;

class Author {
private: 
    string authorID; 
    string authorName; 
    string authorEmail; 
    string dob; 
    string country; 
    int authorGender; 
    vector<string> articlesID; 
public: 
    Author(); 
    Author(const string& a_id,
            const string& au_name,
            const string& au_email,
            const string& au_dob,
            const string& au_country,
            const int& au_gender,
            const vector<string>& ids);
    Author(const Author &a); 
    ~Author(); 

    void setAuthorID(const string &au_id);
    [[nodiscard]] string getAuthorID() const;

    void setAuthorName(const string &au_name);
    [[nodiscard]] string getAuthorName() const;

    void setAuthorEmail(const string &au_email);
    [[nodiscard]] string getAuthorEmail() const;

    void setDob(const string &birth);
    [[nodiscard]] string getDob() const;

    void setCountry(const string &c);
    [[nodiscard]] string getCountry() const;

    void setAuthorGender(int au_g);
    [[nodiscard]] int getAuthorGender() const;

    [[nodiscard]] vector<string> getArticlesID() const;
};