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
    Author(int authorID, string authorName, string authorEmail, string dob, string country, int authorGender, vector<int> articlesID = {}); 
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
};