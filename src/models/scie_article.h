#pragma once

#include "article.h"
#include <string>
#include <vector>
#include <memory>

using namespace std;

class SCIE_Article : public Article {
private:
    double impactFactor; // IF
    int qRank; // Q1, Q2, Q3, Q4
public:
    SCIE_Article(
        const string& abstract = "",
        const int& n_citation = 0,
        const string& title = "",
        const string& venue = "",
        const int& year = 0,
        const string& id = "",
        Type t = Type::SCIE,
        ArticleStatus st = ArticleStatus::DRAFT,
        const vector<string>& r = {},
        const double& iftor = 0.0,
        const int& rank = 0
    );

    explicit SCIE_Article(const Article& other);

    ~SCIE_Article() = default;

    double getImpactFactor() const { return impactFactor; }
    void setImpactFactor(double ifValue) { impactFactor = ifValue; }

    int getQRank() const { return qRank; }
    void setQRank(int q) { qRank = q; }

    // utilities
    unique_ptr<Article> clone() const override;
    json to_json(const vector<string>& authors) const override;
};
