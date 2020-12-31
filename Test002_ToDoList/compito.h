//
// Created by danie on 23/12/2020.
//

#ifndef TEST2_TODOLIST_COMPITO_H
#define TEST2_TODOLIST_COMPITO_H

#include <iostream>

using namespace std;

const int MAX_DIM_DESC = 40;

struct compito {
    char desc[MAX_DIM_DESC+1];
    unsigned int priority;
    bool isDone;
    compito* nextCompito;
};

class ToDoList {
    compito* p0;

    ToDoList(const ToDoList &);
    ToDoList& operator=(const ToDoList&);

public:
    ToDoList();
    void aggiungi(const char*, unsigned int);
    friend ostream& operator<< (ostream&, const ToDoList &);
    ~ToDoList();
    ToDoList& operator+=(const ToDoList &);
    void fai(const char*);
    void cancella_fatti();
};


#endif //TEST2_TODOLIST_COMPITO_H
