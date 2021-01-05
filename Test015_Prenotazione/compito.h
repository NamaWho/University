//
// Created by danie on 05/01/2021.
//

#ifndef TEST15_PRENOTAZIONE_COMPITO_H
#define TEST15_PRENOTAZIONE_COMPITO_H

#include <iostream>
using namespace std;

const int MAX_PARTICIPANTS = 5;

enum abbonamento {
    GOLD = 0,
    SILVER = 1
};

struct cliente {
    int id;
    abbonamento t;
    cliente* nextCliente;
};

struct Ammessi {
    cliente elenco[MAX_PARTICIPANTS];
    int quanti;
};

class Prenotazione {

    //Reservations List
    cliente* p0;
    bool isOpen;
    bool hasAlreadyBooked(int, bool, abbonamento = GOLD) const;

public:
    Prenotazione();
    void prenota(int, abbonamento);
    void cancella(int, abbonamento);
    friend ostream& operator<<(ostream&, const Prenotazione &);

    operator int() const;
    Ammessi chiudi();
    ~Prenotazione();
};


#endif //TEST15_PRENOTAZIONE_COMPITO_H
