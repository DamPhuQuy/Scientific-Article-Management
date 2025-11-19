#pragma once
#include "../models/article.h"
#include "../lib/hashmap.h"
#include <memory>
#include <string>

using namespace std;

class ArticleRepo {
private:
    HashMap<string, shared_ptr<Article>> articles_container;
public:
    ArticleRepo() = default;
    explicit ArticleRepo(HashMap<string, shared_ptr<Article>>&& ar_con);

    ~ArticleRepo() = default;

    void add(shared_ptr<Article> a);
    void remove(const string& articleId);

    HashMap<string, shared_ptr<Article>>& getContainer();
    const HashMap<string, shared_ptr<Article>>& getContainer() const; // for read

    vector<shared_ptr<Article>> getCopyAsVector() const;

    // Import and export data
    void load();
    void save();

    // Search
    shared_ptr<Article> findById(const string& id);
    vector<shared_ptr<Article>> findByTitle(const string& title) const;

    // Filter
    vector<shared_ptr<Article>> filterByYear(Type t) const;
    vector<shared_ptr<Article>> filterByYear(int year) const;
    vector<shared_ptr<Article>> filterByCitation(int minCitations) const;

    // Sort
    vector<shared_ptr<Article>> sortedByCitations(bool ascending=true) const;
    vector<shared_ptr<Article>> sortedByYear(bool ascending=true) const;
    vector<shared_ptr<Article>> sortedByImpactFactor(bool ascending=true) const;
    vector<shared_ptr<Article>> sortedBySJR(bool ascending=true) const;
    vector<shared_ptr<Article>> sortedByHIndex(bool ascending=true) const;

    // Update
    vector<shared_ptr<Article>>updateTitle(const string& id, const string& title);
    vector<shared_ptr<Article>>updateVenue(const string& id, const string& venue);
    vector<shared_ptr<Article>>updateYear(const string& id, const int& year);

    // Statistics
    unsigned int count() const;
    int countByType(Type t) const;
    double averageCitations() const;
};
