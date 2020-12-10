//
// Created by danie on 10/12/2020.
//

#include "compito.h"
#include <iostream>

using namespace std;

/**
 * Constructor
 * @param N maximum number of floors
 */
Palazzo::Palazzo(unsigned int N) {
    maxPiani = (N == 0) ? 1 : N;
    numPiani = 0;
    finestre = new bool *[N];
    aggiungi(); // add the first window
}

/**
 * Copy constructor
 * @param p entity to copy
 */
Palazzo::Palazzo(const Palazzo &p) {
    maxPiani = p.maxPiani;
    numPiani = p.numPiani;
    finestre = new bool *[maxPiani];

    //Copy of windows state
    for (int i = 0; i < p.numPiani; ++i) {
        finestre[i] = new bool[i + 1];
        for (int j = 0; j < (i + 1); ++j) {
            finestre[i][j] = p.finestre[i][j];
        }
    }
}

/**
 * Add a new floor
 * @return
 */
bool Palazzo::aggiungi() {
    if (numPiani == maxPiani) return false;

    numPiani++;
    finestre[numPiani - 1] = new bool[numPiani];    // Initialize the floor array for it windows

    for (int i = 0; i < numPiani; ++i) {            // Initialize windows as closed
        finestre[numPiani - 1][i] = false;
    }

    return true;
}

/**
 * Print the building
 */
void Palazzo::stampa() {
    cout << "<" << numPiani << "> \n";

    for (int i = 0; i < numPiani; ++i) {
        cout << "Piano " << (i + 1) << ": ";
        for (int j = 0; j < (i + 1); ++j) {
            if (finestre[i][j]) cout << "Aperta ";
            else cout << "Chiusa ";
        }
        cout << "\n";
    }
}

/**
 * Destructor
 */
Palazzo::~Palazzo() {
    for (int i = 0; i < numPiani; ++i) {
        delete [] finestre[i];              // Deallocate windows of each floor
    }
    delete[] finestre;                      // Deallocate floors
}

/**
 * Change windows state via given indexes [floor][window]
 * @param f floor index
 * @param w window index
 */
bool Palazzo::cambia(unsigned int f, unsigned int w) {
    if (f == 0 || w == 0 || f > numPiani || w > f) return false;

    finestre[f - 1][w - 1] = !finestre[f - 1][w - 1];       // Change window's state
    return true;
}

/**
 * Returns the number of open windows
 * @return
 */
int Palazzo::operator!() {
    int tot = 0;
    for (int i = 0; i < numPiani; ++i) {
        for (int j = 0; j < (i + 1); ++j) {
            if (finestre[i][j]) tot++;
        }
    }
    return tot;
}

/**
 * Compare the entities and close the window of this->finestre[i][j] if the same window is closed in p1
 * @param p1 entity to compare
 * @return
 */
bool Palazzo::operator%=(Palazzo p1) {
    if (this->numPiani != p1.numPiani) return false;

    for (int i = 0; i < numPiani; ++i) {
        for (int j = 0; j < (i + 1); ++j) {
            // Close window if the same window in p1 is closed
            if (finestre[i][j] && !(p1.finestre[i][j])) finestre[i][j] = !finestre[i][j];
        }
    }

    return true;
}











