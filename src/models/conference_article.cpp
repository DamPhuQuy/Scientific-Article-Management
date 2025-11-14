#include "conference_article.h"

CONFERENCE_Article::CONFERENCE_Article(
    const string& abstract,
    const int& n_citation,
    const string& title,
    const string& venue,
    const int& year,
    const string& id,
    Type t,
    ArticleStatus st,
    const vector<string>& r, const string &rank, const string &l, const double &ar)
    : Article(
          abstract,
          n_citation,
          title,
          venue,
          year,
          id.empty() ? UUID_Generator::generateUUID() : id,
          t,
          st,
          r), conferenceRank(rank), location(l), acceptanceRate(ar) {}

CONFERENCE_Article::~CONFERENCE_Article() {}

CONFERENCE_Article::CONFERENCE_Article(const Article &other) : Article(other) {}

unique_ptr<Article> CONFERENCE_Article::clone() const
{
    return make_unique<CONFERENCE_Article>(*this);
}

json CONFERENCE_Article::to_json(const vector<string>& authors) const {
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
        {"status", getStatusInString()},
        {"conference_rank", conferenceRank},
        {"location", location},
        {"acceptance_rate", acceptanceRate}
    };
}
