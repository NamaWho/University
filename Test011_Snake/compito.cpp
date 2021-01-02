//
// Created by danie on 02/01/2021.
//

#include "compito.h"

Snake::Snake(int row, int col) {

    r = (row < 4) ? 4: row;
    c = (col < 4) ? 4: col;

    snakeLength = 4;

    schema = new snakeCell [r*c];

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            schema[(i*c)+j].numCell = 0;
        }
    }

    for (int i = r-4, j = 1; i < r; ++i, j++) {
        schema[i*c].numCell = j;
        schema[i*c].iNext = (i != r-1) ? i+1 : -1;
        schema[i*c].jNext = (i != r-1) ? 0 : -1;
    }

    iHead = r-4;
    jHead = 0;
}

ostream &operator<<(ostream &os, const Snake &s) {

    os << "|";
    for (int i = 0; i < s.c; ++i) {
        os << "-";
    }
    os << "|\n";

    for (int i = 0; i < s.r; ++i) {
        os << "|";
        for (int j = 0; j < s.c; ++j) {
            if (s.schema[(i*s.c)+j].numCell > 0) os << s.schema[(i*s.c)+j].numCell;
            else if (s.schema[(i*s.c)+j].numCell == -1) os << "*";
            else os << " ";
        }
        os << "|\n";
    }

    os << "|";
    for (int i = 0; i < s.c; ++i) {
        os << "-";
    }
    os << "|";
    return os;
}

Snake& Snake::muovi(const char dir) {

    //Snake moving outside the schema or in an occupied cell or in the opposite way
    if (    (dir == 'n' && ((iHead == 0)     || (schema[(iHead-1)*c+jHead].numCell > 0) || (iHead-1 == schema[iHead*c+jHead].iNext))) ||
            (dir == 's' && ((iHead == (r-1)) || (schema[(iHead+1)*c+jHead].numCell > 0) || (iHead+1 == schema[iHead*c+jHead].iNext))) ||
            (dir == 'o' && ((jHead == 0)     || (schema[iHead*c+(jHead-1)].numCell > 0) || (jHead-1 == schema[iHead*c+jHead].jNext))) ||
            (dir == 'e' && ((jHead == (c-1)) || (schema[iHead*c+(jHead+1)].numCell > 0) || (jHead+1 == schema[iHead*c+jHead].jNext))) )
        return *this;

    int iRowOldHead = iHead;
    int jColOldHead = jHead;

    if (dir == 'n') iHead--;
    else if (dir == 's') iHead++;
    else if (dir == 'o') jHead--;
    else if (dir == 'e') jHead++;

    bool apple = (schema[iHead*c+jHead].numCell == -1) ? true : false;

    schema[iHead*c+jHead].numCell = 1;
    schema[iHead*c+jHead].iNext = iRowOldHead;
    schema[iHead*c+jHead].jNext = jColOldHead;

    int curI = iRowOldHead;
    int curJ = jColOldHead;
    int nextI, nextJ;

    for (int i = 1; i < snakeLength; ++i) {
        nextI = schema[curI*c+curJ].iNext;
        nextJ = schema[curI*c+curJ].jNext;

        schema[curI*c+curJ].numCell = schema[nextI*c+nextJ].numCell;

        curI = nextI;
        curJ = nextJ;
    }

    //Update last cell.
    if (apple && snakeLength < 9) {
        snakeLength++;
        schema[curI*c+curJ].numCell = snakeLength;
    }
    else schema[curI*c+curJ].numCell = 0;

    return *this;
}

Snake &Snake::mela(int i, int j) {

    if (i > 0 && i < r && j > 0 && j < c && schema[i*c+j].numCell != 0)
        return *this;

    schema[i*c+j].numCell = -1;

    return *this;
}

void Snake::inverti() {

    for (int i = 0; i < snakeLength; ++i) {

    }
}
