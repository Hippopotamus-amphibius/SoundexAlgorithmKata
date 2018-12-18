//
// Created by brettmcrae on 12/17/2018.
//
#include "RetweetCollection.h"

bool RetweetCollection::isEmpty() const {
    return tweets.size() == 0;
}

unsigned int RetweetCollection::size() const {
    return tweets.size();
}

void RetweetCollection::add(const Tweet& tweet) {
    tweets.insert(tweet);
}

RetweetCollection::RetweetCollection() {

}
