//
// Created by danie on 07/01/2021.
//

#ifndef TEST17_SMISTACASSE_COMPITO_H
#define TEST17_SMISTACASSE_COMPITO_H

#include <iostream>
using namespace std;

struct cliente {
    int id;
    unsigned int numArticoli;
    cliente* nextCliente;
};

struct cassa {
    unsigned int id;
    bool isAperta;
    unsigned int numArticoliInCoda;
    cliente* coda;
};

class Smistacasse {

    cassa *casse;
    unsigned int numCasse;

    bool isIdPresente(int cliente) const;

public:
    Smistacasse(int);

    int trovaCassa();

    void aggiungi(int, int);

    friend ostream& operator<<(ostream&, const Smistacasse &);

    void servi(int);

    void operator-= (int);

    ~Smistacasse();

};


#endif //TEST17_SMISTACASSE_COMPITO_H
