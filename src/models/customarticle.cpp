#include "customarticle.h"

CUSTOM_Article::CUSTOM_Article(const string& abstract,
                               const int& n_citation,
                               const string& title,
                               const string& venue,
                               const int& year,
                               const string& id,
                               Type t,
                               ArticleStatus st,
                               const vector<string>& r,
                               const vector<string>& aus,
                               const string& customTypeName)
: Article(abstract,
          n_citation,
          title,
          venue,
          year,
          id.empty() ? UUID_Generator::generateUUID() : id,
          t,
          st,
          r,
          aus), customTypeName(customTypeName) {}
