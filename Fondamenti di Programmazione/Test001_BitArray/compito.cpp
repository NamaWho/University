//
// Created by danie on 22/12/2020.
//

#include "compito.h"

BitArray::BitArray(unsigned int arr, int len) {
    booleanArray = arr;
    length = len;
}

BitArray::BitArray(bool *vetBool, int len) {
    if (len <= 0 || len > 32)
        len = 32;

    length = len;
    booleanArray = 0;
    for (int i = 0; i < length; ++i) {
        if (vetBool[i])
            booleanArray |= (1 << (i));
    }
}

ostream &operator<<(ostream &os, const BitArray &array) {
    os << "[";

    for (int i = 0; i < (array.length); ++i) {
        if (array.booleanArray & (1 << i))
            os << "T";
        else os << "F";
        if (i != (array.length - 1)) os << ",";
    }

    os << "]";

    return os;
}

int BitArray::operator!() const {

    int sum = 0;

    for (int i = 0; i < (length); ++i) {
        if (booleanArray & (1 << i))
            sum++;
    }
    return sum;
}

BitArray BitArray::operator|(const BitArray &ba) const {

    unsigned int boolArray = (booleanArray | ba.booleanArray);
    int len = (length > ba.length) ? length : ba.length;

    BitArray newItem(boolArray, len);

    return newItem;
}

bool BitArray::setBit(int start, int end, bool val) {
    if (start < 0 || end > (length - 1) || (start > end))
        return false;

    unsigned int mask = (1 << end + 1) - (1 << start);

    if (val) booleanArray |= mask;
    else booleanArray &= ~mask;

    return true;
}

bool BitArray::flip(int start, int end) {
    if (start < 0 || end > (length - 1) || (start > end))
        return false;

    unsigned int mask = (1 << end + 1) - (1 << start);

    booleanArray ^= mask;
}

int BitArray::maxSubSeq() const {
    int seq = 0;
    int tempSeq = 0;

    for (int i = 0; i < length; ++i) {
        if ((booleanArray & (1 << i))){
            seq = (seq < tempSeq) ? tempSeq : seq;
            tempSeq = 0;
        } else tempSeq += 1;
    }

    return seq;
}






