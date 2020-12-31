//
// Created by danie on 27/12/2020.
//

#include "compito.h"
#include <cmath>

Polinomio::Polinomio(unsigned int deg, const int *coeff) {
    this->deg = (deg > 0) ? deg : 1;
    this->coeff = new int[deg + 1];

    for (int i = 0; i < (deg + 1); ++i) {
        this->coeff[i] = coeff[i];
    }

    if (this->coeff[0] == 0) this->coeff[0] = 1;

}

int Polinomio::valuta(int x) const {
    int sol = 0, pow;

    for (int i = 0; i < (deg + 1); ++i) {

        pow = 1;

        //Calculate power
        for (int j = 0; j < (deg - i); ++j) {
            pow *= x;
        }

        sol += (coeff[i] * pow);
    }

    return sol;
}

ostream &operator<<(ostream &os, const Polinomio &pl) {

    for (int i = 0; i < (pl.deg + 1); ++i) {
        if (pl.coeff[i] >= 0) os << "+";
        else os << "-";
        os << abs(pl.coeff[i]);
        if (pl.deg - i) os << "x^" << (pl.deg - i) << " ";
    }

    return os;
}

Polinomio::~Polinomio() {
    delete[] coeff;
}

Polinomio::operator bool() const {

    int initSign = coeff[0];

    for (int i = 1; i < deg + 1; ++i) {
        if ((coeff[i] * initSign) < 0) return false;
    }

    return true;
}

void Polinomio::operator=(const Polinomio &pl1) {
    deg = pl1.deg;
    delete coeff;
    coeff = new int[deg + 1];

    for (int i = 0; i < (deg + 1); ++i) {
        coeff[i] = pl1.coeff[i];
    }
}

Polinomio operator*(const Polinomio &pl1, const Polinomio &pl2) {

    int newDeg = pl1.deg + pl2.deg;
    int newCoeff[newDeg + 1];

    for (int i = 0; i < (newDeg+1); ++i) {
        newCoeff[i] = 0;
    }

    for (int i = 0; i < (pl1.deg + 1); ++i) {
        for (int j = 0; j < (pl2.deg + 1); ++j) {
            newCoeff[newDeg-((pl1.deg-i)+(pl2.deg-j))] += (pl1.coeff[i]*pl2.coeff[j]);
        }
    }

    return Polinomio(newDeg, newCoeff);
}
