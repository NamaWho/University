//
// Created by danie on 30/12/2020.
//

#ifndef TEST9_GESTOREAPP_COMPITO_H
#define TEST9_GESTOREAPP_COMPITO_H

#include <iostream>
#include <cstring>

using namespace std;

const int MAX_NAME = 20;

struct app {
    char name [MAX_NAME+1];
    app* nextApp;
};

class GestoreApp {
    app* p0;

    bool isPresent(const char *) const;

public:

    GestoreApp();
    GestoreApp& operator+= (const char *);
    friend ostream& operator<<(ostream&, const GestoreApp &);

    void foreground(const char *);
    GestoreApp& operator-= (const char *);
    void chiudi_tutte();
    ~GestoreApp();

};


#endif //TEST9_GESTOREAPP_COMPITO_H
