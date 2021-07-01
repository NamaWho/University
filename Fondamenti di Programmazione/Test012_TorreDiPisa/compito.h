//
// Created by danie on 04/01/2021.
//

#ifndef TEST12_TORREDIPISA_COMPITO_H
#define TEST12_TORREDIPISA_COMPITO_H

#include <iostream>
using namespace std;

struct loggiato {
    bool isPresent;
    unsigned int pend;
};

class TorreDiPisa {

    loggiato* torre;
    int maxLoggiati;
    int loggiati;

    bool isEmpty() const;
    bool isMovePossible() const;
    int relativePend();

    TorreDiPisa(const TorreDiPisa & );

public:
    TorreDiPisa (unsigned int);

    TorreDiPisa& operator+= (const int );

    friend ostream& operator<<(ostream&, const TorreDiPisa &);

    operator int() const;

    TorreDiPisa operator++(int);



};


#endif //TEST12_TORREDIPISA_COMPITO_H
