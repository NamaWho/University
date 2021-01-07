//
// Created by danie on 07/01/2021.
//

#include "compito.h"
#include <iostream>
using namespace std;


AlberoDiNatale::AlberoDiNatale(int N) {
    numPiani = (N < 1) ? 1 : N;

    albero = new char* [numPiani];

    for (int i = 0; i < numPiani; ++i) {
        albero[i] = new char [numPiani-i];
        for (int j = 0; j < (numPiani-i); ++j) {
            albero[i][j] = '-';
        }
    }
}

void AlberoDiNatale::aggiungiPallina(const char p, int piano, int ramo) {
    if (p == '-' || (p != 'R' && p != 'B' && p != 'V') ||
        piano < 0 || piano > (numPiani-1) ||
        ramo < 0 || (ramo > (numPiani-piano)) ||
        albero[piano][ramo] != '-')
        return;

    if (ramo == 0 && (albero[piano][ramo+1] == p))
        return;
    else if ((ramo == (numPiani-piano-1)) && albero[piano][ramo-1] == p)
        return;
    else if (albero[piano][ramo+1] == p || albero[piano][ramo-1] == p)
        return;

    albero[piano][ramo] = p;
}

ostream &operator<<(ostream &os, const AlberoDiNatale &alb) {

    for (int i = alb.numPiani-1; i >= 0; --i) {

        for (int j = 0; j < i; ++j)
            os << " ";

        for (int j = 0; j < alb.numPiani-i; ++j)
            os << alb.albero[i][j] << " ";

        os << endl;
    }

    for (int i = 0; i < alb.numPiani-1; ++i) os << " ";
    os << "|\n";
    
    return os;
}

AlberoDiNatale &AlberoDiNatale::operator+=(int k) {
    if (k < 1) return *this;

    int newNumPiani = numPiani + k;

    char** temp;

    temp = new char*[newNumPiani];
    for (int p=0; p<newNumPiani; p++)
    {
        temp[p] = new char[newNumPiani-p];

        if (p<k)
            for (int r=0; r<newNumPiani-p; r++)
                temp[p][r] = '-';
        else
            for (int r=0; r<newNumPiani-p; r++)
                temp[p][r] = albero[p-k][r];
    }


    for (int i = 0; i < numPiani; ++i) {
        delete [] albero[i];
    }
    delete [] albero;

    numPiani = newNumPiani;
    albero = temp;

    return *this;
}

char AlberoDiNatale::coloreMassimo() const{

    int cR = 0, cV = 0, cB = 0;

    for (int i = 0; i < numPiani; ++i) {
        for (int j = 0; j < numPiani-i; ++j) {
            switch(albero[i][j]){
                case 'R':
                    cR++;
                    break;
                case 'V':
                    cV++;
                    break;
                case 'B':
                    cB++;
                    break;
            }
        }
    }

    return (cB > cV) ? ((cB > cR) ? 'B' : 'R') : ((cV > cR) ? 'V' : 'R');
}

AlberoDiNatale::~AlberoDiNatale() {

    for (int i = 0; i < numPiani; ++i) {
        delete [] albero[i];
    }
    delete [] albero;
}


