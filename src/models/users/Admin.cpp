#include "models/users/Admin.h"

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
