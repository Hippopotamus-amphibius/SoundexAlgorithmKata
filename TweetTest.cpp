//
// Created by brettmcrae on 12/18/2018.
//
#include <gmock/gmock.h>
#include "Tweet.h"

using namespace std;
using namespace testing;


TEST(ATweet, DefaultUserNotNullWhenNotProvided)
{
    Tweet tweet("msg");
    ASSERT_THAT(tweet.getUser(), Eq("@null"));
}

TEST(ATweet, IsEqualWhenSameMessageAndUser)
{
    Tweet tweet("msg", "User");
    Tweet tweet2("msg", "User");
    ASSERT_THAT(tweet, Eq(tweet2));
}

TEST(ATweet, NotEqualWhenDifferentMessage)
{
    Tweet tweet("msg", "User");
    Tweet tweet2("msg2", "User");
    ASSERT_THAT(tweet, Ne(tweet2));
}

TEST(ATweet, NotEqualWhenDifferentUser)
{
    Tweet tweet("msg", "User");
    Tweet tweet2("msg", "User2");
    ASSERT_THAT(tweet, Ne(tweet2));
}