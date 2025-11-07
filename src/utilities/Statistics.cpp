#include "Statistics.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <iomanip>
#include <conio.h>

using namespace std;

void Statistics::articlesByYear(RepositoryManager &repo)
{
    map<int, int> yearCount;

    for (const auto &[id, articlePtr] : repo.getArticles().getContainer())
    {
        if (articlePtr)
        {
            yearCount[articlePtr->getYear()]++;
        }
    }

    cout << "\n=== ARTICLES BY YEAR ===\n";
    cout << left << setw(10) << "Year" << " : " << "Number of Articles\n";
    cout << string(40, '-') << "\n";

    for (const auto &[year, count] : yearCount)
    {
        cout << left << setw(10) << year << " : " << count << " articles\n";
    }

    int total = 0;
    for (const auto &[year, count] : yearCount)
        total += count;
    cout << string(40, '-') << "\n";
    cout << left << setw(10) << "TOTAL" << " : " << total << " articles\n\n";

    cout << "Press any key to continue...";
    _getch();
}

void Statistics::articlesByType(RepositoryManager &repo)
{
    auto &articles = repo.getArticles().getContainer();
    map<string, int> typeCount;

    for (const auto &[id, articlePtr] : articles)
    {
        if (articlePtr)
        {
            switch (articlePtr->getType())
            {
            case Type::SCIE:
                typeCount["SCIE"]++;
                break;
            case Type::SCOPUS:
                typeCount["SCOPUS"]++;
                break;
            case Type::CONFERENCE:
                typeCount["CONFERENCE"]++;
                break;
            default:
                typeCount["OTHER"]++;
                break;
            }
        }
    }

    cout << "\n=== ARTICLES BY TYPE ===\n";
    cout << left << setw(15) << "Type" << " : " << "Count\n";
    cout << string(35, '-') << "\n";

    for (const auto &[type, count] : typeCount)
    {
        cout << left << setw(15) << type << " : " << count << "\n";
    }

    int total = 0;
    for (const auto &[type, count] : typeCount)
        total += count;
    cout << string(35, '-') << "\n";
    cout << left << setw(15) << "TOTAL" << " : " << total << "\n\n";

    cout << "Press any key to continue...";
    _getch();
}

void Statistics::authorsByCountry(RepositoryManager &repo)
{
    auto &authors = repo.getAuthors().getAuthorContainer();
    map<string, int> countryCount;

    for (const auto &[id, author] : authors)
    {
        if (!author.getCountry().empty())
        {
            countryCount[author.getCountry()]++;
        }
    }

    cout << "\n=== AUTHORS BY COUNTRY ===\n";
    cout << left << setw(25) << "Country" << " : " << "Number of Authors\n";
    cout << string(50, '-') << "\n";

    for (const auto &[country, count] : countryCount)
    {
        cout << left << setw(25) << country << " : " << count << "\n";
    }

    int total = 0;
    for (const auto &[country, count] : countryCount)
        total += count;
    cout << string(50, '-') << "\n";
    cout << left << setw(25) << "TOTAL" << " : " << total << "\n\n";

    cout << "Press any key to continue...";
    _getch();
}

void Statistics::authorsByField(RepositoryManager &repo)
{
    auto &authors = repo.getAuthors().getAuthorContainer();
    map<string, int> fieldCount;

    for (const auto &[id, author] : authors)
    {
        if (!author.getFieldOfStudy().empty())
        {
            fieldCount[author.getFieldOfStudy()]++;
        }
    }

    cout << "\n=== AUTHORS BY FIELD OF STUDY ===\n";
    cout << left << setw(35) << "Field of Study" << " : " << "Number of Authors\n";
    cout << string(65, '-') << "\n";

    for (const auto &[field, count] : fieldCount)
    {
        cout << left << setw(35) << field << " : " << count << "\n";
    }

    int total = 0;
    for (const auto &[field, count] : fieldCount)
        total += count;
    cout << string(65, '-') << "\n";
    cout << left << setw(35) << "TOTAL" << " : " << total << "\n\n";

    cout << "Press any key to continue...";
    _getch();
}

void Statistics::topAuthorsByPublication(RepositoryManager &repo, int topN)
{
    auto &authors = repo.getAuthors().getAuthorContainer();
    vector<pair<string, int>> pubs;

    for (const auto &[id, author] : authors)
    {
        pubs.emplace_back(author.getFullName(), author.getTotalPublications());
    }

    sort(pubs.begin(), pubs.end(),
         [](const auto &a, const auto &b)
         { return a.second > b.second; });

    if (pubs.size() > static_cast<size_t>(topN))
    {
        pubs.resize(topN);
    }

    cout << "\n=== TOP " << topN << " AUTHORS BY PUBLICATIONS ===\n";
    cout << left << setw(35) << "Author Name" << " : " << "Publications\n";
    cout << string(60, '-') << "\n";

    for (size_t i = 0; i < pubs.size(); ++i)
    {
        const auto &[name, count] = pubs[i];
        cout << left << setw(3) << (i + 1) << ". "
             << setw(30) << name << " : " << count << "\n";
    }

    int totalPubs = 0;
    for (const auto &[name, count] : pubs)
        totalPubs += count;
    cout << string(60, '-') << "\n";
    cout << left << setw(35) << "TOTAL PUBLICATIONS (Top " + std::to_string(topN) + ")"
         << " : " << totalPubs << "\n\n";

    cout << "Press any key to continue...";
    _getch();
}
