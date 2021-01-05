//
// Created by danie on 05/01/2021.
//

#include <iostream>
#include "compito.h"
using namespace std;


Rastrelliera::Rastrelliera(int ng, int nv, int nr, int nn) {
    dischi[0] = (ng > 0) ? ng : 10;
    dischi[1] = (nv > 0) ? nv : 10;
    dischi[2] = (nr > 0) ? nr : 10;
    dischi[3] = (nn > 0) ? nn : 10;
}

int* Rastrelliera::carica(const int ng, const int nv, const int nr, const int nn) {

    if (ng < 0 || nv < 0 || nr < 0 || nn < 0 ||
        dischi[0] < ng || dischi[1] < nv || dischi[2] < nr || dischi[3] < nn)
        return NULL;

    int* b = new int [DIM_RASTRELLIERA];

    b[0] = ng;
    dischi[0] -= ng;
    b[1] = nv;
    dischi[1] -= nv;
    b[2] = nr;
    dischi[2] -= nr;
    b[3] = nn;
    dischi[3] -= nn;

    return b;
}

void Rastrelliera::scarica(const int *b) {

    if (b == NULL) return;

    if (b[0] > 0) dischi[0] += b[0];
    if (b[1] > 0) dischi[1] += b[1];
    if (b[2] > 0) dischi[2] += b[2];
    if (b[3] > 0) dischi[3] += b[3];

    delete b;
}

ostream &operator<<(ostream & os, const Rastrelliera & ras) {

    for (int i = 0; i < DIM_RASTRELLIERA; ++i) {
        if (i == 0) os << "GIALLO\t";
        else if (i == 1) os << "VERDE\t";
        else if (i == 2) os << "ROSSO\t";
        else os << "NERO\t";

        os << "<" << ras.dischi[i] << ">\t";

        for (int j = 0; j < ras.dischi[i]; ++j) {
            os << "[] ";
        }

        os << "\n";
    }

    return os;
}

int Rastrelliera::calcolaPeso(const int *b) {

    if (b == NULL) return 0;
    int sum = 0;

    sum += (b[0] > 0) ? b[0] : 0;
    sum += (b[1] > 0) ? b[1]*2 : 0;
    sum += (b[2] > 0) ? b[2]*3 : 0;
    sum += (b[3] > 0) ? b[3]*4 : 0;

    return sum;
}

Rastrelliera &Rastrelliera::operator=(const Rastrelliera &r) {

    dischi[0] = r.dischi[0];
    dischi[1] = r.dischi[1];
    dischi[2] = r.dischi[2];
    dischi[3] = r.dischi[3];

    return *this;
}

int *Rastrelliera::unisci(const int* b1, const int* b2) {

    if (b1 == NULL || b2 == NULL) return NULL;

    int* temp = new int [DIM_RASTRELLIERA];

    temp[0] = ((b1[0] > 0 ) ? b1[0] : 0) + ((b2[0] > 0 ) ? b2[0] : 0);
    temp[1] = ((b1[1] > 0 ) ? b1[1] : 0) + ((b2[1] > 0 ) ? b2[1] : 0);
    temp[2] = ((b1[2] > 0 ) ? b1[2] : 0) + ((b2[2] > 0 ) ? b2[2] : 0);
    temp[3] = ((b1[3] > 0 ) ? b1[3] : 0) + ((b2[3] > 0 ) ? b2[3] : 0);

    delete b1;
    delete b2;

    return temp;
}




