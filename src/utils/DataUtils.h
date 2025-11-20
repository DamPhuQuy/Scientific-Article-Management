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
        const vector<string>& aus = {},
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
                t, st, refs, aus, conference_rank, location, acceptance_rate);

        case Type::SCIE:
            return std::make_unique<SCIE_Article>(
                abstract, n_citation, title, venue, year, id,
                t, st, refs, aus, impact_factor, q_rank);

        case Type::SCOPUS:
            return std::make_unique<SCOPUS_Article>(
                abstract, n_citation, title, venue, year, id,
                t, st, refs, aus, sjr, hIndex);

        default:
            return std::make_unique<OTHER_Article>(
                abstract, n_citation, title, venue, year, id,
                t, st, refs, aus);
        }
    }

    static std::unique_ptr<Article> createArticle(Article* source)
    {
        if (!source) return nullptr;

        switch (source->getType()) {
        case Type::CONFERENCE: {
            // Ép kiểu để lấy dữ liệu riêng của Conference
            const auto* src = dynamic_cast<CONFERENCE_Article*>(source);
            if (!src) return nullptr; // Safety check

            return std::make_unique<CONFERENCE_Article>(
                src->getAbstract(),
                src->getCitation(),
                src->getTitle(),
                src->getVenue(),
                src->getYear(),
                src->getId(),
                src->getType(),
                src->getStatus(),
                src->getReferences(),
                src->getAuthors(),
                src->getRank(),         // Getter riêng
                src->getLocation(),     // Getter riêng
                src->getAcceptanceRate()// Getter riêng
                );
        }

        case Type::SCIE: {
            const auto* src = dynamic_cast<SCIE_Article*>(source);
            if (!src) return nullptr;

            return std::make_unique<SCIE_Article>(
                src->getAbstract(),
                src->getCitation(),
                src->getTitle(),
                src->getVenue(),
                src->getYear(),
                src->getId(),
                src->getType(),
                src->getStatus(),
                src->getReferences(),
                src->getAuthors(),
                src->getImpactFactor(), // Getter riêng
                src->getQRank()         // Getter riêng
                );
        }

        case Type::SCOPUS: {
            const auto* src = dynamic_cast<SCOPUS_Article*>(source);
            if (!src) return nullptr;

            return std::make_unique<SCOPUS_Article>(
                src->getAbstract(),
                src->getCitation(),
                src->getTitle(),
                src->getVenue(),
                src->getYear(),
                src->getId(),
                src->getType(),
                src->getStatus(),
                src->getReferences(),
                src->getAuthors(),
                src->getSJR(),      // Getter riêng
                src->getHIndex()    // Getter riêng
                );
        }

        case Type::OTHER:
        default: {
            // Với OTHER hoặc loại chưa xác định, chỉ copy thông tin cơ bản
            return std::make_unique<OTHER_Article>(
                source->getAbstract(),
                source->getCitation(),
                source->getTitle(),
                source->getVenue(),
                source->getYear(),
                source->getId(),
                source->getType(),
                source->getStatus(),
                source->getReferences(),
                source->getAuthors()
                );
            }
        }
    }
};
