//
// Created by danie on 17/12/2020.
//

#ifndef LAB12_2_COMPITO_H
#define LAB12_2_COMPITO_H

#include <iostream>
using namespace std;

struct item {
    int value;
    int index;
    item* nextItem;
};

class VettoreSparso {
    item* p0;
    int maxDim;

    void empty();
    VettoreSparso(const VettoreSparso &);
    VettoreSparso& operator=(const VettoreSparso &);

public:
    VettoreSparso(int);
    void set(int, int);
    friend ostream &operator<<(ostream&, const VettoreSparso&);

    void visualizzaComeDenso() const;
    void reset(int i);
    VettoreSparso& operator*=(int k);
    ~VettoreSparso(){empty();};

};


#endif //LAB12_2_COMPITO_H
