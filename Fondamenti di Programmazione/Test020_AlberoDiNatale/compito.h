//
// Created by danie on 07/01/2021.
//

#ifndef TEST20_ALBERODINATALE_COMPITO_H
#define TEST20_ALBERODINATALE_COMPITO_H

#include <iostream>
using namespace std;


class AlberoDiNatale {

    char **albero;
    int numPiani;

public:
    AlberoDiNatale(int);
    void aggiungiPallina(const char, int, int);
    friend ostream& operator<< (ostream&, const AlberoDiNatale &);

    AlberoDiNatale& operator+=(int);
    char coloreMassimo() const;
    ~AlberoDiNatale();

};


#endif //TEST20_ALBERODINATALE_COMPITO_H
