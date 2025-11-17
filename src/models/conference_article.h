#pragma once

#include "article.h"
#include <string>
#include <vector>
#include <memory>

using namespace std;

class CONFERENCE_Article : public Article {
private:
    string conferenceRank;
    string location;
    double acceptanceRate;
public:
    CONFERENCE_Article(
        const string& abstract = "",
        const int& n_citation = 0,
        const string& title = "",
        const string& venue = "",
        const int& year = 0,
        const string& id = "",
        Type t = Type::CONFERENCE,
        ArticleStatus st = ArticleStatus::DRAFT,
        const vector<string>& r = {},
        const vector<string>& aus = {},
        const string& rank = "",
        const string& l = "",
        const double& ar = 0.0
        );
    explicit CONFERENCE_Article(const Article& other);

    ~CONFERENCE_Article();

    const string& getRank() const { return conferenceRank; }
    void setRank(const string& r) { conferenceRank = r; }

    const string& getLocation() const { return location; }
    void setLocation(const string& l) { location = l; }

    double getAcceptanceRate() const { return acceptanceRate; }
    void setAcceptanceRate(double rate) { acceptanceRate = rate; }

    // utilities
    unique_ptr<Article> clone() const override;
    json to_json() const override;
};
