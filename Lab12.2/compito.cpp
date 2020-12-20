//
// Created by danie on 17/12/2020.
//

#include "compito.h"

VettoreSparso::VettoreSparso(int d) {
    maxDim = (d < 1) ? 1 : d;
    p0 = 0;
}

void VettoreSparso::set(int value, int index) {
    if (index < 0 || index > maxDim || value == 0) return;

    item *p, *q;

    for (p = p0; p != NULL && p->index <= index; p = p->nextItem) {
        q=p;
    }

    item* temp = new item;
    temp->index = index;
    temp->value = value;
    temp->nextItem = p;

    if (p == p0) p0 = temp;
    else q->nextItem = temp;

}

ostream &operator<<(ostream &cout, const VettoreSparso & list) {

    item* p;

    cout << "[" << list.maxDim << "]";
    cout << "{";

    for (p = list.p0;  p != NULL; p = p->nextItem) {
        cout << "(" << p->value << "," << p->index << ")";
    }

    cout << "}" << endl;

    return cout;
}

void VettoreSparso::visualizzaComeDenso() const {
    item* p;
    int i;

    cout << "< ";

    for (p = p0, i = 0; p != NULL ; p = p->nextItem) {
        if (i < p->index){
            do {
                cout << "0 ";
                i++;
            } while (i != p->index);
        }
        cout << p->value << " ";
        i++;
    }

    for (; i < maxDim; i++) {
        cout << "0 ";
    }

    cout << ">" << endl;
}
