#pragma once

#include "models/Article.h"

class ArticleFactory {
public:
    static Article* createEmptyArticle(Type type) {
        switch (type) {
            case Type::SCI: return new SCI_Article(); 
            case Type::SCIE: return new SCIE_Article(); 
            case Type::ISI: return new ISI_Article(); 
            case Type::SCOPUS: return new SCOPUS_Article(); 
            case Type::OTHER: return new OTHER_Article(); 
            default: return new OTHER_Article(); 
        }
    }


    static Article* createArticle(Type type, const string &articleID, const string &articleName, 
                                 const string &authorID, const string &journalID, ArticleStatus status) {
        switch (type) {
            case Type::SCI: return new SCI_Article(articleID, articleName, authorID, journalID, type, status);
            case Type::SCIE: return new SCIE_Article(articleID, articleName, authorID, journalID, type, status);
            case Type::ISI: return new ISI_Article(articleID, articleName, authorID, journalID, type, status);
            case Type::SCOPUS: return new SCOPUS_Article(articleID, articleName, authorID, journalID, type, status);
            case Type::OTHER: return new OTHER_Article(articleID, articleName, authorID, journalID, type, status);
            default: return new OTHER_Article(articleID, articleName, authorID, journalID, type, status);
        }
    }
};