#pragma once

#include <string> 
#include <vector>

using namespace std;

class Author {
private:
    string id;            
    string fullName;         
    string country;           
    string fieldOfStudy;     
    int totalPublications;
public: 
    // Constructor 
    Author() = default;
    Author(
        string id, 
        string fullName = "", 
        string country = "", 
        string fieldOfStudy = "", 
        int totalPublications = 0
    ); 
    Author(const Author& other);

    // Getters
    string getId() const; 
    string getFullName() const; 
    string getCountry() const; 
    string getFieldOfStudy() const; 
    int getTotalPublications() const; 

    // Setters
    void setId(const string& newId); 
    void setFullName(const string& newFullName); 
    void setCountry(const string& newCountry); 
    void setFieldOfStudy(const string& newFieldOfStudy); 
    void setTotalPublications(int newTotal);
    void showAuthorDetails() const;
};