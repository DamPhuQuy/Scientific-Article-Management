#pragma once
#include "RepositoryManager.h"
#include <unordered_map>
#include <map>
#include <string>
#include <vector>

class Statistics
{
public:
    // Article
    static void articlesByYear(RepositoryManager &repo);
    static void articlesByType(RepositoryManager &repo);

    // Author
    static void authorsByCountry(RepositoryManager &repo);
    static void authorsByField(RepositoryManager &repo);
    static void topAuthorsByPublication(RepositoryManager &repo, int topN = 5);
};
