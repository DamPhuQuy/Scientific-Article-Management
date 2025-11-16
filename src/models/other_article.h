#pragma once

#include "article.h"
#include <string>
#include <memory>
#include <vector>

using namespace std;

class OTHER_Article : public Article
{
public:
    OTHER_Article(
        const string& abstract = "",
        const int& n_citation = 0,
        const string& title = "",
        const string& venue = "",
        const int& year = 0,
        const string& id = "",
        Type t = Type::OTHER,
        ArticleStatus st = ArticleStatus::DRAFT,
        const vector<string> &r = {},
        const vector<string>& aus = {});

    explicit OTHER_Article(const Article &other);

    ~OTHER_Article();

    // utilities
    unique_ptr<Article> clone() const override;
    json to_json() const override;
};
