#pragma once

class ArticleRepository {
private:
    vector<Article> articles;
public:
    ArticleRepository() = default;
    ~ArticleRepository() = default;

    void addArticle(const Article& article);
    Article getArticleById(const string& id) const;
    vector<Article> getAllArticles() const;

    void updateArticle(const Article& article);
    void deleteArticle(const string& id); 

    vector<Article> findByTitle(const string& keyword) const;

    vector<Article> findByAuthorId(const string& authorId) const;

    vector<Article> findByJournalId(const string& journalId) const;

    vector<Article> findByDateRange(Date from, Date to) const;

};