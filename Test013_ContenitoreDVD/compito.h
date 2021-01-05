//
// Created by danie on 05/01/2021.
//

#ifndef TEST13_CONTENITOREDVD_COMPITO_H
#define TEST13_CONTENITOREDVD_COMPITO_H

#include <iostream>
using namespace std;

struct dvd {
    bool isVirgin;
    char genre;
    dvd* nextDvd;
};

class ContenitoreDVD {

    dvd* p0;

public:
    ContenitoreDVD();
    ContenitoreDVD(const ContenitoreDVD &);

    void aggiungi();
    void aggiungi(const char);
    bool masterizza(const char);
    friend ostream& operator<<(ostream&, const ContenitoreDVD &);

    void elimina();
    int operator~() const;
    int operator%(const char) const;

    ~ContenitoreDVD();


};


#endif //TEST13_CONTENITOREDVD_COMPITO_H
