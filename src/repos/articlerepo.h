#pragma once
#include "../models/article.h"
#include <memory>
#include <string>

using namespace std;

class ArticleRepo {
private:
    unordered_map<string, unique_ptr<Article>> articles_container;
public:
    ArticleRepo() = default;
    explicit ArticleRepo(unordered_map<string, unique_ptr<Article>>& ar_con);

    ~ArticleRepo() = default;

    void add(unique_ptr<Article> a);
    void remove(const string& articleId);

    unordered_map<string, unique_ptr<Article>>& getContainer();
    const unordered_map<string, unique_ptr<Article>>& getContainer() const; // for read

    vector<unique_ptr<Article>> getCopyAsVector() const;

    // Import and export data
    void load();
    void save();

    // Search
    unique_ptr<Article> findById(const string& id) const;
    vector<unique_ptr<Article>> findByTitle(const string& title) const;

    // Filter
    vector<unique_ptr<Article>> filterByYear(Type t) const;
    vector<unique_ptr<Article>> filterByYear(int year) const;
    vector<unique_ptr<Article>> filterByCitation(int minCitations) const;

    // Sort
    vector<unique_ptr<Article>> sortedByCitations(bool ascending=true) const;
    vector<unique_ptr<Article>> sortedByYear(bool ascending=true) const;
    vector<unique_ptr<Article>> sortedByImpactFactor(bool ascending=true) const;
    vector<unique_ptr<Article>> sortedBySJR(bool ascending=true) const;
    vector<unique_ptr<Article>> sortedByHIndex(bool ascending=true) const;

    // Update
    vector<unique_ptr<Article>>updateTitle(const string& id, const string& title);
    vector<unique_ptr<Article>>updateVenue(const string& id, const string& venue);
    vector<unique_ptr<Article>>updateYear(const string& id, const int& year);

    // Statistics
    int count() const;
    int countByType(Type t) const;
    double averageCitations() const;
};
