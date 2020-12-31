//
// Created by danie on 29/12/2020.
//

#ifndef TEST8_TIMELINE_COMPITO_H
#define TEST8_TIMELINE_COMPITO_H

#include <iostream>

using namespace std;


struct photo {
    char *name;
    bool highlighted;
    photo *nextPhoto;
};

class Timeline {
    photo *p0;

public:

    Timeline();

    void pubblica(const char*, bool);

    void cancella(const char*);

    friend ostream &operator<<(ostream &, const Timeline &);

    bool operator!();

    void mettiInEvidenza(const char *);

    ~Timeline();
};


#endif //TEST8_TIMELINE_COMPITO_H
