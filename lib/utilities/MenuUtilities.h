#pragma once
#include <vector>
#include <string>
#include "RepositoryManager.h"
#include "DataManipulation.h"
#include "AuthorRepo.h"
#include "Constants.h"
#include "AuthorArticleRepo.h"
#include "ArticleService.h"

class MenuUtilities
{
public:
    // Hàm helper trả menu options (không dùng console)
    static int general_menu(const std::vector<std::string> &options, const std::string &title);

    // Main menu (chỉ gọi service, dữ liệu từ Qt frontend)
    static void main_menu(ArticleService &a_service);

    // Data management menu
    static void data_menu(DataManipulation &service,
                          ArticleRepo &a_repo,
                          AuthorRepo &au_repo,
                          AuthorArticleRepo &au_ar);

    // Author menu
    static void author_sub_menu(RepositoryManager &repo);
    static void statisticAuthorMenu(RepositoryManager &repo);
    static void author_update_menu(RepositoryManager &repo);
    static void author_delete_menu(RepositoryManager &repo);

    // Article menu
    static void article_sub_menu(ArticleService &a_service);
    static void statisticArticleMenu(RepositoryManager &repo);
    static void article_update_menu(RepositoryManager &repo);
    static void article_delete_menu(RepositoryManager &repo);
};
