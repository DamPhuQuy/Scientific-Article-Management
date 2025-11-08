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

class MenuUtilities
{
public:
    static void intro();

    static int general_menu(const vector<string> &options, const string &title, bool allowEsc = true);
    // main menu
    static void main_menu(RepositoryManager &a_service);

    // data_menu
    static void data_menu(DataManipulation &service,
                          ArticleRepo &a_repo,
                          AuthorRepo &au_repo,
                          AuthorArticleRepo &au_ar);

    // Author
    static void author_sub_menu(RepositoryManager &repo);
    static void author_update_menu(RepositoryManager &repo);
    static void author_delete_menu(RepositoryManager &repo);
    static void statisticAuthorMenu(RepositoryManager &repo);

    // Article
    static void article_sub_menu(RepositoryManager &repo);
    static void statisticArticleMenu(RepositoryManager &repo);
    static void article_update_menu(RepositoryManager &repo);
    static void article_delete_menu(RepositoryManager &repo);
    static void show_article_through_authorId(RepositoryManager &repo, string selectedId);
};