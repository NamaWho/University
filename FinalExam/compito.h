// Namaki

#ifndef ESAMEPRATICOFDP_COMPITO_H
#define ESAMEPRATICOFDP_COMPITO_H

#include <iostream>
#include <cstring>
using namespace std;

const int MAX_NOME_LENGTH = 25;

struct piatto {
    char nome [MAX_NOME_LENGTH+1];
    unsigned int prezzo;
    piatto* nextPiatto;
};

class Nastro {
    piatto* p0;
    unsigned int conto;

    Nastro(const Nastro&);
    Nastro& operator=(const Nastro&);

    // Controlla se un piatto è presente. Se è presente, restituisce il prezzo, altrimenti -1
    int isPresente(const char*) const;

public:
    Nastro();
    void aggiungi(const char*, int);
    Nastro& consuma(const char*);
    friend ostream& operator<<(ostream& os, const Nastro &);

    Nastro &operator+= (const Nastro &);
    friend Nastro operator|(const Nastro &, const Nastro &);

    ~Nastro();

};


#endif