#include "Statistics.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std; 

void Statistics::articlesByYear(RepositoryManager& repo) {
    std::map<int, int> yearCount;

    for (const auto& [id, article] : repo.getArticles().getContainer()) {
        if (article) {
            yearCount[article->getYear()]++;
        }
    }

    // In tiêu đề
    std::cout << "\n=== ARTICLES BY YEAR ===\n";
    std::cout << std::left << std::setw(10) << "Year" << " : " << "Number of Articles\n";
    std::cout << std::string(40, '-') << "\n";

    // In từng năm và số lượng bài báo
    for (const auto& [year, count] : yearCount) {
        std::cout << std::left << std::setw(10) << year << " : " << count << " articles\n";
    }

    // In tổng cộng
    int total = 0;
    for (const auto& [year, count] : yearCount) total += count;
    std::cout << std::string(40, '-') << "\n";
    std::cout << std::left << std::setw(10) << "TOTAL" << " : " << total << " articles\n\n";
}

void Statistics::articlesByType(RepositoryManager& repo) {
    auto& articles = repo.getArticles().getContainer();
    std::map<std::string, int> typeCount;

    for (const auto& [id, articlePtr] : articles) {
        if (articlePtr) {
            switch (articlePtr->getType()) {
                case Type::SCIE:       typeCount["SCIE"]++; break;
                case Type::SCOPUS:     typeCount["SCOPUS"]++; break;
                case Type::CONFERENCE: typeCount["CONFERENCE"]++; break;
                default:               typeCount["OTHER"]++; break;
            }
        }
    }

    // In tiêu đề
    std::cout << "\n=== ARTICLES BY TYPE ===\n";
    std::cout << std::left << std::setw(15) << "Type" << " : " << "Count\n";
    std::cout << std::string(35, '-') << "\n";

    // In từng loại và số lượng
    for (const auto& [type, count] : typeCount) {
        std::cout << std::left << std::setw(15) << type << " : " << count << "\n";
    }

    // In tổng cộng
    int total = 0;
    for (const auto& [type, count] : typeCount) total += count;
    std::cout << std::string(35, '-') << "\n";
    std::cout << std::left << std::setw(15) << "TOTAL" << " : " << total << "\n\n";
}

void Statistics::authorsByCountry(RepositoryManager& repo) {
    auto& authors = repo.getAuthors().getAuthorContainer();
    std::map<std::string, int> countryCount;

    for (const auto& [id, author] : authors) {
        if (!author.getCountry().empty()) {
            countryCount[author.getCountry()]++;
        }
    }

    // In tiêu đề
    std::cout << "\n=== AUTHORS BY COUNTRY ===\n";
    std::cout << std::left << std::setw(25) << "Country" << " : " << "Number of Authors\n";
    std::cout << std::string(50, '-') << "\n";

    // In từng quốc gia
    for (const auto& [country, count] : countryCount) {
        std::cout << std::left << std::setw(25) << country << " : " << count << "\n";
    }

    // Tổng cộng
    int total = 0;
    for (const auto& [country, count] : countryCount) total += count;
    std::cout << std::string(50, '-') << "\n";
    std::cout << std::left << std::setw(25) << "TOTAL" << " : " << total << "\n\n";
}

void Statistics::authorsByField(RepositoryManager& repo) {
    auto& authors = repo.getAuthors().getAuthorContainer();
    std::map<std::string, int> fieldCount;

    for (const auto& [id, author] : authors) {
        if (!author.getFieldOfStudy().empty()) {
            fieldCount[author.getFieldOfStudy()]++;
        }
    }

    // In tiêu đề
    std::cout << "\n=== AUTHORS BY FIELD OF STUDY ===\n";
    std::cout << std::left << std::setw(35) << "Field of Study" << " : " << "Number of Authors\n";
    std::cout << std::string(65, '-') << "\n";

    // In từng lĩnh vực
    for (const auto& [field, count] : fieldCount) {
        std::cout << std::left << std::setw(35) << field << " : " << count << "\n";
    }

    // Tổng cộng
    int total = 0;
    for (const auto& [field, count] : fieldCount) total += count;
    std::cout << std::string(65, '-') << "\n";
    std::cout << std::left << std::setw(35) << "TOTAL" << " : " << total << "\n\n";
}

void Statistics::topAuthorsByPublication(RepositoryManager &repo, int topN) {
    auto& authors = repo.getAuthors().getAuthorContainer();
    std::vector<std::pair<std::string, int>> pubs;

    for (const auto& [id, author] : authors) {
        pubs.emplace_back(author.getFullName(), author.getTotalPublications());
    }

    // Sắp xếp giảm dần theo số bài báo
    std::sort(pubs.begin(), pubs.end(),
              [](const auto& a, const auto& b) { return a.second > b.second; });

    // Giới hạn topN
    if (pubs.size() > static_cast<size_t>(topN)) {
        pubs.resize(topN);
    }

    // In tiêu đề
    std::cout << "\n=== TOP " << topN << " AUTHORS BY PUBLICATIONS ===\n";
    std::cout << std::left << std::setw(35) << "Author Name" << " : " << "Publications\n";
    std::cout << std::string(60, '-') << "\n";

    // In danh sách top
    for (size_t i = 0; i < pubs.size(); ++i) {
        const auto& [name, count] = pubs[i];
        std::cout << std::left << std::setw(3) << (i + 1) << ". "
                  << std::setw(30) << name << " : " << count << "\n";
    }

    // Tổng số bài báo của top N
    int totalPubs = 0;
    for (const auto& [name, count] : pubs) totalPubs += count;
    std::cout << std::string(60, '-') << "\n";
    std::cout << std::left << std::setw(35) << "TOTAL PUBLICATIONS (Top " + std::to_string(topN) + ")"
              << " : " << totalPubs << "\n\n";
}

