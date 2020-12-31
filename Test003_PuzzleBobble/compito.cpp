//
// Created by danie on 24/12/2020.
//

#include "compito.h"

PuzzleBobble::PuzzleBobble() {

    for (int i = 0; i < ROW_DIM; ++i) {
        for (int j = 0; j < COL_DIM; ++j) {
            schema[i][j] = ' ';
        }
    }
}

ostream &operator<<(ostream &os, const PuzzleBobble &pb) {

    for (int i = 0; i < (COL_DIM + 2); ++i) {
        os << "=";
    }
    os << endl;
    for (int i = 0; i < ROW_DIM; ++i) {
        os << "|";
        for (int j = 0; j < COL_DIM; ++j) {
            os << pb.schema[i][j];
        }
        os << "|\n";
    }

    for (int i = 0; i < (COL_DIM + 2); ++i) {
        os << "=";
    }
    os << endl;

    return os;
}

PuzzleBobble &PuzzleBobble::fire(const int &index, const char &color) {
    if ((color != 'R' && color != 'G' && color != 'B' && color != 'Y') || // Color not acceptable
        (index < 0) || // Wrong index
        (index > COL_DIM - 1) || // Wrong index
        (schema[ROW_DIM - 1][index] != ' ') // Last free cell is already filled
            )
        return *this;

    int i;
    for (i = ROW_DIM - 2; i >= 0; --i) {
        if (schema[i][index] != ' ') break;
    }
    schema[i + 1][index] = color;

    if (countBubbles(i + 1, index, false) > 2)
        countBubbles(i + 1, index, true);

    return *this;
}

PuzzleBobble::operator int() {
    int maxBlock = 0;
    int currentBlock = 0;

    for (int i = 0; i < COL_DIM; ++i) {
        for (int j = 0; j < ROW_DIM; ++j) {
            if (schema[j][i] != ' ')
                currentBlock++;
            else {
                maxBlock = (currentBlock > maxBlock) ? currentBlock : maxBlock;
                currentBlock = 0;
                break;
            }
        }
    }

    return maxBlock;
}

int PuzzleBobble::countBubbles(int row, int column, bool pop) {

    int count = 1;
    char color = schema[row][column];

    if (pop) schema[row][column] = ' ';

    //Over the cell
    for (int i = row - 1; i >= 0; --i) {
        if (schema[i][column] == color) {
            if (pop) schema[i][column] = ' ';
            else count++;
        } else break;
    }

    //Left to the cell
    for (int i = (column - 1); i >= 0; --i) {
        if (schema[row][i] == color) {
            if (pop) schema[row][i] = ' ';
            else count++;
        } else break;
    }

    //Right to the cell
    for (int i = (column + 1); i < COL_DIM; ++i) {
        if (schema[row][i] == color) {
            if (pop) schema[row][i] = ' ';
            else count++;
        } else break;
    }

    return count;
}

PuzzleBobble &PuzzleBobble::scroll() {

    for(int j = 0; j < ROW_DIM; j++)
        if(schema[COL_DIM-1][j] != ' ')
            return *this;

    for (int i = 0; i < COL_DIM; ++i) {
        for (int j = (ROW_DIM - 1); j > 0; --j) {
            schema[j][i] = schema[j - 1][i];
        }
    }

    for (int i = 0; i < COL_DIM; ++i) {
        schema[0][i] = '=';
    }


    return *this;
}

void PuzzleBobble::compact() {

    for (int i = 0; i < COL_DIM; ++i) {
        for (int j = 0; j < ROW_DIM - 1; ++j) {
            if (schema[j][i] == ' ') {
                for (int k = j; k < ROW_DIM - 1; ++k) {
                    schema[k][i] = schema[k + 1][i];
                }
            }
        }
    }

}


