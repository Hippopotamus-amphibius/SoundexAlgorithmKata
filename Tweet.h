//
// Created by brettmcrae on 12/17/2018.
//

#ifndef FIRSTEXAMPLE_TWEET_H
#define FIRSTEXAMPLE_TWEET_H

#include <iostream>
using namespace std;

class Tweet
{
    string message_;
    string user_;
    bool isValidUser(const string &basic_string);
public:
    const string &getUser() const;
    static const string NULL_USER;
    Tweet(const string& msg = "", const string& user = Tweet::NULL_USER);
    bool operator<(const Tweet& rhs) const;
    bool operator==(const Tweet &rhs) const;
    bool operator!=(const Tweet &rhs) const;
};

struct InvalidUserException: public std::invalid_argument
{
public:
    InvalidUserException(const string& user) : invalid_argument(user) {}
};

#endif //FIRSTEXAMPLE_TWEET_H
