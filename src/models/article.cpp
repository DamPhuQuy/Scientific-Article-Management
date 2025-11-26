#include "article.h"
#include <algorithm>
#include <unordered_map>
#include "../utils/exception/ArticleException.h"

Article::Article(const string &abstract,
                 const int &n_citation,
                 const string &title,
                 const string &venue,
                 const int &year,
                 const string &id,
                 const Type t,
                 const ArticleStatus st,
                 const vector<string> &r,
                 const vector<string> &aus)
    : id(id),
    abstract(abstract),
    n_citation(n_citation),
    title(title),
    venue(venue),
    year(year),
    type(t),
    status(st),
    refs(r),
    authors(aus)
{}


Article::Article(const Article &other)
    : id(other.id),
    abstract(other.abstract),
    n_citation(other.n_citation),
    title(other.title),
    venue(other.venue),
    year(other.year),
    type(other.type),
    status(other.status),
    refs(other.refs),
    authors(other.authors)
{
}

string Article::typeToString(Type t) {
    static const std::unordered_map<Type, std::string> map = {
        {Type::SCIE,       "SCIE"},
        {Type::SCOPUS,     "SCOPUS"},
        {Type::CONFERENCE, "CONFERENCE"},
        {Type::OTHER,      "OTHER"},
        {Type::CUSTOM,     "CUSTOM"}
    };
    return map.count(t) ? map.at(t) : "OTHER";
}

string Article::statusToString(ArticleStatus st) {
    static const unordered_map<ArticleStatus, string> map = {
        {ArticleStatus::DRAFT,        "DRAFT"},
        {ArticleStatus::SUBMITTED,    "SUBMITTED"},
        {ArticleStatus::UNDER_REVIEW, "UNDER_REVIEW"},
        {ArticleStatus::REVISIONS,    "REVISIONS"},
        {ArticleStatus::ACCEPTED,     "ACCEPTED"},
        {ArticleStatus::REJECTED,     "REJECTED"},
        {ArticleStatus::PUBLISHED,    "PUBLISHED"}
    };
    return map.count(st) ? map.at(st) : "DRAFT";
}

string Article::getStatusInString() const {
    switch (status) {
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

void Article::setType(const any& t) {
    if (t.type() == typeid(string)) {
        string s = any_cast<string>(t);
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        static const unordered_map<string, Type> map = {
                                                        {"scie", Type::SCIE},
                                                        {"scopus", Type::SCOPUS},
                                                        {"conference", Type::CONFERENCE},
                                                        {"other", Type::OTHER},
                                                        {"custom", Type::CUSTOM}
                                                        };

        auto it = map.find(s);
        if (it != map.end()) {
            this->type = it->second;
        } else {
            throw ArticleException("Giá trị type không hợp lệ: " + s);
        }
    } else if (t.type() == typeid(int)) {
        int temp = any_cast<int>(t);
        if (temp >= 1 && temp <= 5) {
            this->type = static_cast<Type>(temp);
        } else {
            throw ArticleException("Giá trị type không hợp lệ: " + to_string(temp));
        }
    } else {
        throw ArticleException("Giá trị type không hỗ trợ!");
    }
}

void Article::setStatus(const any& st) {
    if (st.type() == typeid(string)) {
        string s = any_cast<string>(st);
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        static const unordered_map<string, ArticleStatus> map = {
            {"draft", ArticleStatus::DRAFT},
            {"submitted", ArticleStatus::SUBMITTED},
            {"under_review", ArticleStatus::UNDER_REVIEW},
            {"revisions", ArticleStatus::REVISIONS},
            {"accepted", ArticleStatus::ACCEPTED},
            {"rejected", ArticleStatus::REJECTED},
            {"published", ArticleStatus::PUBLISHED}
        };

        auto it = map.find(s);
        if (it != map.end())
            this->status = it->second;
        else
            throw ArticleException("Giá trị status không hợp lệ: " + s);
    } else if (st.type() == typeid(int)) {
        int s = any_cast<int>(st);

        // DRAFT = 11,
        //     SUBMITTED = 12,
        //     UNDER_REVIEW = 13,
        //     REVISIONS = 14,
        //     ACCEPTED = 15,
        //     REJECTED = 16,
        //     PUBLISHED = 17

        if (s >= 11 && s <= 17)
            this->status = static_cast<ArticleStatus>(s);
        else {
            throw ArticleException("Giá trị status không hợp lệ: " + std::to_string(s));
        }
    } else if (st.type() == typeid(ArticleStatus)) {
        this->status = any_cast<ArticleStatus>(st);
    } else {
        throw ArticleException("Giá trị status không hỗ trợ!");
    }
}

string Article::submit()
{
    if (this->status == ArticleStatus::DRAFT || this->status == ArticleStatus::REVISIONS)
    {
        this->status = ArticleStatus::SUBMITTED;
        return "Thành công: Trạng thái đã chuyển thành " + getStatusInString() + ".";
    }
    else
    {
        return "Lỗi: Không thể nộp bài từ trạng thái " + typeToString(type) + ".";
    }
}

string Article::startReview()
{
    if (this->status == ArticleStatus::SUBMITTED)
    {
        this->status = ArticleStatus::UNDER_REVIEW;
        return "Thành công: Trạng thái đã chuyển thành " + getStatusInString() + ".";
    }
    else
    {
        return "Lỗi: Không thể nộp bài từ trạng thái " + getStatusInString() + ".";
    }
}

string Article::requestRevisions()
{
    if (this->status == ArticleStatus::UNDER_REVIEW)
    {
        this->status = ArticleStatus::REVISIONS;
        return "Thành công: Trạng thái đã chuyển thành " + getStatusInString() + " (Cần chỉnh sửa)";
    }
    else
    {
        return "Lỗi: Không thể nộp bài từ trạng thái " + getStatusInString() + ".";
    }
}

string Article::accept()
{
    if (this->status == ArticleStatus::UNDER_REVIEW)
    {
        this->status = ArticleStatus::ACCEPTED;
        return "Thành công: Trạng thái đã chuyển thành " + getStatusInString() + ".";
    }
    else
    {
        return "Lỗi: Không thể nộp bài từ trạng thái " + getStatusInString() + ".";
    }
}

string Article::reject() {
    if (this->status == ArticleStatus::UNDER_REVIEW)
    {
        this->status = ArticleStatus::REJECTED;
        return "Thành công: Trạng thái đã chuyển thành " + getStatusInString() + ".";
    }
    else
    {
        return "Lỗi: Không thể nộp bài từ trạng thái " + getStatusInString() + ".";
    }
}

string Article::publish()
{
    if (this->status == ArticleStatus::ACCEPTED)
    {
        this->status = ArticleStatus::PUBLISHED;
        return "Thành công: Trạng thái đã chuyển thành " + getStatusInString() + ".";
    }
    else
    {
        return "Lỗi: Không thể nộp bài từ trạng thái " + getStatusInString() + ".";
    }
}
