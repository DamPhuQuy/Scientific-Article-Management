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
        int n_citation = 0,
        const string& title = "",
        const string& venue = "",
        int year = 0,
        const string& id = "",
        Type t = Type::OTHER,
        ArticleStatus st = ArticleStatus::DRAFT,
        const vector<string>& refs = {},
        const string& conference_rank = "",
        const string& location = "",
        double acceptance_rate = 0.0,
        double impact_factor = 0.0,
        int q_rank = 0,
        double sjr = 0.0,
        int hIndex = 0
        ) {
        switch (t) {
        case Type::CONFERENCE:
            return std::make_unique<CONFERENCE_Article>(
                abstract, n_citation, title, venue, year, id,
                t, st, refs, conference_rank, location, acceptance_rate);

        case Type::SCIE:
            return std::make_unique<SCIE_Article>(
                abstract, n_citation, title, venue, year, id,
                t, st, refs, impact_factor, q_rank);

        case Type::SCOPUS:
            return std::make_unique<SCOPUS_Article>(
                abstract, n_citation, title, venue, year, id,
                t, st, refs, sjr, hIndex);

        default:
            return std::make_unique<OTHER_Article>(
                abstract, n_citation, title, venue, year, id,
                t, st, refs);
        }
    }
};
