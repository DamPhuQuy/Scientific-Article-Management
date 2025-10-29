#pragma once 
#include <vector> 
#include <string> 
#include "MenuUtilities.h"
#include "RepositoryManager.h"
#include "DataManipulation.h"
#include "AuthorRepo.h" 
#include "Constants.h"
#include "AuthorArticleRepo.h"
#include "ArticleService.h" 

using namespace std;

class MenuUtilities {
public: 
static int general_menu(const vector<string> &options, const string &title, bool allowEsc = true);
    static void main_menu(ArticleService& a_service); 
    static void article_sub_menu(ArticleService& a_service);
    static void author_sub_menu(RepositoryManager &repo);
    static void data_menu(DataManipulation &service,
                          ArticleRepo &a_repo,
                          AuthorRepo &au_repo,
                          AuthorArticleRepo &au_ar);
    void statisticArticleMenu(RepositoryManager &repo);
    void statisticAuthorMenu(RepositoryManager& repo); 
};