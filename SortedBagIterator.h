#pragma once
#include "SortedBag.h"
#define NULL_TCOMP -11111;

class SortedBag;

class SortedBagIterator
{
    friend class SortedBag;

private:
    const SortedBag& bag;
    SortedBagIterator(const SortedBag& b);

    //TODO - Representation
    int length, index, k;
    TElem* array;

public:
    TComp getCurrent();
    bool valid();
    void next();
    void first();
};
