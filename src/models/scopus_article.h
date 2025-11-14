#pragma once

#include "Article.h"
#include <string>
#include <vector>
#include <memory>

using namespace std;

class SCOPUS_Article : public Article {
private:
    double sjr; // scimago journal rank
    int hIndex;
public:
    SCOPUS_Article(
        const string& abstract = "",
        const int& n_citation = 0,
        const string& title = "",
        const string& venue = "",
        const int& year = 0,
        const string& id = "",
        Type t = Type::SCOPUS,
        ArticleStatus st = ArticleStatus::DRAFT,
        const vector<string>& r = {},
        const double& rank = 0.0,
        const int& index = 0
    );
    explicit SCOPUS_Article(const Article& other);

    ~SCOPUS_Article();

    double getSJR() const { return sjr; }
    void setSJR(double s) { sjr = s; }

    int getHIndex() const { return hIndex; }
    void setHIndex(int h) { hIndex = h; }

    // utilities
    unique_ptr<Article> clone() const override;
    json to_json(const vector<string>& authors) const override;
};
