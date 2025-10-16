#include "models/users/Admin.h"
#include "models/repositories/RepositoryManager.h"



Admin::Admin(
    string username, 
    string password, 
    string admin_id,
    Role role = Role::ADMIN,
    Status status = Status::ONLINE
) : User(username, password, role, status), admin_id(admin_id) {}

Admin::Admin(const Admin& admin)
    : User(admin), admin_id(admin.admin_id) {}

string Admin::getAdminId() const {
    return admin_id;
}

void Admin::changeArticleStatus(Article& article, ArticleStatus newStatus, decision admin_decision) {
    ArticleStatus status = article.getStatus();

    if (status == ArticleStatus::DRAFT && newStatus == ArticleStatus::SUBMITTED) {
        article.setStatus(ArticleStatus::SUBMITTED);
    }
    else if (status == ArticleStatus::SUBMITTED && newStatus == ArticleStatus::UNDER_REVIEW) {
        article.setStatus(ArticleStatus::UNDER_REVIEW);
    }
    else if (status == ArticleStatus::UNDER_REVIEW && newStatus == ArticleStatus::REVISIONS) {
        article.setStatus(ArticleStatus::REVISIONS);
    }
    else if ((status == ArticleStatus::REVISIONS || status == ArticleStatus::UNDER_REVIEW) && admin_decision == decision::ACCEPT) {
        article.setStatus(ArticleStatus::ACCEPTED);
    }
    else if ((status == ArticleStatus::REVISIONS || status == ArticleStatus::UNDER_REVIEW) && admin_decision == decision::REJECT) {
        article.setStatus(ArticleStatus::REJECTED);
    }
    else if (status == ArticleStatus::ACCEPTED && newStatus == ArticleStatus::PUBLISHED) {
        article.setStatus(ArticleStatus::PUBLISHED);
    }
}

