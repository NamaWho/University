//
// Created by danie on 04/01/2021.
//

#include "compito.h"
#include <iostream>

using namespace std;

TorreDiPisa::TorreDiPisa(unsigned int n) {

    maxLoggiati = (n > 0) ? n : 1;
    loggiati = 0;

    torre = new loggiato[maxLoggiati];

    for (int i = 0; i < maxLoggiati; ++i) {
        torre[i].isPresent = false;
    }
}

TorreDiPisa::TorreDiPisa(const TorreDiPisa &tdp) {

    maxLoggiati = tdp.maxLoggiati;
    loggiati = tdp.loggiati;

    torre = new loggiato[maxLoggiati];

    for (int i = 0; i < loggiati; i++){
        torre[i].pend = tdp.torre[i].pend;
        torre[i].isPresent = tdp.torre[i].isPresent;
    }
}


TorreDiPisa& TorreDiPisa::operator+=(const int p) {

    if (loggiati > 0 &&
        ((p < torre[loggiati - 1].pend) ||
         ((p - torre[loggiati - 1].pend) > 4) ||
         (loggiati == maxLoggiati)))
        return *this;

    torre[loggiati].isPresent = true;
    torre[loggiati].pend = p;
    loggiati++;

    return *this;
}

ostream &operator<<(ostream &os, const TorreDiPisa &tdp) {

    if (!tdp.isEmpty()) {
        for (int i = 0; i < tdp.torre[tdp.loggiati - 1].pend; ++i)
            os << " ";
    }
    for (int i = 0; i < 8; ++i)
        os << "=";
    os << endl;

    for (int i = tdp.loggiati - 1; i >= 0; --i) {

        for (int j = 0; j < tdp.torre[i].pend; ++j)
            os << " ";

        for (int j = 0; j < 8; ++j)
            os << "|";

        os << endl;
    }

    for (int i = 0; i < 8; ++i) os << "=";
    os << endl;

    return os;
}

TorreDiPisa::operator int() const {

    if (isEmpty()) return 0;

    int sum = 0;

    for (int i = 0; i < loggiati; ++i) {
        sum += torre[i].pend;
    }

    return (sum / loggiati);
}

bool TorreDiPisa::isEmpty() const {

    for (int i = 0; i < loggiati; ++i) {
        if (torre[i].isPresent) return false;
    }
    return true;
}

//Test if the movement is possible
bool TorreDiPisa::isMovePossible() const {

    if (loggiati == 0) return false;

    for (int i = loggiati - 1; i > 0; --i) {
        if (((torre[i].pend + 1) - (torre[i - 1].pend)) > 4) return false;
    }

    return true;
}

TorreDiPisa TorreDiPisa::operator++(int) {

    if (!isMovePossible()) return *this;

    TorreDiPisa temp(*this);

    for (int i = 0; i < loggiati; ++i) {
        torre += (i+1);
    }

    return temp;
}





