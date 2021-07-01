//
// Created by danie on 29/12/2020.
//

#include "compito.h"
#include <iostream>
#include <cstring>

using namespace std;

Timeline::Timeline() {
    p0 = nullptr;
}

void Timeline::pubblica(const char *str, bool highlight) {
    if (str == NULL || strlen(str) < 1) return;

    photo* temp = new photo;
    temp->name = new char [strlen(str)];
    strcpy(temp->name, str);
    temp->highlighted = highlight;

    if(highlight){
        temp->nextPhoto = p0;
        p0 = temp;
    } else {

        photo *p, *q;

        for (q = p0; q != NULL && q->highlighted; q = q->nextPhoto) {
            p = q;
        }

        temp->nextPhoto = q;

        if (q==p0) p0 = temp;
        else p->nextPhoto = temp;
    }
}

void Timeline::cancella(const char * str) {
    if (str == NULL || strlen(str) < 1) return;

    photo *p, *q;

    for (q = p0; q != NULL && strcmp(q->name, str) != 0; q = q->nextPhoto) {
        p = q;
    }

    if (q != NULL){
        if (q == p0) p0 = q->nextPhoto;
        else p->nextPhoto = q->nextPhoto;
        delete [] q->name;
        delete q;
    }
}

ostream &operator<<(ostream &os, const Timeline & tml) {

    photo *q;

    os << "-----" << endl;
    for (q = tml.p0; q != NULL; q = q->nextPhoto) {
        if (q->highlighted) os << "(*)";
        os << q->name << endl;
    }
    os << "-----" << endl;

    return os;
}

bool Timeline::operator!() {

    photo *p, *q;
    bool deleted = false;

    for (q = p0; q != NULL && q->highlighted ; q = q->nextPhoto) {
        p = q;
        deleted = true;
        cancella(q->name);
        q = p;
    }

    return deleted;
}

void Timeline::mettiInEvidenza(const char * str) {
    if (str == NULL || strlen(str) < 1) return;

    photo *p, *q;

    for (q = p0; q != NULL && strcmp(q->name, str) != 0; q = q->nextPhoto) {
        p = q;
    }

    if (q != NULL && !q->highlighted){
        cancella(q->name);
        pubblica(q->name, true);
    }
}

Timeline::~Timeline() {
    photo *p, *q;

    for (q = p0; q != NULL; q = q->nextPhoto) {
        p = q;
        delete [] q->name;
        delete q;
        q = p;
    }
}




