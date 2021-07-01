//
// Created by danie on 05/01/2021.
//

#ifndef TEST14_RASTRELLIERA_COMPITO_H
#define TEST14_RASTRELLIERA_COMPITO_H

#include <iostream>
using namespace std;

const int DIM_RASTRELLIERA = 4;

class Rastrelliera {

    int dischi[DIM_RASTRELLIERA];

public:

    Rastrelliera(int ng = 10, int nv = 10,int nr = 10,int nn = 10);
    int* carica(const int, const int,const int,const int);
    void scarica(const int*);
    friend ostream& operator<< (ostream&, const Rastrelliera &);
    static int calcolaPeso(const int*);

    Rastrelliera& operator=(const Rastrelliera &);
    static int* unisci(const int*, const int*);

};


#endif //TEST14_RASTRELLIERA_COMPITO_H
