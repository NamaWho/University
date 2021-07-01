//
// Created by danie on 06/01/2021.
//

#include "compito.h"
#include <iostream>
#include <cstring>

using namespace std;

bool Semaforo::isPresent(const char *t) const {

    if (sx0 == 0 && dx0 == 0) return false;

    automobile *q;

    q = sx0;
    while (q != NULL && strcmp(q->targa, t) != 0)
        q = q->nextAuto;
    if (q != NULL) return true;

    q = dx0;
    while (q != NULL && strcmp(q->targa, t) != 0)
        q = q->nextAuto;
    if (q != NULL) return true;

    return false;
}

void Semaforo::empty(char i) {
    if (i != 'D' && i != 'S') return;

    automobile **dir = (i == 'D') ? &dx0 : &sx0;
    automobile *p, *q = *dir;

    while (q != NULL) {
        p = q->nextAuto;
        delete q;
        q = p;
    }

    *dir = 0;
}

int Semaforo::rowLength(automobile **dir) {

    automobile *q;
    int count = 0;

    for (q = *dir; q != NULL; q = q->nextAuto) {
        count++;
    }

    return count;
}

Semaforo::Semaforo() {
    stato = ROSSO;
    dx0 = 0;
    sx0 = 0;
}

void Semaforo::arrivo(const char *t, char d) {
    if ((stato == VERDEDX && d == 'D') ||
        (stato == VERDESX && d == 'S') ||
        strlen(t) != 7 ||
        (d != 'D' && d != 'S') ||
        isPresent(t))
        return;

    automobile *p, *q;
    automobile **dir = (d == 'D') ? &dx0 : &sx0;

    for (q = *dir; q != NULL; q = q->nextAuto)
        p = q;


    automobile *temp = new automobile;
    strcpy(temp->targa, t);
    temp->nextAuto = q;

    if (q == *dir) *dir = temp;
    else p->nextAuto = temp;
}

void Semaforo::cambiaStato() {
    if (stato == ROSSO) {
        stato = VERDEDX;
        empty('D');
    } else if (stato == VERDEDX) {
        stato = VERDESX;
        empty('S');
    } else stato = ROSSO;
}


ostream &operator<<(ostream &os, const Semaforo &sem) {

    automobile *q;

    os << "<";
    if (sem.stato == ROSSO)
        os << "Rosso";
    else if (sem.stato == VERDEDX)
        os << "Verde Destra";
    else
        os << "Verde Sinistra";

    os << ">\n";

    os << "[";
    for (q = sem.dx0; q != NULL; q = q->nextAuto) {
        os << q->targa;
        if (q->nextAuto) os << ",";
    }

    os << "\n[";
    for (q = sem.sx0; q != NULL; q = q->nextAuto) {
        os << q->targa;
        if (q->nextAuto) os << ",";
    }
    os << "\n";

    return os;
}

bool Semaforo::cambiaCorsia(char d) {
    if (d != 'D' && d != 'S') return false;

    automobile **dirPre = (d == 'D') ? &dx0 : &sx0;
    automobile **dirPost = (d == 'D') ? &sx0 : &dx0;
    int lengthPre = rowLength(dirPre);
    int lengthPost = rowLength(dirPost);

    if (lengthPre <= lengthPost) return false;

    //q will be the element which needs to be moved
    automobile *p, *q;

    //Extracting last element
    for (q = *dirPre; q->nextAuto != NULL; q = q->nextAuto)
        p = q;

    if (q == *dirPre) *dirPre = 0;
    else p->nextAuto = 0;

    automobile *z;

    //Going to the last element and place there the new one
    for (z = *dirPost; z != NULL; z = z->nextAuto)
        p = z;

    if (z == *dirPost) {
        if ((stato == VERDEDX && d == 'D') || (stato == VERDESX && d == 'S'))
            delete q;
        else
            *dirPost = q;
    } else p->nextAuto = q;

    return true;
}

Semaforo::operator int() {
    automobile **sx = &sx0;
    automobile **dx = &dx0;

    return rowLength(sx) + rowLength(dx);
}

Semaforo::~Semaforo() {

    automobile *p;

    while (sx0 != NULL) {
        p = sx0->nextAuto;
        delete sx0;
        sx0 = p;
    }

    while (dx0 != NULL) {
        p = dx0->nextAuto;
        delete dx0;
        dx0 = p;
    }
}





