#pragma once 

#include "models/users/User.h"
#include "../repositories/RepositoryManager.h"
#include "models/articles/Article.h"
#include <string>

enum decision{
    ACCEPT,
    REJECT,
    PUBLISHED,
};

using namespace std;
class Admin : public User {
private:
    string admin_id;
    decision admin_decision;
public:
    Admin( 
        string username, 
        string password, 
        string admin_id,
        Role role = Role::ADMIN,
        Status status = Status::ONLINE
    );
    Admin(const Admin& admin);

    string getAdminId() const;

    void changeArticleStatus(const Article& article_id ,const ArticleStatus& newStatus,const decision& admin_decision);
};