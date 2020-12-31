//
// Created by anviz on 26/12/2020.
//

#include "compito.h"
#include <iostream>

using namespace std;

Flotta::Flotta(int n) {
    if (n < 1) n = 1;
    numRows = n;
    rows = new fila[n];

    for (int i = 0; i < n; ++i) {
        rows[i].isCreated = false;
    }
}

void Flotta::forma_fila(int i, int n) {
    if (i < 0 || i >= numRows || n < 0 || rows[i].isCreated) return;

    rows[i].isCreated = true;
    rows[i].numAirplanes = n;
}

Flotta::operator int() const {
    int maxNum = 0;
    for (int i = 0; i < numRows; ++i) {
        if (rows[i].isCreated)
            maxNum = (rows[i].numAirplanes > maxNum) ? rows[i].numAirplanes : maxNum;
    }
    return maxNum;
}

ostream &operator<<(ostream &os, const Flotta &fl) {

    for (int i = 0; i < fl.numRows; ++i) {

        if (fl.rows[i].isCreated) {
            // White spaces
            for (int j = 0; j < (int(fl) - fl.rows[i].numAirplanes); ++j) {
                os << " ";
            }

            // Print airplanes
            for (int j = 0; j < fl.rows[i].numAirplanes; ++j) {
                os << "A ";
            }
        } else
            for (int j = 0; j < int(fl); ++j) {
                os << "? ";
            }

        os << endl;
    }

    return os;
}

Flotta::~Flotta() {
    delete[] rows;
}

Flotta::Flotta(const Flotta &fl) {
    numRows = fl.numRows;
    rows = new fila[numRows];

    for (int i = 0; i < numRows; ++i) {
        rows[i].isCreated = fl.rows[i].isCreated;
        if (rows[i].isCreated) rows[i].numAirplanes = fl.rows[i].numAirplanes;
    }
}

Flotta operator+(const Flotta &fl1, const Flotta &fl2) {

    int numRows = fl1.numRows + fl2.numRows;
    Flotta temp(numRows);

    for (int i = 0; i < numRows; ++i) {
        if (i < fl1.numRows) {
            if (fl1.rows[i].isCreated)
                temp.forma_fila(i, fl1.rows[i].numAirplanes);
        } else {
            if (fl2.rows[i - fl1.numRows].isCreated)
                temp.forma_fila(i, fl2.rows[i - fl1.numRows].numAirplanes);
        }
    }

    return temp;
}

Flotta &Flotta::operator-=(const Flotta &fl) {
    if (numRows != fl.numRows) return *this;

    for (int i = 0; i < numRows; ++i) {
        if (!rows[i].isCreated || !fl.rows[i].isCreated) return *this;
    }

    for (int i = 0; i < numRows; ++i) {
        if (rows[i].numAirplanes < fl.rows[i].numAirplanes) rows[i].numAirplanes = 0;
        else if (rows[i].numAirplanes == fl.rows[i].numAirplanes) rows[i].numAirplanes /= 2;
    }

    return *this;
}

Flotta &Flotta::operator+=(const int *v) {

    // check ??

    for (int i = 0; i < numRows; ++i) {
        if (rows[i].isCreated && (v[i] >= 0)) rows[i].numAirplanes += v[i];
    }

    return *this;
}







