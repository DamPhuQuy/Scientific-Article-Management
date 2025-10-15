#include <vector>
#include <string>
#include "models/users/User.h"


using namespace std;
class Admin : public User {
private:
    string admin_id;
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
};