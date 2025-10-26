#include <iostream>
#include "Article.h"
#include "UUID_Generator.h" 

using namespace std;

int Article::count = 0; 

string Article::typeToString(Type type) {
    switch (type) {
        case Type::SCIE:       return "SCIE";
        case Type::SCOPUS:     return "SCOPUS";
        case Type::CONFERENCE: return "CONFERENCE";
        default:               return "OTHER";
    }
}

string Article::statusToString() const
{
    switch(this->status) {
        case ArticleStatus::SUBMITTED:     return "SUBMITTED";
        case ArticleStatus::UNDER_REVIEW:  return "UNDER_REVIEW";
        case ArticleStatus::REVISIONS:     return "REVISIONS";
        case ArticleStatus::ACCEPTED:      return "ACCEPTED";
        case ArticleStatus::REJECTED:      return "REJECTED";
        case ArticleStatus::PUBLISHED:     return "PUBLISHED";
        default:                           return "DRAFT";
    }
}

string Article::statusToString(ArticleStatus status) {
    switch(status) {
        case ArticleStatus::SUBMITTED:     return "SUBMITTED";
        case ArticleStatus::UNDER_REVIEW:  return "UNDER_REVIEW";
        case ArticleStatus::REVISIONS:     return "REVISIONS";
        case ArticleStatus::ACCEPTED:      return "ACCEPTED";
        case ArticleStatus::REJECTED:      return "REJECTED";
        case ArticleStatus::PUBLISHED:     return "PUBLISHED";
        default:                           return "DRAFT";
    }
}

Article::Article(string abstract,
                int n_citation,
                string title, string venue,
                int year,
                string id,
                Type t,
                ArticleStatus st)
    : abstract(abstract),
      n_citation(n_citation),
      title(title),
      venue(venue),
      year(year),
      article_id(id),
      type(t),
      status(st) {
    ++count; 
}

Article::Article(string abstract,
                int n_citation,
                string title, string venue,
                int year,
                Type t,
                ArticleStatus st)
    : abstract(abstract),
      n_citation(n_citation),
      title(title),
      venue(venue),
      year(year),
      type(t),
      status(st) {
    ++count; 
    article_id = UUID_Generator::generateUUID();
}

Article::Article(const Article &other)
    : abstract(other.abstract),
      n_citation(other.n_citation),
      title(other.title),
      venue(other.venue),
      year(other.year),
      article_id(other.article_id),
      type(other.type),
      status(other.status) {
    ++count; 
}

[[nodiscard]] string Article::getId() const {
    return article_id;
}

[[nodiscard]] string Article::getArticleTitle() const {
    return title;
}

[[nodiscard]] int Article::getYear() const
{
    return year;
}

Type Article::getType(int order)
{
    if (order >= 1 && order <= 4)
        return static_cast<Type>(order);
    return Type::OTHER;
}

ArticleStatus Article::getStatus(int order) {
    if (order >= 11 && order <= 17)
        return static_cast<ArticleStatus>(order); 
    return ArticleStatus::DRAFT; 
}

