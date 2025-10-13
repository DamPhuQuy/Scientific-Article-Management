#pragma once
#include <map>
#include <string>
#include "models/articles/Article.h"

using namespace std;

class RepositoryManager {
private:
    map<string, Article*> articles;
    map<string, Author> authors;
    map<string, Journal> journals;
public:
    RepositoryManager() = default;
    RepositoryManager(const map<string, Article*>& _articles,
                      const map<string, Author>& _authors,
                      const map<string, Journal>& _journals);

    ~RepositoryManager();

    /* ========= Article ========= */
    void addArticle(const Article& article);
    [[nodiscard]] Article* getArticleById(const string& id) const;
    [[nodiscard]] vector<const Article*> getAllArticles() const;
    void updateArticle(const Article& article);
    void deleteArticle(const string& id);
    [[nodiscard]] vector<const Article*> findByTitle(const string &keyword) const;
    [[nodiscard]] vector<const Article*> findByAuthorId(const string& authorID) const;
    [[nodiscard]] vector<const Article*> findByJournalId(const string& journalID) const;

    /* ========= Author ========= */
    void addAuthor(const Author& author);
    [[nodiscard]] Author getAuthorById(const string& id) const;
    [[nodiscard]] vector<Author> getAllAuthors() const;
    void updateAuthor(const Author& author);
    void deleteAuthor(const string& id);
    [[nodiscard]] vector<Author> findByAuthorName(const string& keyword) const;

    /* ========= Journal ========= */ 
    void addJournal(const Journal& journal);
    [[nodiscard]] Journal getJournalById(const string& id) const;
    [[nodiscard]] vector<Journal> getAllJournals() const;
    void updateJournal(const Journal& journal);
    void deleteJournal(const string& id);
    [[nodiscard]] vector<Journal> findByName(const string& keyword) const;
    [[nodiscard]] vector<Journal> findByType(const string& type) const;
    [[nodiscard]] vector<Journal> findByYear(const int& year) const;

    // General
    template<typename T>
    unsigned int size();

    template<typename T>
    string generateID(const T& t);
};

