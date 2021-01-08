// Namaki

#include "compito.h"
#include <iostream>

using namespace std;

//Funzione di utilità
int Nastro::isPresente(const char *n) const {
    if (strlen(n) > MAX_NOME_LENGTH)
        return -1;

    piatto *q = p0;

    while (q != NULL && strcmp(q->nome, n) != 0)
        q = q->nextPiatto;

    if (q == NULL) return -1;
    else return q->prezzo;
}

Nastro::Nastro() {
    p0 = 0;
    conto = 0;
}

void Nastro::aggiungi(const char *n, int pr) {
    char nome[MAX_NOME_LENGTH + 1];
    if (n == NULL || strlen(n) > MAX_NOME_LENGTH)
        strcpy(nome, "");
    else strcpy(nome, n);
    if (pr < 0)
        pr = 0;

// Applicata la correzione della variabile "n" da trasformare in "nome"
// Sostituendo le parole con l'apposita funzione venivano sostituite
// anche le lettere "n" presenti

//Se è presente con un prezzo diverso, annulla l'aggiunta
    int prezzoPresente = isPresente(nome);
    if (prezzoPresente >= 0 && prezzoPresente != pr) return;

    piatto *p, *q;

    for (q = p0; q != NULL && (q->prezzo < pr); q = q->nextPiatto)
        p = q;

// Se hanno lo stesso prezzo, inserisci in ordine lessicografico
    if (q != NULL && q->prezzo == pr)
        for (; q != NULL && (q->prezzo == pr) && (strcmp(q->nome, nome) < 0); q = q->nextPiatto)
            p = q;

    piatto *temp = new piatto;
    strcpy(temp->nome, nome);
    temp->prezzo = pr;
    temp->nextPiatto = q;

    if (q == p0) //Inserimento in testa
        p0 = temp;
    else
        p->nextPiatto = temp;
}

Nastro &Nastro::consuma(const char *n) {
    //Nome invalido
    if (n == NULL || strlen(n) > MAX_NOME_LENGTH)
        return *this;

    //Piatto non presente
    if (isPresente(n) == -1) return *this;

    piatto *p, *q;

    for (q = p0; q != NULL && strcmp(q->nome, n) != 0; q = q->nextPiatto)
        p = q;

    //Estrazione in testa
    if (q == p0) p0 = q->nextPiatto;
        //Estrazione in mezzo o in fondo
    else p->nextPiatto = q->nextPiatto;

    conto += q->prezzo;

    delete q;
    return *this;
}


ostream &operator<<(ostream &os, const Nastro &c1) {

    os << "Piatti sul nastro:\n";

    piatto *q;

    for (q = c1.p0; q != NULL; q = q->nextPiatto) {
        os << "    " << q->nome << " " << q->prezzo << "\n";
    }

    os << "Conto: " << c1.conto << "\n";

    return os;
}

Nastro &Nastro::operator+=(const Nastro &n1) {

    //Anti Aliasing
    if (this == &n1) return *this;

    piatto *q;

    for (q = n1.p0; q != NULL; q = q->nextPiatto)
        aggiungi(q->nome, q->prezzo);


    return *this;
}

Nastro operator|(const Nastro &n1, const Nastro &n2) {

    Nastro temp;
    piatto *q;
    int prezzon;

    //Scorro tutti gli elementi di n1 e guardo se in n2 è presente lo stesso el. con prezzo minore
    for (q = n1.p0; q != NULL; q = q->nextPiatto) {
        prezzon = n2.isPresente(q->nome);
        if (prezzon >= 0 && prezzon < q->prezzo)
            temp.aggiungi(q->nome, prezzon);
        else
            temp.aggiungi(q->nome, q->prezzo);
    }

    for (q = n2.p0; q != NULL; q = q->nextPiatto) {
        if (!((temp.isPresente(q->nome) >= 0 && temp.isPresente(q->nome) < q->prezzo) ||
              (n1.isPresente(q->nome) >= 0 && n1.isPresente(q->nome) > q->prezzo))) {
            prezzon = n1.isPresente(q->nome);
            if (prezzon >= 0 && prezzon < q->prezzo)
                temp.aggiungi(q->nome, prezzon);
            else
                temp.aggiungi(q->nome, q->prezzo);
        }
    }

    return temp;
}

Nastro::~Nastro() {

    piatto *q;

    while (p0 != NULL) {
        q = p0->nextPiatto;
        delete p0;
        p0 = q;
    }
}
