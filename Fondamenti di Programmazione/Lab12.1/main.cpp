#include <iostream>
#include <fstream>

using namespace std;

void first();

void second();

void third();

int main() {
    int choice;
    do {
        cout << "\nInserire la propria scelta: \n"
                "1 per File 1\n"
                "2 per File 2\n"
                "3 per File 3\n"
                "Altro numero per uscire\n";
        cin >> choice;
        switch (choice) {
            case 1:
                first();
                break;
            case 2:
                second();
                break;
            case 3:
                //third();
                break;
            default:
                break;
        }
    } while (choice > 0 && choice < 4);
    return 0;
}

void first() {

    fstream input;

    // First part
    input.open("interi.txt", ios::out);

    if (!input) {
        cout << "Error while opening 'interi.txt' \n";
        exit(1);
    }

    input << 13 << ' ' << 7 << ' ' << 4;

    input.close();

    // Second part
    input.open("interi.txt", ios::out | ios::app);

    if (!input) {
        cout << "Error while opening 'interi.txt' \n";
        exit(1);
    }

    input << ' ' << 16 << '.';

    input.close();
}

void second() {
    fstream input, output;
    int temp, sum = 0, items = 0;


    input.open("interi.txt", ios::in);
    if (!input) {
        cout << "Error while opening 'interi.txt' \n";
        exit(1);
    }
    output.open("output.txt", ios::out);
    if (!output) {
        cout << "Error while opening 'output.txt' \n";
        exit(1);
    }

    while (input >> temp) {
        sum += temp;
        items++;
    }

    bool eof = input.eof();
    bool fail = input.fail();
    input.clear();

    char point;
    input >> point;

    if (eof) output << "Errore! Il file non termina con un punto.\n";
    else if (fail) {
        if (point == '.') {
            output << "Numero dei valori letti: " << items << endl;
            output << "Valore medio dei dati letti: " << (double) (sum / items) << endl;
        } else
            output << "Errore! Il file deve contenere interi e terminare con un punto";
    }

    input.close();
    output.close();
}

