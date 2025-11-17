#include "MenuUtilities.h"

int MenuUtilities::general_menu(const std::vector<std::string> &options, const std::string &title)
{
    // Qt sẽ hiển thị menu và trả về index lựa chọn
    // Backend chỉ cần index trả về từ frontend
    return -1; // placeholder
}

void MenuUtilities::main_menu(ArticleService &a_service)
{
    // Qt frontend sẽ gọi trực tiếp các hàm dưới đây khi click button
}

void MenuUtilities::article_sub_menu(ArticleService &a_service)
{
    // Qt frontend gọi a_service.createArticle() hoặc addAuthors(), addReferences() trực tiếp
}

void MenuUtilities::author_sub_menu(RepositoryManager &repo)
{
    // Qt frontend gọi repo.getAuthors()->createAuthor(), update, delete trực tiếp
}

void MenuUtilities::data_menu(DataManipulation &service, ArticleRepo &a_repo, AuthorRepo &au_repo, AuthorArticleRepo &au_ar)
{
    // Qt frontend sẽ truyền file path từ QFileDialog hoặc dữ liệu cần import
    // và gọi service.fetchArticleDataSet(...), fetchAuthorInformation(...)
}

void MenuUtilities::statisticArticleMenu(RepositoryManager &repo)
{
    // Qt frontend gọi Statistics::articlesByYear(repo), etc.
}

void MenuUtilities::statisticAuthorMenu(RepositoryManager &repo)
{
    // Qt frontend gọi Statistics::authorsByCountry(repo), etc.
}

void MenuUtilities::article_update_menu(RepositoryManager &repo) {}
void MenuUtilities::article_delete_menu(RepositoryManager &repo) {}
void MenuUtilities::author_update_menu(RepositoryManager &repo) {}
void MenuUtilities::author_delete_menu(RepositoryManager &repo) {}
