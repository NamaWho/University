#include <iostream>

using namespace std;


void stampaTriangoloRettangolo(int n) {

    cout << "Triangolo Rettangolo\n";
    // Stampa del triangolo rettangolo con due cicli for
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i + 1; ++j) {
            cout << "*  ";
        }
        cout << "\n";
    }
}

void stampaTriangoloRettangoloRov(int n) {

    cout << "\nTriangolo Rettangolo rovesciato\n";
    // Stampa del triangolo rettangolo rovesciato
    for (int i = n; i > 0; --i) {
        // Stampa spazi vuoti
        // Il numero degli spazi vuoti equivale alla differenza
        // tra n (lato) e i (asterischi da stampare)
        for (int k = 0; k < n - i; ++k) {
            cout << "   ";
        }
        //Stampa asterischi
        for (int j = i; j > 0; --j) {
            cout << "*  ";
        }
        cout << "\n";
    }
}

void stampaTriangoloIsosceleRov(int n) {

    cout << "Triangolo isoscele rovesciato \n";

    for (int i = n; i > 0; i -= 2) {
        // Stampa spazi vuoti
        for (int j = 0; j < (n - i) / 2; ++j) {
            cout << "   ";
        }
        // Stampo asterischi
        for (int k = i; k > 0; --k) {
            cout << "*  ";
        }
        cout << "\n";
    }
}

void stampaTriangoloIsosceleRuot(int n) {

    cout << "Triangolo isoscele ruotato \n";

    for (int i = 0; i < n; ++i) {
        //If the half of the triangle has been passed
        if (i > n / 2) {
            // (n/2)-(i-(n/2)) = Difference of the half of the triangle minus the number of rows passed after the half,
            // which determines how many * the cycle will print
            for (int j = n / 2 - (i - (n / 2)); j >= 0; --j) {
                cout << "*  ";
            }
        } else {
            // i+1 represents the number of * to print in the (i+1)° row
            for (int j = 0; j < i + 1; j++) {
                cout << "*  ";
            }
        }
        cout << endl;
    }
}


/**
 *  Es. 4.1 – Triangoli
 *  Scrivere un programma C++ che:
 *  - legga un numero intero n>0 da tastiera;
 *  - mostri a video un triangolo rettangolo di asterischi, avente lato n;
 *  - mostri a video un triangolo rettangolo rovesciato di asterischi, avente lato n.
 *
 * Es. 4.2 – Triangoli 2 (per casa)
 * Scrivere un programma C++ che:
 * - legga un numero intero n>0 dispari da tastiera;
 * - mostri a video un triangolo isoscele rovesciato avente come base n.
 * - mostri a video un triangolo isoscele ruotato verso destra avente come base n
 */
void firstTwoExercises() {
    int n, choice = -1;

    while (choice != 0) {
        cout << "Menu operazioni: \n"
                "1 per Triangolo Rettangolo \n"
                "2 per Triangolo Rettangolo Rovesciato\n"
                "3 per Triangolo Isoscele Rovesciato\n"
                "4 per Triangolo Isoscele Ruotato\n"
                "0 per uscire\n"
                "Scelta?\n";
        cin >> choice;

        if (choice > 0 && choice < 5) {
            //Insert of the triangle side
            do {
                cout << "Lato? \n";
                cin >> n;
                if (n < 0) cout << "Il numero inserito e' negativo.\n";
                else if ((choice == 3 || choice == 4) && (n % 2 == 0))
                    cout << "Per questo triangolo inserire un numero dispari.\n";
            } while (n < 0 || ((choice == 3 || choice == 4) && (n % 2 == 0)));

            switch (choice) {
                case 1:
                    stampaTriangoloRettangolo(n);
                    break;
                case 2:
                    stampaTriangoloRettangoloRov(n);
                    break;
                case 3:
                    stampaTriangoloIsosceleRov(n);
                    break;
                case 4:
                    stampaTriangoloIsosceleRuot(n);
                    break;
                default:
                    break;
            }
        }
    };
}


/**
 * Stampa la riga della matrice
 * @param r indice riga
 * @param d dimensione riga
 */
void stampa_riga(int r, int d) {
    for (int j = 1; j <= d; ++j) {
        cout << r * j << "    ";
    }
}

/**
 * Scrivere un programma C++ che:
 * - Legga un numero intero n>0 da tastiera;
 * - mostri a video una tavola pitagorica di ordine n.
 * - La tavola pitagorica è una matrice di numeri in cui il numero che si trova nella posizione
 *   individuata dalla riga i e dalla colonna j è il prodotto 𝑖 × 𝑗.
 */
void second() {
    int n;

    do {
        cout << "Ordine della tavola? \n";
        cin >> n;
        if (n < 0) cout << "Il numero inserito e' negativo.\n";
    } while (n < 0);

    //Stampa tavola pitagorica
    for (int i = 1; i <= n; ++i) {
        // Chiamata a funzione per stampare la riga,
        // passando indice e dimensione totale della riga
        stampa_riga(i, n);
        cout << "\n";
    }
}

/**
 * Calcola il minimo di tre numeri interi
 * @param a
 * @param b
 * @param c
 */
int min(int a, int b, int c) {
    int min = a;
    if (min > b) min = b;
    if (min > c) min = c;
    return min;
}

/**
 * Calcola il massimo di tre numeri interi
 * @param a
 * @param b
 * @param c
 */
int max(int a, int b, int c) {
    int max = a;
    if (max<b) max = b;
    if (max<c) max = c;
    return max;
}

/**
 * Calcola la media di tre numeri interi
 * @param a
 * @param b
 * @param c
 */
float avg(int a, int b, int c) {
    return ((a + b + c) / 3.0);
}

/**
 *Es. 4.4 – Menù operazioni
Scrivere un programma C++ che:
 - mostri il menù
 - legga da tastiera un numero intero che esprime la scelta dell’utente;
 - termini se l’utente ha scelto 0. Altrimenti legga da tastiera tre numeri interi, esegua
   l’operazione prescelta (minimo, massimo o media) su di essi, e mostri a video il risultato.
   Gestire anche il caso di scelta non valida;
 - mostri nuovamente il menù, fino a che l’utente non sceglie di uscire (digitando 0)
 */
void third() {
    int choice = -1, a, b, c;
    while (choice != 0) {
        cout << "Menu operazioni: \n"
                "1 per minimo di tre interi \n"
                "2 per massimo di tre interi\n"
                "3 per media di tre interi\n"
                "0 per uscire\n"
                "Scelta?\n";
        cin >> choice;
        if (choice > 0 && choice < 4) {
            cout << "Inserire tre interi: \n";
            cin >> a >> b >> c;

            switch (choice) {
                case 1:
                    cout << "Il minimo di questi tre numeri e' " << min(a, b, c) << endl;
                    break;
                case 2:
                    cout << "Il massimo di questi tre numeri e' " << max(a, b, c) << endl;
                    break;
                case 3:
                    cout << "La media di questi tre numeri e' " << avg(a, b, c) << endl;
                    break;
                default:
                    break;
            }
        }
    };
}

int main() {
    int choice;
    do {
        cout << "\nInserire la propria scelta: \n"
                "1 per Triangoli \n"
                "2 per Tavola pitagorica\n"
                "3 per Menu' operazioni\n"
                "Altro numero per uscire\n";
        cin >> choice;
        switch (choice) {
            case 1:
                firstTwoExercises();
                break;
            case 2:
                second();
                break;
            case 3:
                third();
                break;
            default:
                break;
        }
    } while (choice > 0 && choice < 4);

    return 0;
}
