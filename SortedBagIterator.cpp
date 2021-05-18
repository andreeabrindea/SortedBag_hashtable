#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>

using namespace std;

SortedBagIterator::SortedBagIterator(const SortedBag& b) : bag(b) {
    //TODO - Implementation
    this->index = 0;
    this->length = b.length;
    this->array = new TElem[this->length];
    this->k = 0;
    for (int i = 0; i < b.capacity; i++) {
        if (b.hashTable[i] != b.deleted && b.hashTable[i] != b.empty) {
            this->array[this->k++] = b.hashTable[i];
        }
    }
    for (int i = 0; i < k - 1; i++) {
        for (int j = i + 1; j < k; j++) {
            if (!b.relation(this->array[i], this->array[j])) {
                TElem aux;
                aux = this->array[i];
                this->array[i] = this->array[j];
                this->array[j] = aux;
            }
        }
    }

}

TComp SortedBagIterator::getCurrent() {
    //TODO - Implementation
    if (!valid())
        throw std::exception();
    return this->array[this->index];
}

bool SortedBagIterator::valid() {
    //TODO - Implementation
    return this->index < this->length;
}

void SortedBagIterator::next() {
    //TODO - Implementation
    if (!valid())
        throw std::exception();
    this->index++;
}

void SortedBagIterator::first() {
    //TODO - Implementation
    this->index = 0;
}
