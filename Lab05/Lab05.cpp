/**
 * @author Daniel Namaki Ghaneh
 * @date 29/10/2020
 */

#include <iostream>
#include <cmath>

using namespace std;

/**
 * Duplicate the int parameter passed as a reference
 * @param i
 */
void raddoppia(int &i) {
    cout << "Dentro raddoppia() Valore del parametro: " << i << endl;
    i *= 2;
    cout << "Dentro raddoppia() Valore del parametro raddoppiato: " << i << endl;
    cout << "Dentro raddoppia() Indirizzo del parametro: " << &i << endl;
}

/**
 * Es. 5.1 – Riferimenti
 * Scrivere una funzione void raddoppia(...) che ha come argomento una variabile di tipo intero e ne
 * raddoppia il valore. La funzione stampa anche l’indirizzo della variabile ed il suo valore prima e
 * dopo il raddoppio.
 * Scrivere un programma che accetta un intero da tastiera, ne stampa l’indirizzo, chiama la funzione
 * per raddoppiarne il valore, e ne stampa il nuovo valore.
 */
void first() {
    int n;
    cout << "Numero? \n";
    cin >> n;
    cout << "Indirizzo di n: " << &n << endl;
    raddoppia(n);
    cout << "Nuovo valore di n: " << n << endl;
}
/**
 * Multiply by three the variable passed with the reference to the pointer
 * @param pt
 */
void triplica(int *ptr){
    *ptr *= 3;
}
/**
 * Es. 5.2 – Puntatori 1
 * Scrivere una funzione che calcola e restituisce il triplo di una variabile del chiamante. La funzione
 * non deve lavorare direttamente sulla variabile del chiamante, ma indirettamente, mediante una
 * variabile puntatore che punti ad essa.
 * La funzione main che chiama tale funzione deve creare una variabile intera, leggerne il contenuto
 * da tastiera, e poi invocare in modo opportuno la suddetta funzione e stampare a video il risultato
 * ritornato.
 */
void second(){
    int n;
    cout << "Numero? \n";
    cin >> n;
    triplica(&n);
    cout << "Numero triplicato: " << n;
}

/**
 * Scrivere una funzione f(…) che ha come argomento un puntatore a intero. Sia n il valore
 * dell’oggetto puntato. La funzione stampa il valore del puntatore ed il valore dell’oggetto puntato,
 * dopodiché restituisce come ritorno di funzione:
 * - il quadrato di n se n è multiplo di 2;
 * - il cubo di n se n è multiplo di 3;
 * - altrimenti il numero n.
 *
 * @param nptr
 * @return int
 */
int f(int *nptr){
    cout << "Dentro f(): Valore puntatore: " << nptr << "\n";
    cout << "Dentro f(): Valore oggetto puntato: " << *nptr << "\n";
    if (!(*nptr % 2)) return pow(*nptr, 2);
    if (!(*nptr % 3)) return pow(*nptr, 3);
    return *nptr;
}

/**
 * Es. 5.3 – Puntatori 2
 * Scrivere un programma che:
 * - chiede un numero da tastiera;
 * - stampa a video l’indirizzo a cui tale numero è memorizzato;
 * - chiama la funzione f(…) sul numero; e
 * - stampa a video il ritorno della funzione.
 */
void third(){
    int n, res;
    cout << "Numero? \n";
    cin >> n;
    cout << "Indirizzo in memoria: " << &n << "\n";
    res = f(&n);
    cout << "Il risultato e': " << res << "\n";
}

/**
 * Scrivere una funzione void inizializzaP(...) che ha come argomento un puntatore a intero. La
 * funzione inizializza a NULL il puntatore.
 * @param ptr
 */
void inizializzaP(int* &ptr){
    ptr = NULL;
}

/**
 * Es. 5.4 – Puntatori 3
 * Scrivere un programma che crea una variabile intera k ed
 * una variabile puntatore p che inizialmente punta a k. Successivamente invocare la funzione che
 * deve modificare il valore della variabile puntatore p assegnandogli NULL.
 * Stampare il valore del puntatore prima e dopo la chiamata della funzione
 */
void fourth(){
    int k, *p;
    cout << "P non inizializzato: " << p << "\n";
    p = &k;
    cout << "Indirizzo di k: " << &k << "\n";
    cout << "P punta a k: " << p << "\n";
    inizializzaP(p);
    cout << "P inizializzato a NULL: " << p << "\n";
}

/**
 * Scrivere la fuzione calcolaStatistiche(…) che, dati tre interi in ingresso, restituisca tre valori: il
 * minimo, il massimo, ed il valor medio (quest'ultimo deve essere un valore reale, non intero)
 * @param a
 * @param b
 * @param c
 * @param min
 * @param max
 * @param avg
 */
void calcolaStatistiche(int a,int b,int c,int &min,int &max,double &avg){
    min = (a < b) ? ((a < c) ? a : c ) : ((b < c) ? b : c);
    max = (a > b) ? ((a > c) ? a : c ) : ((b > c) ? b : c);
    avg = (a+b+c)/3.0;
}

/**
 * Es. 5.5 – Funzione con valori di ritorno multipli
 */
void fifth(){
    int a,b,c,min,max;
    double avg;

    cout << "Inseririre A: \n";
    cin >> a;
    cout << "Inseririre B: \n";
    cin >> b;
    cout << "Inseririre C: \n";
    cin >> c;

    //Passing by reference three variables which will be modified
    calcolaStatistiche(a,b,c,min,max,avg);

    cout << "Il minimo e' " << min << "\n";
    cout << "Il massimo e' " << max << "\n";
    cout << "La media e' " << avg << "\n";
}

/**
 * Scrivere una funzione restituisciPrimoValorePari(…) che restituisce (se esiste) il primo valore pari
 * tra tre interi passati come argomento
 * @param a
 * @param b
 * @param c
 */
int restituisciPrimoValorePari(int a, int b, int c){
    if (!(a % 2)) return a;
    if (!(b % 2)) return b;
    if (!(c % 2)) return c;
    return -1;
}
/**
 * Es. 5.6 – Funzione con risultato non sempre significativo
 * Scrivere un programma che legga da tastiera una sequenza di tre interi, chiami la funzione su di
 * essi, e mostri a video il primo valore pari fra quelli inseriti. Nel caso non ve ne sia neanche uno,
 * deve stampare a video "Nessun numero pari presente nella sequenza inserita".
 */
void sixth(){
    int a,b,c, res;

    cout << "Inseririre A: \n";
    cin >> a;
    cout << "Inseririre B: \n";
    cin >> b;
    cout << "Inseririre C: \n";
    cin >> c;

    res = restituisciPrimoValorePari(a,b,c);
    if (res == -1)
        cout << "Nessun numero pari presente nella sequenza inserita\n";
    else cout << "Il primo numero pari della sequenza e': " << res << "\n";
}

int main() {
    int choice;
    do {
        cout << "\nInserire la propria scelta: \n"
                "1 per Riferimenti\n"
                "2 per Puntatori 1\n"
                "3 per Puntatori 2\n"
                "4 per Puntatori 3\n"
                "5 per Puntatori Funzione con valori di ritorno multipli\n"
                "6 per Funzione con risultato non sempre significativo\n"
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
            case 6:
                sixth();
                break;
            default:
                break;
        }
    } while (choice > 0 && choice < 7);
    return 0;
}
