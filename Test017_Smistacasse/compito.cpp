//
// Created by danie on 07/01/2021.
//

#include "compito.h"

bool Smistacasse::isIdPresente(int id) const {

    cliente *q;

    for (int i = 0; i < numCasse; ++i) {
        if (casse[i].isAperta && casse[i].numArticoliInCoda) {
            q = casse[i].coda;

            while (q != NULL && (q->id != id))
                q = q->nextCliente;

            if (q != NULL) return true;
        }
    }

    return false;
}

Smistacasse::Smistacasse(int N) {

    numCasse = (N > 0) ? N : 1;

    casse = new cassa[numCasse];

    for (int i = 0; i < numCasse; ++i) {
        casse[i].id = i + 1;
        casse[i].isAperta = true;
        casse[i].numArticoliInCoda = 0;
        casse[i].coda = 0;
    }
}

int Smistacasse::trovaCassa() {

    int id, min = -1;

    //Determino il primo numero minimo della prima cassa aperta
    for (int i = 0; i < numCasse; ++i) {
        if (casse[i].isAperta) {
            min = casse[i].numArticoliInCoda;
            id = i+1;
            break;
        }
    }

    if (min == -1) return min;

    //Determino il minimo confrontando con il primo minimo trovato, partendo da indice = id
    for (int i = id; i < numCasse; ++i) {
        if (casse[i].isAperta && (casse[i].numArticoliInCoda < min)) {
            min = casse[i].numArticoliInCoda;
            id = i + 1;
        }
    }

    return id;
}

void Smistacasse::aggiungi(int idCliente, int numArt) {
    if (idCliente == 0 || numArt < 1 || isIdPresente(idCliente) || (trovaCassa() == -1)) return;

    cliente *p, *q;
    int idCassa = trovaCassa()-1;

    for (q = casse[idCassa].coda; q != NULL; q = q->nextCliente) {
        p = q;
    }

    cliente *temp = new cliente;
    temp->id = idCliente;
    temp->numArticoli = numArt;
    temp->nextCliente = q;

    if (q == casse[idCassa].coda) casse[idCassa].coda = temp;
    else p->nextCliente = temp;

    casse[idCassa].numArticoliInCoda += numArt;
}

ostream &operator<<(ostream &os, const Smistacasse &sms) {

    cliente *q;

    for (int i = 0; i < sms.numCasse; ++i) {
        os << i + 1 << ":_";

        if (!sms.casse[i].isAperta)
            os << "<chiusa>\n";

        else if (sms.casse[i].numArticoliInCoda) {

            for (q = sms.casse[i].coda; q != NULL; q = q->nextCliente)
                os << "(ID=" << q->id << ",_ARTICOLI=" << q->numArticoli << ") ";

            os << ".\n";

        } else
            os << "<vuota>\n";
    }

    return os;
}

void Smistacasse::servi(int nCassa) {

    if (nCassa < 1 || nCassa > numCasse || !casse[nCassa-1].isAperta || casse[nCassa-1].coda == 0) return;

    cliente *q;
    int artDaRimuovere = casse[nCassa-1].coda->numArticoli;

    q = casse[nCassa-1].coda;
    casse[nCassa-1].coda =  casse[nCassa-1].coda->nextCliente;
    delete q;

    casse[nCassa-1].numArticoliInCoda -= artDaRimuovere;
}

void Smistacasse::operator-=(int nCassa) {
    if (nCassa < 1 || nCassa > numCasse || !casse[nCassa-1].isAperta) return;

    casse[nCassa-1].isAperta = false;
    casse[nCassa-1].numArticoliInCoda = 0;

    cliente *r, *p, *q = casse[nCassa-1].coda;

    while(q != NULL){
        r = q;
        p = q->nextCliente;
        servi(nCassa);
        aggiungi(r->id, r->numArticoli);
        q = p;
    }
}

Smistacasse::~Smistacasse() {

    for (int i = 0; i < numCasse; ++i)
        while(casse[i].numArticoliInCoda)
            servi(i+1);

}



