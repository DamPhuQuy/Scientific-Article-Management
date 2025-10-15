#include <vector>
#include <string>
#include "models/users/User.h"

using namespace std;

class Reviewer : public User {
private:
    string reviewer_id;
public:
    Reviewer(
        string username,
        string password,
        string reviewer_id,
        Role role = Role::REVIEWER,
        Status status = Status::ONLINE
    );

    Reviewer(const Reviewer& reviewer);

    string getReviewerId() const;
};
