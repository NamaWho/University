//
// Created by danie on 30/12/2020.
//

#include "compito.h"
#include <iostream>
#include <cstring>

using namespace std;

GestoreApp::GestoreApp() {
    p0 = nullptr;
}

bool GestoreApp::isPresent(const char *str) const {
    if (str == NULL || strlen(str) < 1 || strlen(str) > 20) return false;

    app *q = p0;

    while (q != NULL) {
        if (strcmp(q->name, str) == 0) return true;
        q = q->nextApp;
    }

    return false;
}

GestoreApp& GestoreApp::operator+=(const char *str) {
    if (str == NULL || strlen(str) < 1 || strlen(str) > 20 || isPresent(str)) return *this;

    app *temp = new app;
    strcpy(temp->name, str);
    temp->nextApp = p0;
    p0 = temp;

    return *this;
}

ostream &operator<<(ostream &os, const GestoreApp &gapp) {

    os << "[";
    if (gapp.p0) os << gapp.p0->name;
    os << "]";

    app *q;

    if (gapp.p0) {
        for (q = gapp.p0->nextApp; q != NULL; q = q->nextApp) {
            os << ", " << q->name;
        }
    }


    return os;
}

GestoreApp& GestoreApp::operator-=(const char *str) {
    if (str == NULL || strlen(str) < 1 || strlen(str) > 20 || !isPresent(str)) return *this;

    app *p, *q;

    for (q = p0; q != NULL && strcmp(q->name, str) != 0; q = q->nextApp) {
        p = q;
    }

    if (q == p0) p0 = q->nextApp;
    else p->nextApp = q->nextApp;

    delete q;

    return *this;
}

void GestoreApp::foreground(const char *str) {
    if (str == NULL || strlen(str) < 1 || strlen(str) > 20
        || !isPresent(str)
        || strcmp(p0->name, str) == 0) return;

    operator-=(str);
    operator+=(str);
}

void GestoreApp::chiudi_tutte() {
    app *p, *q;

    for (q = p0; q != NULL; q = q->nextApp) {
        p = q;
        delete q;
        q = p;
    }

    p0 = 0;
}

GestoreApp::~GestoreApp() {
    chiudi_tutte();
}


