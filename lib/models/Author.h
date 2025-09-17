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
    Author(string a_id, 
                   string au_name,
                   string au_email,
                   string au_dob,
                   string au_country,
                   int au_gender,
                   vector<string> ids);  
    Author(const Author &a); 
    ~Author(); 

    void setAuthorID(const string &authorID);
    [[nodiscard]] string getAuthorID() const;

    void setAuthorName(const string &authorName);
    [[nodiscard]] string getAuthorName() const;

    void setAuthorEmail(const string &authorEmail);
    [[nodiscard]] string getAuthorEmail() const;

    void setDob(const string &dob);
    [[nodiscard]] string getDob() const;

    void setCountry(const string &country);
    [[nodiscard]] string getCountry() const;

    void setAuthorGender(int authorGender); 
    [[nodiscard]] int getAuthorGender() const;

    [[nodiscard]] vector<string> getArticlesID() const;

    void generateID(int count);

    static string nextID(int count);
};