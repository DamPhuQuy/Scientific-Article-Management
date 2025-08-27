#pragma once

#include <string> 
#include <vector>

using namespace std;

class Author {
private: 
    int authorID; 
    string authorName; 
    string authorEmail; 
    string dob; 
    string country; 
    int authorGender; 
    vector<int> articlesID; 
public: 
    Author(); 
    Author(int a_id, 
                   string au_name,
                   string au_email,
                   string au_dob,
                   string au_country,
                   int au_gender,
                   vector<int> ids);  
    Author(const Author &a); 
    ~Author(); 

    void setAuthorID(int authorID); 
    int getAuthorID() const; 

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

    vector<int> getArticlesID() const; 
};