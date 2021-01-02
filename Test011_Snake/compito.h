//
// Created by danie on 02/01/2021.
//

#ifndef TEST11_SNAKE_COMPITO_H
#define TEST11_SNAKE_COMPITO_H

#include <iostream>
using namespace std;

struct snakeCell {
    int numCell;
    //Coordinates of the next cell
    int iNext;
    int jNext;
};

class Snake {

    snakeCell *schema;
    int r, c;
    int snakeLength;
    int iHead;
    int jHead;

public:
    Snake(int, int);
    friend ostream& operator<<(ostream &, const Snake &);
    Snake& muovi(const char);
    Snake& mela(int, int);
    void inverti();
};


#endif //TEST11_SNAKE_COMPITO_H
