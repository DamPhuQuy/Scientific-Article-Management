#pragma once
#include <map>
#include "models/Author.h"
#include "models/Journal.h"
#include "models/Article.h"

class DataWrapper {
private:
    map<string, Author> &authors; 
    map<string, Journal> &journals; 
    map<string, Article*> &articles;
public:
    DataWrapper(map<string, Author> &a, map<string, Journal> &j, map<string, Article*> &ar)
        : authors(a), journals(j), articles(ar) {}

    ~DataWrapper() = default;

    const map<string, Author>& getAuthors() const {
        return this->authors; 
    }
    const map<string, Journal>& getJournals() const {
        return this->journals; 
    }
    const map<string, Article*>& getArticles() const {
        return this->articles; 
    }
};



