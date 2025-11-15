#include "repomanager.h"
#include <unordered_set>
#include <QString>
#include <QFile>
#include <QDebug>

using namespace std;

RepositoryManager::RepositoryManager(
    ArticleRepo &a_repo,
    AuthorRepo &au_repo,
    AuthorArticleRepo &au_ar
    )
    : a_repo(a_repo), au_repo(au_repo), au_ar(au_ar)
{
}

ArticleRepo &RepositoryManager::getArticles()
{ return a_repo; }
AuthorRepo &RepositoryManager::getAuthors()
{ return au_repo; }
AuthorArticleRepo &RepositoryManager::getAuthorArticles()
{ return au_ar; }

bool RepositoryManager::validateDataConsistency() const {
    bool isConsistent = true;
    const auto& relations = au_ar.getRelations();
    const auto& articles = a_repo.getContainer();
    const auto& authors = au_repo.getAuthorContainer();
    unordered_set<string> validArticleIds;
    unordered_set<string> validAuthorIds;

    // fetch valid id
    for (const auto& [id, articlePtr] : articles) validArticleIds.insert(id);
    for (const auto& [id, author] : authors) validAuthorIds.insert(id);

    QStringList errorMessages;
    QString logFilePath = "../../data/data_consistency.log"; // đường dẫn file log

    QFile logFile(logFilePath);
    if (!logFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        qCritical() << "Cannot open log file:" << logFilePath;
        return false;
    }
    QTextStream out(&logFile);

    out << "=== DATA CONSISTENCY CHECK ===\n";

    // check relationship
    for (const auto& rel : relations) {
        const string& aid = rel.getArticleId();
        const string& auid = rel.getAuthorId();

        if (validArticleIds.find(aid) == validArticleIds.end()) {
            QString msg = QString("[ERROR] Article ID '%1' DOES NOT EXIST in ArticleRepo!").arg(QString::fromStdString(aid));
            qWarning() << msg;
            errorMessages.append(msg);
            out << msg << "\n";
            isConsistent = false;
        }
        if (validAuthorIds.find(auid) == validAuthorIds.end()) {
            QString msg = QString("[ERROR] Author ID '%1' DOES NOT EXIST in AuthorRepo!").arg(QString::fromStdString(auid));
            qWarning() << msg;
            errorMessages.append(msg);
            out << msg << "\n";
            isConsistent = false;
        }
    }

    // report summary
    QString summary = QString(
                          "Summary:\n"
                          "  - Number of articles: %1\n"
                          "  - Number of authors: %2\n"
                          "  - Number of relations: %3\n"
                          ).arg(articles.size()).arg(authors.size()).arg(relations.size());

    if (isConsistent) {
        summary += "=> [SUCCESS] All data are FULLY CONSISTENT!";
        qInfo() << summary;
    } else {
        summary += "=> [ERROR] Inconsistent data detected!";
        qCritical() << summary;
    }

    out << summary << "\n";
    logFile.close();

    return isConsistent;
}

// void RepositoryManager::createArticle() {
//     // Type
//     int typeChoice;
//     do {
//         cout << "Choose the type of article (1: SCIE, 2: SCOPUS, 3: CONFERENCE, 4: OTHER): ";
//         cin >> typeChoice; cin.ignore();
//         if (cin.fail() || typeChoice < 1 || typeChoice > 4) {
//             cout << "Loai bai bao khong hop le. Vui long nhap lai.\n";
//             cin.clear();
//             cin.ignore(numeric_limits<streamsize>::max(), '\n');
//         } else {
//             break;
//         }
//     } while (true);
//     Type type = static_cast<Type>(typeChoice);
//     Article* article = DataManipulation::createArticle(type);
//     // input Article + Author + References
//     inputArticle(article);    // xử lý liên kết với Author
//     inputArticleReferences(article);
//     // Save
//     a_repo.add(article);
//     cout << "Article created successfully!\n";
// }

// void RepositoryManager::inputArticleReferences(Article* article)
// {
//     int numReferences = 0;
//     while (true) {
//         cout << "Enter the number of reference documents (0 or more): ";
//         if (cin >> numReferences && numReferences >= 0) {
//             cin.ignore(numeric_limits<streamsize>::max(), '\n');
//             break;
//         }
//         cout << "Invalid input. Please enter a non-negative integer.\n";
//         cin.clear();
//         cin.ignore(numeric_limits<streamsize>::max(), '\n');
//     }
//     article->getReferences().clear();
//     // pick or add
//     for (int i = 0; i < numReferences; ++i) {
//         cout << "\n=== Reference " << (i + 1) << " of " << numReferences << " ===\n";
//         while (true) {
//             // Show available titles
//             cout << "Available reference titles:\n";
//             int idx = 1;
//             vector<string> titles;
//             for (const auto& [id, element] : a_repo.getContainer()) {
//                 cout << idx << ". " << element->getArticleTitle() << "\n";
//                 titles.push_back(element->getArticleTitle());
//                 ++idx;
//             }
//             cout << idx << ". Add new reference title\n";
//             string choice;
//             cout << "Choose (or " << idx << " to add new): ";
//             getline(cin >> ws, choice);
//             int sel;
//             try { sel = stoi(choice); }
//             catch (...) { cout << "Please enter a number.\n"; continue; }
//             if (sel == idx) {
//                 string newTitle;
//                 cout << "Enter the reference title: ";
//                 getline(cin >> ws, newTitle);
//                 if (newTitle.empty()) {
//                     cout << "Title cannot be empty.\n";
//                     continue;
//                 }
//                 article->getReferences().push_back(newTitle);
//                 cout << "Added: " << newTitle << "\n";
//                 break;
//             }
//             else if (sel > 0 && sel < idx) {
//                 const string& chosen = titles[sel - 1];
//                 article->getReferences().push_back(chosen);
//                 cout << "Selected: " << chosen << "\n";
//                 break;
//             }
//             else {
//                 cout << "Invalid choice.\n";
//             }
//         }
//     }
//     cout << "\nAll references added to article.\n";
// }

