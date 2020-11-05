#include <iostream>

using namespace std;

/**
 * Scrivere un programma C++ che:
 * - chieda all’utente di inserire due numeri non negativi b ed e;
 * - mostri a video il risultato di b^e
 * Gestire i casi di e=0 e b=0
 */
void first() {
    int b, e, i = 0, res = 1;

    do {
        cout << "Inserire il numero NON NEGATIVO b: \n";
        cin >> b;
        if (b < 0) cout << "Il numero inserito e' negativo.\n";
    } while (b < 0);

    do {
        cout << "Inserire il numero NON NEGATIVO e: \n";
        cin >> e;
        if (e < 0) cout << "Il numero inserito e' negativo.\n";
    } while (e < 0);

    if (b == 0 && e == 0) cout << "Risultato indefinito\n";
    else {
        while (i < e) {
            res *= b;
            i++;
        }
        cout << b << " elevato alla " << e << " vale: " << res;
    }
}

/**
 * Es. 3.2 – Massimo comun divisore (MCD)
 * Scrivere un programma C++ che:
 * - chieda all’utente di inserire da tastiera due numeri interi positivi m e n;
 * - mostri a video il massimo comun divisore, calcolato secondo l’algoritmo di Euclide.
 * L’algoritmo di Euclide sottrae il numero più piccolo a quello più grande, ripetendo l’operazione
 * tante volte finché i due numeri non assumono valore uguale. Tale valore sarà l’MCD. Di seguito
 * due esempi di esecuzione dell’algoritmo.
 */
void second() {
    int m, n, m1, m2;

    do {
        cout << "Inserire il numero positivo m: \n";
        cin >> m;
        if (m < 0) cout << "Il numero inserito e' negativo.\n";
    } while (m < 0);

    do {
        cout << "Inserire il numero positivo n: \n";
        cin >> n;
        if (n < 0) cout << "Il numero inserito e' negativo.\n";
    } while (n < 0);

    cout << "Il Massimo Comune Divisore tra " << m << " e " << n << " e': ";

    while (m != n) {
        if (m > n)
            m -= n;
        else n -= m;
    }

    cout << m << endl;
}

/**
 * Es. 3.3 – Maschere di bit
 * Scrivere un programma C++ che:
 * - chiede in ingresso un numero naturale n su 16 bit (utilizzare il tipo unsigned short int);
 * - genera una maschera M1, avente il bit in posizione n a 1 e tutti gli altri bit a 0;
 * - stampa il valore numerico della maschera;
 * - genera una maschera M2, avente il bit in posizione n a 0 e tutti gli altri bit a 1;
 * - stampa il valore numerico della maschera.
 * Nota: Il primo bit della maschera è quello meno significativo e ha posizione 0, il secondo 1, ecc.
 */
void third(){
    unsigned short int n, m1=1, m2=1;
    cout << "Inserire il numero naturale n: \n";
    cin >> n;
    m1 = m1 << n;
    m2 = ~(m2 << n);
    cout << "Valore numerico della maschera M1: " << m1 << endl;
    cout << "Valore numerico della maschera M2: " << m2 << endl;
}

/**
 * Es. 3.4 – Codifica binaria
 * Scrivere un programma C++ che:
 * - chiede in ingresso un intero senza segno x;
 * - stampa a video la sua codifica binaria.
 */
void fourth(){
    unsigned int x;
    cout << "Digita un numero senza segno: \n";
    cin >> x;
    cout << "La sua codifica binaria e': ";

    for (int i = (sizeof(unsigned int)*8)-1; i >= 0; --i) {
        if(x & (1u << i)) cout << 1;
        else cout << 0;
    }
    cout << endl;
}

/**
 * Es. 3.5 – Quadrati
 * Scrivere un programma C++ che:
 * - chieda in ingresso un numero naturale n;
 * - stampi un quadrato n x n di asterischi;
 * - stampi un quadrato n x n vuoto di asterischi
 */
void fifth(){
    int m;

    do {
        cout << "Base quadrato? \n";
        cin >> m;
        if (m < 0) cout << "Il numero inserito e' minore di 1.\n";
    } while (m <= 0);

    cout << "Stampo quadrato di base " << m << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << "*  ";
        }
        cout << endl;
    }

    cout << "\nStampo quadrato vuoto di base " << m << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!(i > 0 && i < (m-1) && j > 0 && j < (m-1)))
                cout << "*  ";
            else cout << "   ";
        }
        cout << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "Inserire la propria scelta: \n"
                "1 per Elevamento a Potenza \n"
                "2 per MCD\n"
                "3 per Maschere di Bit\n"
                "4 per Codifica Binaria\n"
                "5 per Quadrati\n"
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
    } while (choice > 0 && choice < 5);
    return 0;
}
