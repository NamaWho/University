#ifndef LAB10_COMPITO_H
#define LAB10_COMPITO_H

const int MAX_ROWS = 26;
const int MAX_SEATS = 9;
const int MAX_NAMELENGHT = 31;

class Cinema {

    char name[MAX_NAMELENGHT];
    bool seats[MAX_ROWS][MAX_SEATS];
    int dimRow, dimSeats;

public:
    Cinema(unsigned int n, unsigned int p, const char *s);

    bool prenota(char l, unsigned int j);

    bool cancella(char l, unsigned int j);

    void stampa();

    int quantiLiberi();

    bool prenotaAdiacenti(unsigned int k);
};


#endif //LAB10_COMPITO_H
