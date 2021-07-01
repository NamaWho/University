//
// Created by danie on 31/12/2020.
//

#ifndef TEST10_MONITOR_COMPITO_H
#define TEST10_MONITOR_COMPITO_H

#include <iostream>
using namespace std;

const int MAX_CONTENT = 10;

class Monitor {

    char **messages;
    int index;
    const int MAX_MESSAGE;

public:

    Monitor(const int);
    void inserisci(const char *);
    friend ostream& operator<<(ostream&, const Monitor &);

    Monitor(const Monitor &);
    Monitor operator+(const Monitor &);
    ~Monitor();

};


#endif //TEST10_MONITOR_COMPITO_H
