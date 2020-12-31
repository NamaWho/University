//
// Created by danie on 31/12/2020.
//

#include "compito.h"
#include <cstring>
#include <iostream>
using namespace std;

Monitor::Monitor(const int N) : MAX_MESSAGE(N < 1 ? 3 : N) {
    messages = new char* [MAX_MESSAGE];
    index = -1;
}

void Monitor::inserisci(const char *str) {
    if (str == NULL || strlen(str) < 1) return;

    if (index != (MAX_MESSAGE-1))
        messages[++index] = new char [MAX_CONTENT+1];
    else {
        for (int i = 0; i < index; ++i) {
            strncpy(messages[i],messages[i+1], MAX_CONTENT);
        }
    }
    strncpy(messages[index], str, MAX_CONTENT);
    messages[index][MAX_CONTENT] = '\0';
}

ostream &operator<<(ostream &os, const Monitor & m) {

    os << "[" << m.MAX_MESSAGE << "]\n";

    for (int i = m.index; i >= 0; --i) {
        os << m.messages[i] << "\n";
    }


    return os;
}

Monitor::Monitor(const Monitor & m) : MAX_MESSAGE(m.MAX_MESSAGE) {
    messages = new char* [MAX_MESSAGE];
    index = m.index;

    for (int i = 0; i <= index; ++i) {
        messages[i] = new char [MAX_CONTENT+1];
        strcpy(messages[i], m.messages[i]);
    }
}

Monitor Monitor::operator+(const Monitor & m) {

    Monitor temp(m.MAX_MESSAGE+MAX_MESSAGE);

    for (int i = 0; i <= index; ++i) {
        temp.inserisci(messages[i]);
    }

    for (int j = 0; j <= m.index; j++) {
        temp.inserisci(m.messages[j]);
    }


    return temp;
}

Monitor::~Monitor() {

    for (int i = 0; i < index; ++i) {
        delete [] messages[i];
    }
    delete [] messages;
}

