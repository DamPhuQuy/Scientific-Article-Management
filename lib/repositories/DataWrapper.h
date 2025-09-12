#pragma once
#include <map>
#include "models/Author.h"
#include "models/Journal.h"
#include "models/Article.h"

class DataWrapper {
public:
    map<string, Author> &authors; 
    map<string, Journal> &journals; 
    map<string, Article*> &articles;

    DataWrapper(map<string, Author> &a, map<string, Journal> &j, map<string, Article*> &ar)
        : authors(a), journals(j), articles(ar) {}

    ~DataWrapper() = default;
    
};



