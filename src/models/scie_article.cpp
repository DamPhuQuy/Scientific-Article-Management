#include "scie_article.h"
#include "src/models/article.h"


SCIE_Article::SCIE_Article(
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
    const double& iftor,
    const int& rank)
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
          aus), impactFactor(iftor), qRank(rank) {}

SCIE_Article::SCIE_Article(const Article &other) : Article(other) {}

unique_ptr<Article> SCIE_Article::clone() const
{
    return make_unique<SCIE_Article>(*this);
}

json SCIE_Article::to_json() const {
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

        // Các thuộc tính riêng của SCIE
        {"impact_factor", impactFactor},
        {"q_rank", qRank}
    };
}
