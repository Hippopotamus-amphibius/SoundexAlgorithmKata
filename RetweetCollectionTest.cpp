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
    RetweetCollection collection;
    ASSERT_TRUE(collection.isEmpty());
}

TEST_F(RetweetCollectionTest, HasSizeZeroWhenCreated)
{
    RetweetCollection collection;
    ASSERT_THAT(collection.size(), Eq(0u));
}