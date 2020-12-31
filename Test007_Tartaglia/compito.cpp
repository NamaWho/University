//
// Created by danie on 28/12/2020.
//

#include "compito.h"
#include <iostream>
#include <iomanip>
using namespace std;

Tartaglia::Tartaglia(int ord) {
    order = (ord < 0) ? 0 : ord;
    triangle = new int [(order+1)*(order+1)];

    triangle[0] = 1;

    for (int i = 1; i < (order+1); ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j ==  0 || j == i) triangle[(order+1)*i+j] = 1;
            else triangle[(order+1)*i + j] = triangle[((order+1)*(i-1))+j] + triangle[((order+1)*(i-1))+j-1];
        }
    }
}

ostream &operator<<(ostream &os, const Tartaglia & tart) {

    for (int i = 0; i < (tart.order+1); ++i) {
        for (int j = 0; j <= i; ++j) {
            os << setw(5) << tart.triangle[(tart.order+1)*i+j];
        }
        os << "\n";
    }

    return os;
}

int Tartaglia::fibonacci(int n) const {
    if (n > order || n < 0) return -1;
    int fib = 0;

    for (int i = n, j = 0; i >= (n+1)/2; --i, j++) {
        fib += triangle[(order+1)*i+j];
    }

    return fib;
}

void Tartaglia::espandi(int n) const {
    if (n > order) return;
    if (!n) {
        cout << "{1}";
        return;
    }

    cout << "{";
    for (int a = n, b = 0; a >= 0 ; --a, ++b) {
        if (a && b) cout << triangle[(order+1)*n+b];

        if (a) cout << "a^" << a;
        if (b) cout << "b^" << b;
        if (a) cout << " + ";
    }
    cout << "}";
}

Tartaglia &Tartaglia::operator=(const Tartaglia & t) {

    if (this == &t || order == t.order) return *this;

    order = t.order;
    destroy();

    triangle = new int [(order+1)*(order+1)];

    for (int i = 0; i < (order+1); ++i) {
        for (int j = 0; j <= i; ++j) {
            triangle[(order+1)*i + j] = t.triangle[(order+1)*i+j];
        }
    }

    return *this;
}

void Tartaglia::destroy() {
    delete [] triangle;
}
