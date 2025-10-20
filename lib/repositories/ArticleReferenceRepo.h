#pragma once
#include "ArticleReference.h"
#include <vector> 

using namespace std; 

class ArticleReferenceRepo {
private:
    vector<ArticleReference> references;
public:
    ArticleReferenceRepo() = default; 
    ArticleReferenceRepo(const vector<ArticleReference>& ref); 

    ~ArticleReferenceRepo() = default; 

    // utilities
    void addReference(const std::string& article_id, const string& reference_id); 
    vector<string> getReferencesOf(const string& article_id) const;
    vector<string> getCitedBy(const string& reference_id) const; 
};
