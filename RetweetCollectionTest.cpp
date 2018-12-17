//
// Created by brettmcrae on 12/17/2018.
//
#include <gmock/gmock.h>
#include "RetweetCollection.h"

using namespace testing;
// Create a class fixture
class RetweetCollectionTest: public testing::Test
{
public:
    RetweetCollection collection;
};

TEST_F(RetweetCollectionTest, IsEmptyWhenCreated)
{
    ASSERT_TRUE(collection.isEmpty());
}

TEST_F(RetweetCollectionTest, HasSizeZeroWhenCreated)
{
    ASSERT_THAT(collection.size(), Eq(0u));
}

TEST_F(RetweetCollectionTest, IsNotEmptyAfterTweetAdded)
{
    collection.add(Tweet());
    ASSERT_FALSE(collection.isEmpty());
}

TEST_F(RetweetCollectionTest, IsEmptyWhenSizeIsZero)
{
    ASSERT_THAT(collection.size(), Eq(0u));
    ASSERT_TRUE(collection.isEmpty());
}

TEST_F(RetweetCollectionTest, IsNotEmptyWhenSizeIsZero)
{
    collection.add(Tweet());
    ASSERT_THAT(collection.size(), Gt(0u));
    ASSERT_FALSE(collection.isEmpty());
}