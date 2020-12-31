//
// Created by danie on 28/12/2020.
//

#ifndef TEST7_TARTAGLIA_COMPITO_H
#define TEST7_TARTAGLIA_COMPITO_H

#include <iostream>
using namespace std;

class Tartaglia {

    int order;
    int *triangle;

    void destroy();

    Tartaglia();
    Tartaglia(const Tartaglia &);

public:
    Tartaglia(int);
    friend ostream& operator<<(ostream&, const Tartaglia &);
    int fibonacci(int) const;

    void espandi(int) const;
    Tartaglia& operator= (const Tartaglia&);
    ~Tartaglia(){destroy();};

};


#endif //TEST7_TARTAGLIA_COMPITO_H