string Article::typeToString() const 
{
    switch (this->type) {
        case Type::SCIE:       return "SCIE";
        case Type::SCOPUS:     return "SCOPUS";
        case Type::CONFERENCE: return "CONFERENCE";
        default:               return "OTHER";
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

void Article::submit() {
    int choice; 
    cout << "ban co muon submit khong (1: co, 0: khong): ";
    cin >> choice;
    if (choice == 0) {
        return; 
    }
    else if(choice != 1) {
        cout << "Lua chon khong hop le!" << endl; 
        return; 
    }
    else{
        if (this->status == ArticleStatus::DRAFT) {
            this->status = ArticleStatus::SUBMITTED;
        }
        cout<<"Da submit thanh cong!"<<endl; 
    }
}

void Article::startReview() {
    if (this->status == ArticleStatus::SUBMITTED) {
        this->status = ArticleStatus::UNDER_REVIEW; 
    }
}

void Article::requestRevisions() {
    if (this->status == ArticleStatus::UNDER_REVIEW) {
        this->status = ArticleStatus::REVISIONS;
    }
}

void Article::accept() {
    if (this->status == ArticleStatus::REVISIONS) {
        this->status = ArticleStatus::ACCEPTED; 
    }
    cout<<"Bai bao cua ban da duoc accept !"<<endl;
}

void Article::reject() {
    if (this->status == ArticleStatus::UNDER_REVIEW || this->status == ArticleStatus::REVISIONS) {
        this->status = ArticleStatus::REJECTED; 
    }
    cout<<"Bai bao cua ban da bi reject !"<<endl;
}

void Article::publish() {
    if (this->status == ArticleStatus::ACCEPTED) {
        this->status = ArticleStatus::PUBLISHED; 
    }
    cout<<"Bai bao da duoc publish !"<<endl;
}

Article *Article::input() const
{
    // Article* new_article; 
    // cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    // cout << "Nhap tieu de bai bao: ";
    // getline(cin, title);

    // cout << "Nhap tom tat (abstract): ";
    // getline(cin, abstract);

    // cout << "Nhap noi xuat ban (venue): ";
    // getline(cin, venue);

    // do {
    //     cout << "Nhap nam xuat ban: ";
    //     cin >> year;
    //     if (cin.fail() || year < 0 || year > 2025) {
    //         cout << "Nam khong hop le. Vui long nhap lai.\n";
    //         cin.clear();
    //         cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //     } else {
    //         break;
    //     }
    // } while (true);

    // do {
    //     cout << "Nhap so luong trich dan: ";
    //     cin >> n_citation;
    //     if (cin.fail() || n_citation < 0) {
    //         cout << "So luong trich dan khong hop le. Vui long nhap lai.\n";
    //         cin.clear();
    //         cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //     } else {
    //         break;
    //     }
    // } while (true);

    // // Nhập loại bài báo
    // int typeChoice;
    // do {
    //     cout << "Nhap loai bai bao (1: SCIE, 2: SCOPUS, 3: CONFERENCE, 4: OTHER): ";
    //     cin >> typeChoice;
    //     if (cin.fail() || typeChoice < 1 || typeChoice > 4) {
    //         cout << "Loai bai bao khong hop le. Vui long nhap lai.\n";
    //         cin.clear();
    //         cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //     } else {
    //         break;
    //     }
    // } while (true);
    // switch (typeChoice) {
    //     case 1: type = Type::SCIE; break;
    //     case 2: type = Type::SCOPUS; break;
    //     case 3: type = Type::CONFERENCE; break;
    //     case 4: type = Type::OTHER; break;
    // }

    // // Nhập trạng thái bài báo
    // int statusChoice;
    // do {
    //     cout << "Nhap trang thai bai bao (1: DRAFT, 2: SUBMITTED, 3: PUBLISHED): ";
    //     cin >> statusChoice;
    //     if (cin.fail() || statusChoice < 1 || statusChoice > 3) {
    //         cout << "Trang thai khong hop le. Vui long nhap lai.\n";
    //         cin.clear();
    //         cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //     } else {
    //         break;
    //     }
    // } while (true);
    // switch (statusChoice) {
    //     case 1: status = ArticleStatus::DRAFT; break;
    //     case 2: status = ArticleStatus::SUBMITTED; break;
    //     case 3: status = ArticleStatus::PUBLISHED; break;
    // }

    // // Nhập danh sách tác giả
    // int numAuthors;
    // do {
    //     cout << "Nhap so luong tac gia: ";
    //     cin >> numAuthors;
    //     if (cin.fail() || numAuthors < 0) {
    //         cout << "So luong tac gia khong hop le. Vui long nhap lai.\n";
    //         cin.clear();
    //         cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //     } else {
    //         break;
    //     }
    // } while (true);

    // cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Xóa bộ đệm
    // authors.clear(); // Xóa danh sách hiện tại (nếu có)
    // for (int i = 0; i < numAuthors; ++i) {
    //     string authorId;
    //     cout << "Nhap ID tac gia thu " << (i + 1) << " (UUID): ";
    //     getline(cin, authorId);
    //     if (Utilities::isValidUUID(authorId)) { // Kiểm tra định dạng UUID
    //         AuthorArticle author(article_id, authorId);
    //         authors.push_back(author);
    //     } else {
    //         cout << "ID tac gia khong phai UUID hop le, bo qua.\n";
    //         --i; // Quay lại để nhập lại
    //     }
    // }

    // // Nhập danh sách tài liệu tham khảo
    // int numReferences;
    // do {
    //     cout << "Nhap so luong tai lieu tham khao: ";
    //     cin >> numReferences;
    //     if (cin.fail() || numReferences < 0) {
    //         cout << "So luong tai lieu tham khao khong hop le. Vui long nhap lai.\n";
    //         cin.clear();
    //         cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //     } else {
    //         break;
    //     }
    // } while (true);

    // cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Xóa bộ đệm
    // references.clear(); // Xóa danh sách hiện tại (nếu có)
    // for (int i = 0; i < numReferences; ++i) {
    //     string referenceId;
    //     cout << "Nhap ID tai lieu tham khao thu " << (i + 1) << " (UUID): ";
    //     getline(cin, referenceId);
    //     if (Utilities::isValidUUID(referenceId)) { // Kiểm tra định dạng UUID
    //         ArticleReference ref(article_id, referenceId);
    //         references.push_back(ref);
    //     } else {
    //         cout << "ID tai lieu tham khao khong phai UUID hop le, bo qua.\n";
    //         --i; // Quay lại để nhập lại
    //     }
    // }
    return nullptr; 
}
