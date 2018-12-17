//
// Created by brettmcrae on 12/17/2018.
//

#include "RetweetCollection.h"

bool RetweetCollection::isEmpty() const {
    return size_ == 0;
}

unsigned int RetweetCollection::size() const {
    return size_;
}

void RetweetCollection::add(const Tweet& tweet) {
    size_++;
}
