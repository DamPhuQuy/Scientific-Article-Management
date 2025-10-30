#include <iostream>
#include "Article.h"
#include "UUID_Generator.h"
#include <limits>

using namespace std;

int Article::count = 0;

string Article::typeToString(Type type)
{
    switch (type)
    {
    case Type::SCIE:
        return "SCIE";
    case Type::SCOPUS:
        return "SCOPUS";
    case Type::CONFERENCE:
        return "CONFERENCE";
    default:
        return "OTHER";
    }
}

string Article::statusToString() const
{
    switch (this->status)
    {
    case ArticleStatus::SUBMITTED:
        return "SUBMITTED";
    case ArticleStatus::UNDER_REVIEW:
        return "UNDER_REVIEW";
    case ArticleStatus::REVISIONS:
        return "REVISIONS";
    case ArticleStatus::ACCEPTED:
        return "ACCEPTED";
    case ArticleStatus::REJECTED:
        return "REJECTED";
    case ArticleStatus::PUBLISHED:
        return "PUBLISHED";
    default:
        return "DRAFT";
    }
}

string Article::statusToString(ArticleStatus status)
{
    switch (status)
    {
    case ArticleStatus::SUBMITTED:
        return "SUBMITTED";
    case ArticleStatus::UNDER_REVIEW:
        return "UNDER_REVIEW";
    case ArticleStatus::REVISIONS:
        return "REVISIONS";
    case ArticleStatus::ACCEPTED:
        return "ACCEPTED";
    case ArticleStatus::REJECTED:
        return "REJECTED";
    case ArticleStatus::PUBLISHED:
        return "PUBLISHED";
    default:
        return "DRAFT";
    }
}

vector<string> Article::wrapText(const string &text, int maxWidth)
{
    {
        vector<string> lines;
        string current;
        int width = 0;

        for (char c : text)
        {
            if (c == ' ' || c == '\n')
            {
                if (width + current.length() > maxWidth && !current.empty())
                {
                    lines.push_back(current);
                    current.clear();
                    width = 0;
                }
                if (c == '\n')
                {
                    lines.push_back(current);
                    current.clear();
                    width = 0;
                    continue;
                }
            }
            current += c;
            width++;

            if (width > maxWidth && c == ' ')
            {
                size_t spacePos = current.rfind(' ', current.length() - 1);
                if (spacePos != string::npos)
                {
                    lines.push_back(current.substr(0, spacePos));
                    current = current.substr(spacePos + 1);
                    width = current.length();
                }
            }
        }
        if (!current.empty())
        {
            lines.push_back(current);
        }
        return lines;
    }
}

void Article::printAbstract(const string &abstract, int width)
{
    vector<string> lines = wrapText(abstract, width);
    for (const auto &line : lines)
    {
        cout << line << endl;
    }
    cout << endl;
}

Article::Article(string abstract,
                 int n_citation,
                 string title, string venue,
                 int year,
                 string id,
                 Type t,
                 ArticleStatus st,
                 const vector<string> &r)
    : abstract(abstract),
      n_citation(n_citation),
      title(title),
      venue(venue),
      year(year),
      article_id(id),
      type(t),
      status(st),
      refs(r)
{
    ++count;
}

Article::Article(const Article &other)
    : abstract(other.abstract),
      n_citation(other.n_citation),
      title(other.title),
      venue(other.venue),
      year(other.year),
      article_id(other.article_id),
      type(other.type),
      status(other.status)
{
    ++count;
}

[[nodiscard]] string Article::getId() const
{
    return article_id;
}

[[nodiscard]] string Article::getArticleTitle() const
{
    return title;
}

[[nodiscard]] int Article::getYear() const
{
    return year;
}

Type Article::getType()
{
    return this->type;
}

ArticleStatus Article::getStatus(int order)
{
    if (order >= 11 && order <= 17)
        return static_cast<ArticleStatus>(order);
    return ArticleStatus::DRAFT;
}

vector<string> &Article::getReferences()
{
    return this->refs;
}

string Article::typeToString() const
{
    switch (this->type)
    {
    case Type::SCIE:
        return "SCIE";
    case Type::SCOPUS:
        return "SCOPUS";
    case Type::CONFERENCE:
        return "CONFERENCE";
    default:
        return "OTHER";
    }
}

[[nodiscard]] string Article::getVenueName() const
{
    return venue;
}

string Article::getAbstract() const
{
    return abstract;
}

int Article::getCitation() const
{
    return n_citation;
}

// status working flow

void Article::submit()
{
    int choice;
    cout << "ban co muon submit khong (1: co, 0: khong): ";
    cin >> choice;
    if (choice == 0)
    {
        return;
    }
    else if (choice != 1)
    {
        cout << "Lua chon khong hop le!" << endl;
        return;
    }
    else
    {
        if (this->status == ArticleStatus::DRAFT)
        {
            this->status = ArticleStatus::SUBMITTED;
        }
        cout << "Da submit thanh cong!" << endl;
    }
}

void Article::startReview()
{
    if (this->status == ArticleStatus::SUBMITTED)
    {
        this->status = ArticleStatus::UNDER_REVIEW;
    }
}

void Article::requestRevisions()
{
    if (this->status == ArticleStatus::UNDER_REVIEW)
    {
        this->status = ArticleStatus::REVISIONS;
    }
}

void Article::accept()
{
    if (this->status == ArticleStatus::REVISIONS)
    {
        this->status = ArticleStatus::ACCEPTED;
    }
    cout << "Bai bao cua ban da duoc accept !" << endl;
}

void Article::reject()
{
    if (this->status == ArticleStatus::UNDER_REVIEW || this->status == ArticleStatus::REVISIONS)
    {
        this->status = ArticleStatus::REJECTED;
    }
    cout << "Bai bao cua ban da bi reject !" << endl;
}

void Article::publish()
{
    if (this->status == ArticleStatus::ACCEPTED)
    {
        this->status = ArticleStatus::PUBLISHED;
    }
    cout << "Bai bao da duoc publish !" << endl;
}
