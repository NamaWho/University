/**
 * @author Daniel Namaki Ghaneh
 * @date 11/11/2020
 */

#include <iostream>
#include <cstring>

using namespace std;

int f(int);

void first();

void second();

struct elem;

void addItemAtTheBeginning(elem *&, int);

void addItemAtTheEnd(elem *&, int);

void stampa(elem *);

void third();

void fourth();

void inserisciOrdinato(elem *&, int);

void fifth();

//Number of rows and columns of the matrix in the given exercises
const int DIM = 3;

int main() {
    int choice;
    do {
        cout << "\nInserire la propria scelta: \n"
                "1 per Tutorial n.1 sull'uso del debugger\n"
                "2 per Tutorial n.2 sull'uso del debugger\n"
                "3 per Utilizzo del debugger\n"
                "4 per Serpente di numeri\n"
                "5 per Matrice trasposta\n"
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
                third();
                break;
            case 4:
                fourth();
                break;
            case 5:
                fifth();
                break;
            default:
                break;
        }
    } while (choice > 0 && choice < 6);
    return 0;
}

int f(int a) {
    a *= 2;
    return a;
}

void first() {

    int n;
    n = 2;

    int *p;
    p = &n;
    *p = 5;

    int &r = n;
    r = 9;

    int m = f(n);
    cout << n << " " << m << endl;
}

struct punto {
    float x;
    float y;
};

void second() {

    // definizione di due elementi di tipo "punto"
    punto p1;
    p1.x = 3.3;
    p1.y = 1.1;

    punto p2;
    p2 = p1;
    // definizione di un array di 3 interi
    int v[3];
    int i = 0;
    while (i < 3) {
        v[i] = i;
        i++;
    }

    // v[4] = 123; ERRORE! L'array definito sullo stack ha una capienza di 3 celle int.

    // definizione di una stringa
    char w[5];
    strcpy(w, "si");
    strcpy(w, "informatica");   // ERRORE! Out of bounds! Informatica viene stampato perché nonostante
                                       // il buffer overflow in lettura e scrittura stampa fino a che non trova
                                       // terminatore (nmel vettore di int inizializzato prima! essendo sullo stack)

    // stampa della stringa
    cout << w << endl;
}

void third() {

    int n;
    cout << "Inserisci n:" << endl;
    cin >> n;

    if (n < 1) {
        cout << "Numero non valido" << endl;
        return;
    }

    int *v = new int[n];
    cout << "Inserisci " << n << " numeri:" << endl;

    for (int i = 0; i < n; i++)
        cin >> v[i];

    int max = 0;

    for (int i = 0; i < n; i++)
        max = (v[i] > max) ? v[i] : max;

    for (int i = 0; i < n; i++)
        v[i] += max;

    int mul = v[0];

    for (int i = 1; i < n; i++)
        mul *= v[i];

    cout << "Risultato del calcolo:" << endl;
    cout << mul;
    delete v;
}

struct elem {
    int info;
    elem *pun;
};


void addItemAtTheBeginning(elem *&p0, int a) {
    elem *temp = new elem;

    temp->info = a;
    temp->pun = p0;
    p0 = temp;
}

void addItemAtTheEnd(elem *&p0, int a) {

    elem *p;
    elem *q;

    for (q = p0; q != 0; q = q->pun)
        p = q;

    q = new elem;
    q->info = a;
    q->pun = 0;

    if (p0 == 0) p0 = q;
    else p->pun = q;

}

void stampa(elem *p0) {
    for (; p0 != 0; p0 = p0->pun) {
        cout << p0->info << "\t";
    }
    cout << endl;
}


bool deleteItem(elem *&p0, int a) {
    if (p0 == 0) return false;
    elem *p = nullptr;
    elem *q;

    // Searches for the occurence and stops, otherwise keeps searching until the end
    // p = previous element
    // q = 'to be deleted' element
    for (q = p0; q != 0 && q->info != a; q = q->pun) {
        p = q;
    }

    if (q == p0)            // If the element is at the beginning
        p0 = q->pun;
    else p->pun = q->pun;

    delete q;  // Deallocate from the heap memory
    return true;

}


void fourth() {

    elem *p0 = nullptr;

    addItemAtTheBeginning(p0, 50);
    addItemAtTheEnd(p0, 60);
    addItemAtTheBeginning(p0, 70);

    stampa(p0);

    deleteItem(p0, 50);

    stampa(p0);
}

void inserisciOrdinato(elem *&p0, int n) {
    elem *p = 0, *q = 0;

    for (q = p0; q != 0 && q->info < n; q = q->pun) {
        p = q;
    }

    elem *temp = new elem;
    temp->info = n;
    temp->pun = q;

    if (q == p0) p0 = temp; // If the element must be inserted at the beginning
    else p->pun = temp;
}

void fifth() {
    int n;
    elem* p0 = nullptr;

    cout << "Inserire 6 numeri \n";

    for (int i = 0; i < 6; ++i) {
        cin >> n;
        inserisciOrdinato(p0, n);
    }

    stampa(p0);
}