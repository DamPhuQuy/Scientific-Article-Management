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

    void setAuthorID(int authorID); 
    string getAuthorID() const; 

    void setAuthorName(string authorName); 
    string getAuthorName() const; 

    void setAuthorEmail(string authorEmail); 
    string getAuthorEmail() const; 

    void setDob(string dob); 
    string getDob() const; 

    void setCountry(string country); 
    string getCountry() const; 

    void setAuthorGender(int authorGender); 
    int getAuthorGender() const; 

    vector<string> getArticlesID() const; 
};