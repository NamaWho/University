//
// Created by danie on 22/12/2020.
//

#ifndef FDP_EX1_COMPITO_H
#define FDP_EX1_COMPITO_H

#include <iostream>

using namespace std;

class BitArray {
    unsigned int booleanArray;
    unsigned int length;

    BitArray(unsigned int, int);
public:
    BitArray(bool *, int);

    friend ostream &operator<<(ostream &os, const BitArray &);

    int operator!() const;

    BitArray operator|(const BitArray &) const;

    bool setBit(int, int, bool);

    bool flip(int, int);

    int maxSubSeq() const;
};


#endif //FDP_EX1_COMPITO_H
