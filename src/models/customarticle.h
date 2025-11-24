#pragma once
#include "article.h"

class CUSTOM_Article : public Article
{
private:
    string customTypeName;
public:
    CUSTOM_Article(const string& abstract = "",
                  const int& n_citation = 0,
                  const string& title = "",
                  const string& venue = "",
                  const int& year = 0,
                  const string& id = "",
                  Type t = Type::CUSTOM,
                  ArticleStatus st = ArticleStatus::DRAFT,
                  const vector<string> &r = {},
                  const vector<string>& aus = {},
                  const string& customTypeName = "");

    string getCustomTypeName() const {
        return customTypeName;
    }

    void setCustomTypeName(const string& name) {
        customTypeName = name;
    }

    std::unique_ptr<Article> clone() const override {
        return std::make_unique<CUSTOM_Article>(*this);
    }

    json to_json() const override {
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
            {"customTypeName", getCustomTypeName()}
        };
    }
};
