#pragma once
#include <string>

using namespace std;

class AuthorArticle {
private:
    string article_id;
    string author_id;
public:
    AuthorArticle() = default;
    AuthorArticle(const string& article_id, const string& author_id)
        : article_id(article_id), author_id(author_id) {}
    ~AuthorArticle() = default;

    // getters
    string getArticleId() const { return article_id; }
    string getAuthorId() const { return author_id; }

    // setters
    void setArticleId(const string& a_id) {
        article_id = a_id;
    }

    void setAuthorId(const string& au_id) {
        author_id = au_id;
    }
};

