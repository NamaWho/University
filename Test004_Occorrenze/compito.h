//
// Created by danie on 26/12/2020.
//

#ifndef TEST4_OCCORRENZE_COMPITO_H
#define TEST4_OCCORRENZE_COMPITO_H

#include <iostream>
using namespace std;

const int MAX_DIM_WORD = 31;

struct parola {
    char word[MAX_DIM_WORD];
    unsigned int occurs;
    parola* nextWord;
};

class Occorrenze {
    parola* p0;

    // Private methods
    void add(const char []);

    // Forbidden methods
    Occorrenze();
    Occorrenze(const Occorrenze&);
    Occorrenze& operator=(const Occorrenze&);

public:
    Occorrenze(const char*);
    friend ostream& operator<<(ostream &, const Occorrenze &);
    int operator%(int) const;

    void operator+=(const char[]);
    int operator[](const char[]);
    void operator-=(const char);

    ~Occorrenze();
};


#endif //TEST4_OCCORRENZE_COMPITO_H
