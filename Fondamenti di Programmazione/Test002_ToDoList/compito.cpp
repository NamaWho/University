//
// Created by danie on 23/12/2020.
//

#include <iostream>
#include <cstring>
#include "compito.h"

using namespace std;

ToDoList::ToDoList() {
    p0 = 0;
}

void ToDoList::aggiungi(const char *description, unsigned int priority) {

    if (description == NULL || priority < 1 || strlen(description) > MAX_DIM_DESC)
        return;

    compito *p = 0, *q;

    for (q = p0; q != NULL && q->priority <= priority; q = q->nextCompito) {
        p = q;
    }

    compito *temp = new compito;
    temp->priority = priority;
    strcpy(temp->desc, description);
    temp->isDone = false;
    temp->nextCompito = q;

    //Aggiunta in testa
    if (q == p0) p0 = temp;
    else p->nextCompito = temp;
}

ostream &operator<<(ostream &os, const ToDoList &tdl) {

    compito *p;

    for (p = tdl.p0; p != NULL; p = p->nextCompito) {
        if (p->isDone)
            os << "V ";
        else os << "  ";
        os << p->priority << " - " << p->desc << endl;

    }

    return os;
}

ToDoList::~ToDoList() {

    compito *p, *q;

    for (p = p0; p != NULL;) {
        q = p;
        p = p->nextCompito;
        delete q;
    }
}

ToDoList &ToDoList::operator+=(const ToDoList &tdl) {

    if (&tdl == this) return *this;

    compito *z;
    compito *p, *q;

    // Selezione di ogni task di tdl
    for (z = tdl.p0; z != NULL; z = z->nextCompito)
        aggiungi(z->desc, z->priority);

    return *this;
}

void ToDoList::fai(const char *descr) {
    if (descr == NULL || strlen(descr) > MAX_DIM_DESC)
        return;

    compito *p;

    for (p = p0; p != NULL; p = p->nextCompito) {
        if ((strcmp(p->desc, descr) == 0) && !(p->isDone)) {
            p->isDone = true;
            break;
        }
    }
}

void ToDoList::cancella_fatti() {

    compito *p, *q, *r;
    for(p = p0; p != NULL; p = p->nextCompito){
        if(p->isDone){
            if(p == p0){ // estrazione in testa
                r = p0->nextCompito;
                delete p0;
                p0 = r;
            }
            else{ // estrazione in mezzo o in fondo
                r = p->nextCompito;
                delete p;
                q->nextCompito = r;
                p=q;
            }
        }
        q = p;
    }

}
