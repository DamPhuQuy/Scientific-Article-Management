#include "other_article.h"
using namespace std;

OTHER_Article::OTHER_Article(
    const string& abstract,
    const int& n_citation,
    const string& title,
    const string& venue,
    const int& year,
    const string& id,
    Type t,
    ArticleStatus st,
    const vector<string>& r)
    : Article(
          abstract,
          n_citation,
          title,
          venue,
          year,
          id.empty() ? UUID_Generator::generateUUID() : id,
          t,
          st,
          r) {}

OTHER_Article::~OTHER_Article()
{
}

OTHER_Article::OTHER_Article(const Article &other) : Article(other) {}

unique_ptr<Article> OTHER_Article::clone() const
{
    return make_unique<OTHER_Article>(*this);
}

json OTHER_Article::to_json(const vector<string>& authors) const {
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
        {"status", getStatusInString()}
    };
}
