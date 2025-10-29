#pragma once
#include "RepositoryManager.h"
#include "matplotlibcpp.h"
#include <unordered_map>
#include <map>
#include <string>
#include <vector>

namespace plt = matplotlibcpp;

class Statistics {
public:
    static void articlesByYear(RepositoryManager& repo);
    static void articlesByType(RepositoryManager& repo);
    static void authorsByCountry(RepositoryManager& repo) {
        auto& authors = repo.getAuthors().getData(); // unordered_map<string, Author>
        std::map<std::string, int> countryCount;

        for (const auto& [id, author] : authors) {
            countryCount[author.getCountry()]++;
        }

        std::vector<std::string> countries;
        std::vector<int> counts;

        for (const auto& [country, count] : countryCount) {
            countries.push_back(country);
            counts.push_back(count);
        }

        plt::figure();
        plt::bar(countries, counts);
        plt::title("Number of Authors by Country");
        plt::xlabel("Country");
        plt::ylabel("Number of Authors");
        plt::show();
    }

    static void authorsByField(RepositoryManager& repo) {
        auto& authors = repo.getAuthors().getData();
        std::map<std::string, int> fieldCount;

        for (const auto& [id, author] : authors) {
            fieldCount[author.getFieldOfStudy()]++;
        }

        std::vector<std::string> fields;
        std::vector<int> counts;

        for (const auto& [field, count] : fieldCount) {
            fields.push_back(field);
            counts.push_back(count);
        }

        plt::figure();
        plt::bar(fields, counts);
        plt::title("Number of Authors by Field of Study");
        plt::xlabel("Field");
        plt::ylabel("Number of Authors");
        plt::show();
    }

    static void topAuthorsByPublication(RepositoryManager& repo, int topN = 5) {
        auto& authors = repo.getAuthors().getData();
        std::vector<std::pair<std::string, int>> pubs;

        for (const auto& [id, author] : authors) {
            pubs.emplace_back(author.getFullName(), author.getTotalPublications());
        }

        std::sort(pubs.begin(), pubs.end(), [](const auto& a, const auto& b) {
            return b.second < a.second;
        });

        if (pubs.size() > static_cast<size_t>(topN))
            pubs.resize(topN);

        std::vector<std::string> names;
        std::vector<int> counts;

        for (const auto& [name, count] : pubs) {
            names.push_back(name);
            counts.push_back(count);
        }

        plt::figure();
        plt::bar(names, counts);
        plt::title("Top Authors by Publications");
        plt::xlabel("Author");
        plt::ylabel("Total Publications");
        plt::show();
    }
};
