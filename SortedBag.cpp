#include <valarray>
#include "SortedBag.h"
#include "SortedBagIterator.h"

SortedBag::SortedBag(Relation r) {
    //TODO - Implementation
    this->length= 0;
    this->capacity = 1000;
    this->relation = r;
    this->hashTable = new TElem[capacity];
    this->empty =-1111;
    this->deleted = -1111;

    for (int i = 0; i < capacity; i++) {
        this->hashTable[i] = this->empty;
}
}

void SortedBag::add(TComp e) {
    //TODO - Implementation

    int i=0;
    int pos = h(e,i);

    while (i < this->capacity && this->hashTable[pos] != this->empty && this->hashTable[pos]!=this->deleted ) {
        i++;
        pos = h(e, i);
    }

    TElem old = this->hashTable[pos];
    if (old == this->empty|| old == this->deleted) {
        this->length++;
        this->hashTable[pos] = e;
    }
}


bool SortedBag::remove(TComp e) {
    //TODO - Implementation
    int i = 0;
    int pos = h(e, i);
    while (i < this->capacity && this->hashTable[pos]!= e && this->hashTable[pos] != this->empty) {
        i++;
        pos = h(e, i);
    }
    if (i == this->capacity || this->hashTable[pos]==this->empty)
        return false;
    this->length--;

    //TElem toReturn = this->hashTable[pos];
    this->hashTable[pos] = this->deleted;
    return true;
}


bool SortedBag::search(TComp elem) const {
    //TODO - Implementation
    int i = 0;
    int pos = h(elem, i);
    while(i<this->capacity && this->hashTable[pos]!=elem && this->hashTable[pos]!=this->empty){
        i++;
        pos = h(elem, i);
    }
    if (i == this->capacity || this->hashTable[pos] == this->empty)
        return false;
    return true;
    }


int SortedBag::nrOccurrences(TComp elem) const {
    //TODO - Implementation
    int noOccurrence=0;
    for(int i=0;i<length; i++)
    {
        if(hashTable[i] == elem)
        noOccurrence++;
    }

    return noOccurrence;
}



int SortedBag::size() const {
    //TODO - Implementation
    return this->length;
}


bool SortedBag::isEmpty() const {
    //TODO - Implementation
    return this->length == 0;
}


SortedBagIterator SortedBag::iterator() const {
    return SortedBagIterator(*this);
}


SortedBag::~SortedBag() {
    //TODO - Implementation
    delete[] this->hashTable;
}



int SortedBag::hCode(TElem elem) {
    return abs(int(elem));
}

TComp SortedBag::h1(TElem elem) const {
    return hCode(elem) % this->capacity;
}

int SortedBag::h(TElem elem, int i) const {
    return (h1(elem) + i) % this->capacity;
}

