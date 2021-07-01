// Namaki

#ifndef TEST019_RISTORANTE_COMPITO_H
#define TEST019_RISTORANTE_COMPITO_H

#include <iostream>
using namespace std;

struct gruppo {
    char* cognome;
    int numPersone;
    gruppo* nextGruppo;
};

class Ristorante {

    int numPosti;
    int numPostiOccupati;
    gruppo* p0;

    void seatGroupsIfPossible();

public:
    Ristorante(int);
    void aggiungi(const char *, int);
    friend ostream& operator<<(ostream&, const Ristorante&);
    Ristorante& operator-= (int);

    Ristorante(const Ristorante &);
    bool rinuncia(const char *);
    ~Ristorante();

};


#endif //TEST019_RISTORANTE_COMPITO_H
