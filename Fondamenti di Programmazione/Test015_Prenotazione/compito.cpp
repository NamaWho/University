//
// Created by danie on 05/01/2021.
//

#include "compito.h"


bool Prenotazione::hasAlreadyBooked(int cod, bool checkAbb, abbonamento type) const {

    if (p0 == 0) return false;

    cliente *q = p0;

    while ( q != NULL){

        if ( q->id == cod &&
            (!(checkAbb) || (type == q->t)))
            break;

        q = q->nextCliente;
    }

    if (q == NULL) return false;

    return true;
}

Prenotazione::Prenotazione() {
    p0 = 0;
    isOpen = true;
}

void Prenotazione::prenota(int cod, abbonamento abb) {
    if (!isOpen || cod < 1 || hasAlreadyBooked(cod, false)) return;

    cliente *p, *q;

    if (abb == GOLD)
        for (q = p0; q != NULL && (q->t != SILVER); q = q->nextCliente)
            p = q;
    else
        for (q = p0; q != NULL; q = q->nextCliente)
            p = q;

    cliente* temp = new cliente;
    temp->id = cod;
    temp->t = abb;
    temp->nextCliente = q;

    if (q == p0) p0 = temp;
    else p->nextCliente = temp;
}

void Prenotazione::cancella(int cod, abbonamento abb) {
    if ( !isOpen ||
         cod < 1 ||
         !hasAlreadyBooked(cod, true, abb)
         )
        return;

    cliente *p, *q;

    for (q = p0; q != NULL && (q->id != cod); q = q->nextCliente) {
        p = q;
    }

    if (q == p0) p0 = q->nextCliente;
    else p->nextCliente = q->nextCliente;

    delete q;
}

ostream &operator<<(ostream & os, const Prenotazione & pre) {

    cliente *q;

    os << "GOLD\n";
    for (q = pre.p0; q != NULL && (q->t != SILVER); q = q->nextCliente)
        os << q->id << "\n";

    os << "SILVER\n";
    for (; q != NULL; q = q->nextCliente)
        os << q->id << "\n";

    return os;
}

Prenotazione::operator int() const{

    if (p0 == 0) return 0;

    int gold = 0, silver = 0;
    cliente *q;

    for (q = p0; q != NULL && q->t != SILVER ; q = q->nextCliente) {
        gold++;
        if (gold == MAX_PARTICIPANTS) return 0;
    }

    for (; q != NULL && (gold+silver) < MAX_PARTICIPANTS; q = q->nextCliente)
        silver++;

    return silver;
}

Ammessi Prenotazione::chiudi() {

    cliente *q;
    Ammessi list;
    int i = 0;

    for (q = p0; q != NULL && (i < MAX_PARTICIPANTS); ++i, q = q->nextCliente) {
        list.elenco[i].id = q->id;
        list.elenco[i].t = q->t;
    }

    list.quanti = i;
    isOpen = false;
    return list;
}

Prenotazione::~Prenotazione() {

    cliente *p, *q = p0;

    while (q != NULL){
        p = q->nextCliente;
        delete q;
        q = p;
    }
}



