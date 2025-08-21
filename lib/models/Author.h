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
    int getAuthorID(); 

    void setAuthorName(string authorName); 
    string getAuthorName(); 

    void setAuthorEmail(string authorEmail); 
    string getAuthorEmail(); 

    void setDob(string dob); 
    string getDob(); 

    void setCountry(string country); 
    string getCountry(); 

    void setAuthorGender(int authorGender); 
    int getAuthorGender(); 
};