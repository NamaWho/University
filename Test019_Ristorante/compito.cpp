#include "compito.h"
#include <iostream>
#include <cstring>

using namespace std;


void Ristorante::seatGroupsIfPossible() {
    gruppo *q;

    while ((numPostiOccupati + p0->numPersone) <= numPosti) {
        numPostiOccupati += p0->numPersone;
        q = p0->nextGruppo;
        delete p0->cognome;
        delete p0;
        p0 = q;
    }
}

Ristorante::Ristorante(int N) {
    numPosti = (N < 1) ? 1 : N;
    numPostiOccupati = 0;
    p0 = 0;
}

void Ristorante::aggiungi(const char *cog, int num) {
    if (num < 1 || strlen(cog) == 0 || ((numPostiOccupati + num) > numPosti && cog == NULL))
        return;

    if ((p0 == 0) && (numPostiOccupati + num <= numPosti)) numPostiOccupati += num;
    else {

        gruppo *p, *q;

        for (q = p0; q != NULL; q = q->nextGruppo) {
            p = q;
        }

        gruppo *temp = new gruppo;
        temp->cognome = new char[strlen(cog) + 1];
        strcpy(temp->cognome, cog);
        temp->numPersone = num;
        temp->nextGruppo = q;

        if (p0 == q) p0 = temp;
        else p->nextGruppo = temp;
    }
}

ostream &operator<<(ostream &os, const Ristorante &r) {

    os << "Posti liberi " << (r.numPosti - r.numPostiOccupati) << ", in attesa ";

    if (r.p0 == 0) os << "nessuno";
    else
        for (gruppo *q = r.p0; q != NULL; q = q->nextGruppo)
            os << q->cognome << "(" << q->numPersone << ") ";
    os << "\n";

    return os;
}

Ristorante &Ristorante::operator-=(int num) {

    if (num < 1 || num > numPostiOccupati) return *this;


    numPostiOccupati -= num;

    seatGroupsIfPossible();

    return *this;
}

Ristorante::Ristorante(const Ristorante &r) {
    numPosti = r.numPosti;
    numPostiOccupati = r.numPostiOccupati;
    p0 = 0;
    gruppo *q;

    for (q = r.p0; q != NULL; q = q->nextGruppo) {
        aggiungi(q->cognome, q->numPersone);
    }
}

bool Ristorante::rinuncia(const char *cog) {

    if (cog == NULL || strlen(cog) < 1) return false;

    gruppo *p, *q;

    for (q = p0; q != NULL && strcmp(q->cognome, cog) != 0; q = q->nextGruppo)
        p = q;

    if (q == NULL) return false;
    if (q == p0) p0 = q->nextGruppo;
    else p->nextGruppo = q->nextGruppo;

    delete q->cognome;
    delete q;

    seatGroupsIfPossible();

    return true;
}

Ristorante::~Ristorante() {

    gruppo *q;

    while (p0 != NULL){
        q = p0->nextGruppo;
        delete p0->cognome;
        delete p0;
        p0 = q;
    }
}




