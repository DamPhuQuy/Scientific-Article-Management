#include "models/users/Reviewer.h"

Reviewer::Reviewer(
    string username,
    string password,
    string reviewer_id,
    Role role = Role::REVIEWER,
    Status status = Status::ONLINE
) : User(username, password, role, status), reviewer_id(reviewer_id) {}

Reviewer::Reviewer(const Reviewer &reviewer) 
    : User(reviewer), reviewer_id(reviewer.reviewer_id) {}

string Reviewer::getReviewerId() const {
    return reviewer_id;
}