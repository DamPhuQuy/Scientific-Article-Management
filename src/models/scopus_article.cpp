#include "scopus_article.h"

SCOPUS_Article::SCOPUS_Article(
    const string& abstract,
    const int& n_citation,
    const string& title,
    const string& venue,
    const int& year,
    const string& id,
    Type t,
    ArticleStatus st,
    const vector<string>& r,
    const vector<string>& aus,
    const double& rank,
    const int& index)
    : Article(
          abstract,
          n_citation,
          title,
          venue,
          year,
          id.empty() ? UUID_Generator::generateUUID() : id,
          t,
          st,
          r,
          aus), sjr(rank), hIndex(index) {}

SCOPUS_Article::~SCOPUS_Article()
{
}

SCOPUS_Article::SCOPUS_Article(const Article &other) : Article(other) {}

unique_ptr<Article> SCOPUS_Article::clone() const
{
    return make_unique<SCOPUS_Article>(*this);
}

json SCOPUS_Article::to_json() const {
    return json{
        {"id", getId()},
        {"type", static_cast<int>(getType())},
        {"title", getTitle()},
        {"abstract", getAbstract()},
        {"venue", getVenue()},
        {"year", getYear()},
        {"n_citation", getCitation()},
        {"authors", authors},
        {"references", getReferences()},
        {"status", getStatusInString()}, // nếu bạn có hàm convert

        // SCOPUS
        {"sjr", sjr},
        {"hIndex", hIndex}
    };
}
