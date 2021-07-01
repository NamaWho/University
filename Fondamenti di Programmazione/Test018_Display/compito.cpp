//
// Created by danie on 07/01/2021.
//

#include "compito.h"
#include <iostream>
#include <cstring>
using namespace std;


Display::Display(int row, int col) {

    bool def = (row < 1 || col < 1);
    r = def ? 5 : row;
    c = def ? 8 : col;

    display = new char *[r];

    for (int i = 0; i < r; ++i) {
        display[i] = new char[c+1];
        display[i][0] = '\0';
    }

    cursore = 0;
}

Display::Display(const Display &disp) {

    r = disp.r;
    c = disp.c;
    display = new char *[r];

    for (int i = 0; i < r; ++i) {
        display[i] = new char[c+1];
        strcpy(display[i], disp.display[i]);
    }

    cursore = disp.cursore;

}

void Display::writeT(const char *str) {
    if (str == NULL || strlen(str) == 0) return;

    if (cursore == r) cursore = 0;

    strncpy(display[cursore], str, c);
    display[cursore][c] = '\0';

    cursore++;
}

ostream &operator<<(ostream &os, const Display & disp) {

    for (int i = 0; i < disp.r; ++i) {
        os << "[" << (i+1);
        if (disp.cursore == i) os << ">";
        else os << "]";

        os << disp.display[i] << endl;
    }

    return os;
}

void Display::writeW(char *str) {
    if (str == NULL || strlen(str) == 0) return;

    if (strlen(str) < c) writeT(str);
    else {
        char tempStr [c+1];
        for (int i = 0; i < strlen(str); i += c) {
            strncpy(tempStr, str+i, c);
            writeT(tempStr);
        }
    }
}

Display& Display::operator=(const Display &d1) {

    if (this == &d1) return *this;

    for (int i = 0; i < r; ++i)
        delete [] display[i];

    delete [] display;

    r = d1.r;
    c = d1.c;
    cursore = d1.cursore;

    display = new char *[r];

    for (int i = 0; i < r; ++i) {
        display[i] = new char[c+1];
        strcpy(display[i], d1.display[i]);
    }

    return *this;
}

Display::~Display() {

    for (int i = 0; i < r; ++i)
        delete [] display[i];

    delete [] display;

}




