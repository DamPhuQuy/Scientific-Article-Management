#pragma once 
#include <vector> 
#include <string> 
#include "MenuUtilities.h"
#include "RepositoryManager.h"
#include "DataManipulation.h"
#include "AuthorRepo.h" 
#include "Constants.h"
#include "AuthorArticleRepo.h"

using namespace std;

class MenuUtilities {
public: 
static int general_menu(const vector<string> &options, const string &title, bool allowEsc = true);
    static void article_menu(RepositoryManager& repo); 
    static void data_menu(DataManipulation& service,
                          ArticleRepo& a_repo,
                          AuthorRepo& au_repo,
                          AuthorArticleRepo& au_ar);
};