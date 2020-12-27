//
// Created by danie on 27/12/2020.
//

#ifndef TEST6_POLINOMIO_COMPITO_H
#define TEST6_POLINOMIO_COMPITO_H

#include <iostream>
using namespace std;

class Polinomio {
    unsigned int deg;
    int *coeff;
public:

    //FIRST PART
    Polinomio(unsigned int, const int *);
    int valuta(int) const;
    friend ostream& operator<<(ostream&, const Polinomio &);
    ~Polinomio();

    //SECOND PART
    operator bool() const;
    void operator=(const Polinomio &);
    friend Polinomio operator*(const Polinomio&, const Polinomio &);
};


#endif //TEST6_POLINOMIO_COMPITO_H
