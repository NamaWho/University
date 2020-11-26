#include "iscrizione.h"
#include <iostream>
#include <cstring>

using namespace std;

// Inizializza la lista settando il pointer a 0
void init(elem *&p0) {
    p0 = nullptr;
}

// Visualizzazione degli elementi a partire DALLA CODA della pila
// L'ordine di stampa sarà:
// Primo -> Secondo -> Terzo
void visualizza(elem *p0) {
    cout << "Atleti iscritti: \n";

    for (elem *q = p0; q != 0; q = q->pun) {
        cout << q->nome << ", " << q->pettorale << "\n";
    }

    cout << endl;
}

// Aggiunta di elementi IN TESTA alla lista
// Primo -> Secondo -> newItem
bool aggiungi(elem *&p0, const char *name, int num) {

    if (name == NULL || strlen(name) > 30) return false;

    elem *newItem;
    elem *p = 0;

    // Scorre la lista fino alla testa
    // Se trova un'occorrenza già inserita, restituisce false
    for (elem *q = p0; q != 0; q = q->pun) {
        if ((strcmp(name, q->nome) == 0) || (q->pettorale == num)) return false;
        p = q;
    }

    newItem = new elem;

    if (p0 == 0) p0 = newItem;
    else p->pun = newItem;

    strcpy(newItem->nome, name);
    newItem->pettorale = num;
    newItem->pun = nullptr;

    return true;
}

// Scorre tutta la lista
// Se trova un'occorrenza, restituisce true
bool cerca(elem *p0, const char *name) {

    for (elem *q = p0; q != 0; q = q->pun) {
        if (strcmp(name, q->nome) == 0) return true;
    }
}

// Elimina l'atleta corrispondente al nome inserito
bool elimina(elem *&p0, const char *name) {
    if (p0 == 0) return false;

    elem *q;
    elem *p = nullptr;

    for (q = p0; ((q != 0) && (strcmp(q->nome, name) != 0)); q = q->pun) {
        p = q;
    }

    if (q == 0) return false;
    if (q == p0) p0 = q->pun;
    else p->pun = q->pun;

    delete q;
    return true;
}
