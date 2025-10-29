#include "Statistics.h"
#include <iostream>

using namespace std; 

void Statistics::articlesByYear(RepositoryManager& repo) {
    map<int, int> yearCount;

    for (auto& [id, article] : repo.getArticles().getAll()) {
        if (article) {
            yearCount[article->getYear()]++;
        }
    
    vector<int> years;
    vector<int> counts;
    for (auto& [year, count] : yearCount) {
        years.push_back(year);
        counts.push_back(count);
    }

    cout << "\n=== ARTICLES BY YEAR ===\n";
    for (auto& [year, count] : yearCount)
        cout << "Year " << year << " : " << count << " articles\n";

    plt::bar(years, counts);
    plt::xlabel("Year");
    plt::ylabel("Number of Articles");
    plt::title("Articles per Year");
    plt::show();
    }
}


void Statistics::articlesByType(RepositoryManager& repo) {
    map<string, int> typeCount; 
    for (auto& [id, article] : repo.getArticles().getAll()) {
        if (!article) continue;
        Type t = article->getType();
        switch (t) {
            case Type::SCIE:        typeCount["SCIE"]++; break;
            case Type::SCOPUS:      typeCount["SCOPUS"]++; break;
            case Type::CONFERENCE:  typeCount["CONFERENCE"]++; break;
            case Type::OTHER:       typeCount["OTHER"]++; break;
        }
    }

    vector<string> labels;
    vector<int> values;
    for (auto& [label, value] : typeCount) {
        labels.push_back(label);
        values.push_back(value);
    }

    cout << "\n=== ARTICLES BY TYPE ===\n";
    for (auto& [label, value] : typeCount)
        cout << label << " : " << value << " articles\n";

    plt::pie(values, labels);
    plt::title("Articles by Type");
    plt::show();
}

void MenuUtilities::article_sub_menu(RepositoryManager& repo) {
    const std::vector<std::string> options = {
        "Statistics by Year",
        "Statistics by Type",
        "Back"
    };

    while (true) {
        int selected = MenuUtilities::general_menu(options, "ARTICLE STATISTICS MENU");
        switch (selected) {
            case 0:
                Statistics::articlesByYear(repo);
                break;
            case 1:
                Statistics::articlesByType(repo);
                break;
            case 2:
                return;
        }
    }
}