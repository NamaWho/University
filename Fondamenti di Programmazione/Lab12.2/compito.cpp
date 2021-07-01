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

    item *p, *q=0;

    for (p = p0; p != NULL && p->index <= index; p = p->nextItem) {
        q = p;
    }

    if ((p && (p == p0) && (p->index == index))){
        p->value = value;
        return;
    } else if (q && (q->index == index)) {
        q->value = value;
        return;
    }

    item *temp = new item;
    temp->index = index;
    temp->value = value;
    temp->nextItem = p;

    if (p == p0) p0 = temp;
    else q->nextItem = temp;

}

ostream &operator<<(ostream &os, const VettoreSparso &list) {

    item *p;

    os << "[" << list.maxDim << "]";
    os << "{";

    for (p = list.p0; p != NULL; p = p->nextItem) {
        os << "(" << p->value << "," << p->index << ")";
    }

    os << "}";

    return os;
}

void VettoreSparso::visualizzaComeDenso() const {
    item *p;
    int i;

    cout << "< ";

    for (p = p0, i = 0; p != NULL; p = p->nextItem) {
        if (i < p->index) {
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

    cout << ">";
}

void VettoreSparso::reset(int i) {
    item *p = 0, *q;

    for (q = p0; q != NULL && q->index < i; q = q->nextItem) {
        p = q;
    }

    if (!((p0 == 0) || (q->index > i))) {
        if (q == p0)
            p0 = q->nextItem;
        else
            p->nextItem = q->nextItem;
        delete q;
    }
}

void VettoreSparso::empty() {

    item *p;

    while (p0) {
        p = p0;
        p0 = p0->nextItem;
        delete p;
    }
}

VettoreSparso &VettoreSparso::operator*=(int k) {

    if (!k) empty();
    else {
        item *q;

        for (q = p0; q != NULL; q = q->nextItem) {
            q->value *= k;
        }
    }

    return *this;
}



