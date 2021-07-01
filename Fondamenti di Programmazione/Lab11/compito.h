//
// Created by danie on 10/12/2020.
//

#ifndef LAB11_COMPITO_H
#define LAB11_COMPITO_H


class Palazzo {
    unsigned int maxPiani;
    unsigned int numPiani;
    bool** finestre;

public:
    Palazzo(unsigned int);
    Palazzo(const Palazzo &);
    bool aggiungi();
    void stampa();
    ~Palazzo();
    bool cambia(unsigned int, unsigned int);
    int operator!();
    bool operator%=(Palazzo);
};


#endif //LAB11_COMPITO_H
