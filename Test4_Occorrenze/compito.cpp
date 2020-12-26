//
// Created by danie on 26/12/2020.
//

#include "compito.h"
#include <iostream>
#include <cstring>

using namespace std;

Occorrenze::Occorrenze(const char frase[]) {
    p0 = nullptr;
    bool newWord = true;
    char item[MAX_DIM_WORD];

    for (int i = 0, h = 0; i <= strlen(frase); ++i) {
        if ((i < strlen(frase)) && (frase[i] != ' ')) {
            if (newWord)
                newWord = false;

            item[h] = frase[i];
            h++;
        } else {
            item[h] = '\0';
            add(item);

            //Skip spaces
            while (frase[i] == ' ') i++;
            if (i < strlen(frase)) i--;

            h = 0;
            newWord = true;
        }
    }
}

void Occorrenze::add(const char word[]) {

    parola *p = 0, *q;

    for (q = p0; q != NULL && strcmp(q->word, word) <= 0; q = q->nextWord) {
        p = q;
    }

    if (p != 0 && strcmp(p->word, word) == 0) {
        p->occurs++;
        return;
    }

    parola *temp = new parola;
    strcpy(temp->word, word);
    temp->occurs = 1;
    temp->nextWord = q;

    if (q == p0) p0 = temp;
    else p->nextWord = temp;
}

ostream &operator<<(ostream &os, const Occorrenze &occ) {

    parola *p;

    for (p = occ.p0; p != NULL; p = p->nextWord) {
        os << p->word << ":" << p->occurs << endl;
    }

    return os;
}

int Occorrenze::operator%(int val) const {
    if (val <= 1)
        return 0;

    int occ = 0;

    parola *p;

    for (p = p0; p != NULL; p = p->nextWord) {
        if (p->occurs >= val) occ++;
    }

    return occ;
}

void Occorrenze::operator+=(const char *word) {
    add(word);
}

int Occorrenze::operator[](const char *word) {

    parola *p = p0;

    while (p != NULL && strcmp(p->word, word) != 0)
        p = p->nextWord;

    if (p != NULL) return p->occurs;

    return 0;
}

void Occorrenze::operator-=(const char letter) {
    parola *p, *q, *r;

    for (q = p0; q != NULL; q = q->nextWord) {
        if (q->word[0] == letter) {
            if (q == p0) { // At the top
                r = p0->nextWord;
                delete p0;
                p0 = r;
            } else { // In the middle or at the bottom
                r = q->nextWord;
                delete q;
                p->nextWord = r;
                q = p;
            }
        }
        p = q;
    }
}

Occorrenze::~Occorrenze() {

    parola *p = p0, *q;

    while (p != NULL){
        q = p;
        p = p->nextWord;
        delete q;
    }


}

