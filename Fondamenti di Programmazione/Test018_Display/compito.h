//
// Created by danie on 07/01/2021.
//

#ifndef TEST18_DISPLAY_COMPITO_H
#define TEST18_DISPLAY_COMPITO_H

#include <iostream>
using namespace std;

class Display {

    int r, c;
    char **display;
    int cursore;

public:
    Display(int, int);
    Display(const Display &);
    void writeT(const char *);
    friend ostream& operator<<(ostream&, const Display &);

    void writeW(char *);
    Display& operator=(const Display &);
    ~Display();

};


#endif //TEST18_DISPLAY_COMPITO_H