// void RepositoryManager::inputArticle(Article* article) {
//     cout << "Enter title of article: ";
//     string title;
//     getline(cin, title);
//     article->setTitle(title);
//     cout << "Enter abstract of article: ";
//     string abstract;
//     getline(cin, abstract);
//     article->setAbstract(abstract);
//     cout << "Enter the venue of article: ";
//     string venue;
//     getline(cin, venue);
//     article->setVenue(venue);
//     int year = 0;
//     do {
//         cout << "Enter publish year: ";
//         cin >> year; cin.ignore();
//         if (cin.fail() || year < 0 || year > 2025) {
//             cout << "Invalid data. Please try again.\n";
//             cin.clear();
//             cin.ignore(numeric_limits<streamsize>::max(), '\n');
//         } else {
//             break;
//         }
//     } while (true);
//     article->setYear(year);
//     int n_citation = 0;
//     do {
//         cout << "Enter the number of citations: ";
//         cin >> n_citation; cin.ignore();
//         if (cin.fail() || n_citation < 0) {
//             cout << "Invalid citations count. Please try again.\n";
//             cin.clear();
//             cin.ignore(numeric_limits<streamsize>::max(), '\n');
//         } else {
//             break;
//         }
//     } while (true);
//     article->setNCitation(n_citation);
//     int statusChoice;
//     do {
//         cout << "Choose the status of article (1: DRAFT, 2: SUBMITTED, 3: PUBLISHED): ";
//         cin >> statusChoice; cin.ignore();
//         if (cin.fail() || statusChoice < 1 || statusChoice > 3) {
//             cout << "Invalid status. Please try again.\n";
//             cin.clear();
//             cin.ignore(numeric_limits<streamsize>::max(), '\n');
//         } else {
//             break;
//         }
//     } while (true);
//     ArticleStatus status;
//     switch (statusChoice) {
//     case 1: status = ArticleStatus::DRAFT; break;
//     case 2: status = ArticleStatus::SUBMITTED; break;
//     case 3: status = ArticleStatus::PUBLISHED; break;
//     }
//     article->setStatus(status);
//     // Input Authors (Multiple)
//     int numAuthors;
//     do {
//         cout << "Enter the number of authors: ";
//         cin >> numAuthors;
//         if (cin.fail() || numAuthors < 0) {
//             cout << "Invalid author number. Please try again.\n";
//             cin.clear();
//             cin.ignore(numeric_limits<streamsize>::max(), '\n');
//         } else {
//             break;
//         }
//     } while (true);
//     // Choose available author or add new one
//     for (int i = 0; i < numAuthors; ++i) {
//         cout << "\n--- Author " << (i + 1) << " of " << numAuthors << " ---\n";
//         while (true) {
//             cout << "Available authors:\n";
//             int index = 1;
//             vector<string> keys;
//             for (const auto& [id, author] : au_repo.getAuthorContainer()) {
//                 cout << index << ". " << author.getFullName() << " (ID: " << id << ")\n";
//                 keys.push_back(id);
//                 ++index;
//             }
//             cout << index << ". Add new author\n";
//             string choice;
//             cout << "Choose (or " << index << " to add new): ";
//             getline(cin, choice);
//             int selected;
//             try {
//                 selected = stoi(choice);
//             } catch (...) {
//                 cout << "Invalid input. Please enter a number.\n";
//                 continue;
//             }
//             if (selected == index) {
//                 // Add new author
//                 Author newAuthor;
//                 newAuthor.inputFromUser();
//                 au_repo.add(newAuthor);
//                 cout << "Added new author: " << newAuthor.getFullName() << "\n";
//                 if (au_repo.getAuthorContainer().count(newAuthor.getId())) {
//                     cout << "ID already exists. Author not added.\n";
//                     continue;
//                 }
//                 au_ar.add(article->getId(), newAuthor.getId());
//             } else if (selected > 0 && selected < index) {
//                 const string& chosenId = keys[selected - 1];
//                 const Author& chosen = au_repo.getAuthorContainer().at   (chosenId);
//                 cout << "You selected: " << chosen.getFullName() << "\n";
//                 au_ar.add(article->getId(), chosen.getId());
//                 break;
//             } else {
//                 cout << "Invalid choice.\n";
//             }
//         }
//     }
