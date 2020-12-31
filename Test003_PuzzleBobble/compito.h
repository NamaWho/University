//
// Created by danie on 24/12/2020.
//

#ifndef TEST3_PUZZLEBOBBLE_COMPITO_H
#define TEST3_PUZZLEBOBBLE_COMPITO_H

#include <iostream>
using namespace std;

const int ROW_DIM = 10;
const int COL_DIM = 6;

class PuzzleBobble {

    char schema[ROW_DIM][COL_DIM];
    int countBubbles(int, int, bool);

public:
    PuzzleBobble();
    friend ostream& operator<<(ostream&,const PuzzleBobble &);
    PuzzleBobble& fire(const int &, const char &);
    operator int();
    PuzzleBobble& scroll();
    void compact();
};


#endif //TEST3_PUZZLEBOBBLE_COMPITO_H
