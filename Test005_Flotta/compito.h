//
// Created by anviz on 26/12/2020.
//

#ifndef TEST5_FLOTTA_COMPITO_H
#define TEST5_FLOTTA_COMPITO_H

#include <iostream>
using namespace std;

struct fila {
    int numAirplanes;
    bool isCreated;
};

class Flotta {
    fila *rows;
    unsigned int numRows;

    Flotta();
    Flotta& operator=(const Flotta &);
public:
    Flotta(int);
    Flotta(const Flotta &);
    void forma_fila(int, int);
    operator int() const;
    friend ostream& operator<<(ostream&, const Flotta &);
    friend Flotta operator+(const Flotta &, const Flotta &);
    Flotta& operator-=(const Flotta &);
    Flotta& operator+=(const int []);

    ~Flotta();
};


#endif //TEST5_FLOTTA_COMPITO_H
