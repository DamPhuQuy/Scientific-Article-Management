#pragma once
#include <memory>
#include "../models/article.h"
#include "../models/conference_article.h"
#include "../models/scie_article.h"
#include "../models/scopus_article.h"
#include "../models/other_article.h"

class DataUtils {
public:
    static std::unique_ptr<Article> createArticle(
        const string& abstract = "",
        const int& n_citation = 0,
        const string& title = "",
        const string& venue = "",
        const int& year = 0,
        const string& id = "",
        Type t = Type::OTHER,
        ArticleStatus st = ArticleStatus::DRAFT,
        const vector<string>& r = {},
        const string& conference_rank = "",
        const string& l = "",
        const double& ar = 0.0,
        const double& iftor = 0.0,
        const int& Qrank = 0,
        const double& sjr = 0.0,
        const int& index = 0)
    {
        switch (t) {
        case Type::CONFERENCE:
            return std::make_unique<CONFERENCE_Article>(abstract, n_citation, title, venue, year, id, t, st, r, conference_rank, l, ar);
        case Type::SCIE:
            return std::make_unique<SCIE_Article>(abstract, n_citation, title, venue, year, id, t, st, r, iftor, Qrank);
        case Type::SCOPUS:
            return std::make_unique<SCOPUS_Article>(abstract, n_citation, title, venue, year, id, t, st, r, sjr, index);
        default:
            return std::make_unique<OTHER_Article>(abstract, n_citation, title, venue, year, id, t, st, r);
        }
    }
};
