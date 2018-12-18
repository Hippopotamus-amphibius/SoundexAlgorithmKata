//
// Created by brettmcrae on 12/17/2018.
//

#include "Tweet.h"
const std::string Tweet::NULL_USER("@null");

struct InvalidUserException: public std::invalid_argument
{
public:
    InvalidUserException(const string& user) : invalid_argument(user) {}
};

Tweet::Tweet(const string &msg, const string &user)
{
    if (!isValidUser(user)) throw InvalidUserException(user);
    message_ = msg;
    user_ = user;
}

bool Tweet::operator<(const Tweet &rhs) const {
    if(message_ < rhs.message_) return true;
    if(rhs.message_ < message_) return false;
    return user_ < rhs.user_;
}

const string &Tweet::getUser() const {
    return user_;
}

bool Tweet::operator==(const Tweet &rhs) const {
    return message_ == rhs.message_ &&
           user_ == rhs.user_;
}

bool Tweet::operator!=(const Tweet &rhs) const {
    return !(rhs == *this);
}

bool Tweet::isValidUser(const string &user)
{
    return user.length() > 2 && user[0] == '@';
}
