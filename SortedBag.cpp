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
}//Complexity O(n)

void SortedBag::add(TComp e) {
    //TODO - Implementation

    int i=0;
    int pos = h(e,i);

    while (i < this->capacity && this->hashTable[pos] != this->empty ) {
        i++;
        pos = h(e, i);
    }

    if(i < this->capacity){
        this->hashTable[pos] = e;
        this->length++;
    }

    if(this->length == this->capacity){
        TComp *oldTable = hashTable;
        int oldCapacity = capacity;
        capacity = 2 * capacity;
        hashTable = new TElem[capacity];
        length = 0;
        for (int i = 0; i < capacity; i++) {
            this->hashTable[i] = this->empty;
        }
        for (int i = 0; i < oldCapacity; i++) {
            this->add(oldTable[i]);
        }
        delete[] oldTable;
    }
}//Complexity:


bool SortedBag::remove(TComp e) {
    //TODO - Implementation
    int i = 0;
    int pos = h(e, i);
    while (i < this->capacity && this->hashTable[pos] != e && this->hashTable[pos] != this->empty) {
        i++;
        pos = h(e, i);
    }
    if (i == this->capacity || this->hashTable[pos] == this->empty)
        return false;
    this->length--;

    //TElem toReturn = this->hashTable[pos];
    this->hashTable[pos] = this->deleted;
    return true;
}//Complexity: worst case: O(n)
//              best case: Theta(1)
//              average case: O(n)


bool SortedBag::search(TComp elem) const {
    //TODO - Implementation
    int i = 0;
    int pos = h(elem, i);
    while(i < this->capacity && this->hashTable[pos] != elem && this->hashTable[pos] != this->empty){
        i++;
        pos = h(elem, i);
    }
    if (i == this->capacity || this->hashTable[pos] == this->empty)
        return false;
    return true;
}//Complexity: worst case: O(n)
//              best case: Theta(1)
//              average case: O(n)


int SortedBag::nrOccurrences(TComp elem) const {
    //TODO - Implementation
    int noOccurrence=0;
    int i = 0;
    int pos = h(elem, i);
    while(i < this->capacity && this->hashTable[pos] != this->empty){
        if(this->hashTable[pos] == elem){
            noOccurrence++;
        }
        i++;
        pos = h(elem, i);
    }

    return noOccurrence;
}//Complexity: worst case: O(n)
//              best case: Theta(1)
//              average case: O(n)



int SortedBag::size() const {
    //TODO - Implementation
    return this->length;
}//Complexity: Theta(1)


bool SortedBag::isEmpty() const {
    //TODO - Implementation
    return this->length == 0;
}//Complexity: Theta(1)


SortedBagIterator SortedBag::iterator() const {
    return SortedBagIterator(*this);
}//Complexity: Theta(1)


SortedBag::~SortedBag() {
    //TODO - Implementation
    delete[] this->hashTable;
}//Complexity: O(n)



int SortedBag::hCode(TElem elem) {
    return abs(int(elem));
}

TComp SortedBag::h1(TElem elem) const {
    return hCode(elem) % this->capacity;
}

int SortedBag::h(TElem elem, int i) const {
    return (h1(elem) + i) % this->capacity;
}
