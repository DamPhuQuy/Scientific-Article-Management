#pragma once
#include "RepositoryManager.h"
#include "UUID_Generator.h"
#include "DataManipulation.h"

struct ArticleData {
    std::string title;
    std::string abstractText;
    std::string venue;
    int year;
    int nCitations;
    ArticleStatus status;
};

class ArticleService {
private:
    RepositoryManager& repo;

public:
    ArticleService(RepositoryManager& r) : repo(r) {}
    ~ArticleService() = default;

    RepositoryManager& getRepo() const { return repo; }

    // Qt-ready functions
    Article* createArticle(Type type, const ArticleData& data);
    void addReferences(Article* article, const std::vector<std::string>& references);
    void addAuthors(Article* article, const std::vector<std::string>& authorIds);
};
