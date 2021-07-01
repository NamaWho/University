//
// Created by danie on 05/01/2021.
//

#include "compito.h"
#include <iostream>

using namespace std;

ContenitoreDVD::ContenitoreDVD() {
    p0 = 0;
}

void ContenitoreDVD::aggiungi() {

    dvd *q = p0;

    if (p0 != 0)
        while (q->nextDvd != NULL) {
            q = q->nextDvd;
        }

    dvd *temp = new dvd;
    temp->isVirgin = true;
    temp->nextDvd = 0;

    if (p0 == 0) p0 = temp;
    else q->nextDvd = temp;
}

void ContenitoreDVD::aggiungi(const char g) {
    if (g != 'V' && g != 'D') return;

    aggiungi();

    dvd *q = p0;

    while (q->nextDvd != NULL) {
        q = q->nextDvd;
    }

    q->isVirgin = false;
    q->genre = g;
}

bool ContenitoreDVD::masterizza(const char g) {
    if (g != 'V' && g != 'D') return false;

    dvd *q = p0;

    while (q != NULL && !q->isVirgin)
        q = q->nextDvd;

    if (q == NULL) return false;
    else {
        q->isVirgin = false;
        q->genre = g;
        return true;
    }
}

ostream &operator<<(ostream &os, const ContenitoreDVD &cdvd) {

    dvd *p;

    os << "[";

    for (p = cdvd.p0; p != NULL; p = p->nextDvd) {
        if (p->isVirgin) os << "-";
        else os << p->genre;
    }

    os << "]";

    return os;
}

void ContenitoreDVD::elimina() {

    if (p0 == 0) return;

    dvd *p = p0, *q;

    for (q = p0; q != NULL && !q->isVirgin; q = q->nextDvd) {
        p = q;
    }

    if (q == NULL) return;
    else {
        p->nextDvd = q->nextDvd;
        delete q;
    }
}

ContenitoreDVD::ContenitoreDVD(const ContenitoreDVD & c) {
    p0 = 0;

    dvd *p;

    for (p = c.p0; p != NULL; p = p->nextDvd) {
        if (p->isVirgin) aggiungi();
        else aggiungi(p->genre);
    }

}

int ContenitoreDVD::operator~() const{
    if (p0 == NULL) return 0;
    int sum = 0;
    dvd* p;

    for (p = p0; p != NULL; p = p->nextDvd)
        if (p->isVirgin)
            sum++;

    return sum;
}

int ContenitoreDVD::operator%(const char g) const {
    if (p0 == NULL || (g != 'V' && g != 'D')) return 0;

    int sum = 0;
    dvd* p;

    for (p = p0; p != NULL; p = p->nextDvd)
        if (p->genre == g)
            sum++;

    return sum;
}

ContenitoreDVD::~ContenitoreDVD() {

    dvd *p, *q = p0;

    while(q != NULL){
        p = q->nextDvd;
        delete q;
        q = p;
    }
}



