//
// Created by danie on 06/01/2021.
//

#ifndef TEST16_SEMAFORO_COMPITO_H
#define TEST16_SEMAFORO_COMPITO_H

#include <iostream>
#include <cstring>
using namespace std;

const int DIM_TARGA = 7;

enum statiSemaforo {
    ROSSO,
    VERDEDX,
    VERDESX
};

struct automobile {
    char targa [DIM_TARGA+1];
    automobile* nextAuto;
};

class Semaforo {

    statiSemaforo stato;
    automobile* dx0;
    automobile* sx0;

    //Utility function
    bool isPresent(const char *) const;
    void empty(char i);
    int rowLength(automobile**);

public:
    Semaforo();
    void arrivo(const char *, char);
    void cambiaStato();
    friend ostream& operator<<(ostream&, const Semaforo &);
    bool cambiaCorsia(char);
    operator int();
    ~Semaforo();
};


#endif //TEST16_SEMAFORO_COMPITO_H
