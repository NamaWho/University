//
// Created by danie on 03/12/2020.
//

#include <iostream>
#include "compito.h"
#include <cstring>

using namespace std;

/**
 * Constructor
 * @param n rows number
 * @param p number of seats per row
 * @param s cinema's name
 */
Cinema::Cinema(unsigned int n, unsigned int p, const char *s) {
    // Assigning values with sanitization via substitution
    this->dimRow = n > MAX_ROWS ? MAX_ROWS : n;
    this->dimSeats = p > MAX_SEATS ? MAX_SEATS : p;
    if (strlen(s) > MAX_NAMELENGHT) {
        strcpy(this->name, "DefaultName");
    } else strcpy(this->name, s);

    // Define matrix values
    for (int i = 0; i < dimRow; ++i) {
        for (int j = 0; j < dimSeats; ++j) {
            this->seats[i][j] = false;
        }
    }
}

/**
 * Book a seat if not already booked
 * @param l row letter
 * @param j seat number
 * @return
 */
bool Cinema::prenota(char l, unsigned int j) {

    j -= 1; // Conversion to zero based format
    l -= 'A';

    //Sanitization
    if (l > MAX_ROWS || j > MAX_SEATS)
        return false;

    if (this->seats[l][j] != true) {
        this->seats[l][j] = true;  // If the seat isn't already booked
        return true;
    }
    return false;
}

/**
 * Remove a booked seat if it isn't already free
 * @param l
 * @param j
 * @return
 */
bool Cinema::cancella(char l, unsigned int j) {

    j -= 1; // Conversion to zero based format
    l -= 'A';

    //Sanitization
    if (l > MAX_ROWS || j > MAX_SEATS)
        return false;

    if (this->seats[l][j] == true) {
        this->seats[l][j] = false;  // If the seat is booked, empty it
        return true;
    }
    return false;
}

/**
 * Print the matrix
 */
void Cinema::stampa() {

    cout << "Nome del cinema: " << this->name << endl;

    // Seat numbers print
    cout << " ";
    for (int i = 1; i <= dimSeats; ++i) cout << i;
    cout << "\n";

    // Row letter + row seats
    for (int i = 0; i < this->dimRow; ++i) {
        cout << char('A' + i);
        for (int j = 0; j < this->dimSeats; ++j) {
            if (this->seats[i][j] == true) cout << "*";
            else cout << " ";
        }
        cout << "\n";
    }
}

/**
 * Counts all the free seats
 * @return free seats number
 */
int Cinema::quantiLiberi() {
    unsigned int freeSeats = 0;

    for (int i = 0; i < this->dimRow; ++i) {
        for (int j = 0; j < this->dimSeats; ++j) {
            if (this->seats[i][j] == false) freeSeats++;
        }
    }

    return freeSeats;
}

/**
 * Book k adjacent seats if possibile
 * @param k
 * @return
 */
bool Cinema::prenotaAdiacenti(unsigned int k) {

    if (k > MAX_SEATS) return false;

    for (int i = 0; i < this->dimRow; ++i) {
        for (int j = 0; j < this->dimSeats; ++j) {
            if ((j+k-1) < this->dimSeats) {

                bool free = true;
                //Check if there are k adjacent seats
                for (int l = 0; l < k; ++l) {
                    if (this->seats[i][j+l]){
                        j += l; //skip free seats (before the one booked), which can't be booked
                                // because we found an already booked seat now
                        free = false;
                        break;
                    }
                }

                // Book those seats
                if (free){
                    for (int l = 0; l < k; ++l) {
                        this->seats[i][j+l] = true;
                    }
                }

            }

        }
    }

    return false;
}


