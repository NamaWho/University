/**
 * @author Daniel Namaki Ghaneh
 * @date 05/11/2020
 */

#include <iostream>
#include <cstring>

using namespace std;


double massimo(const double *, unsigned int);
void first();

int posMinimo(const double vett[], unsigned int dim);
void second();

bool pari(const int v[], unsigned int n);
void third();

void concatena(const int *v1, const int *v2, unsigned int n1, unsigned int n2, int *v3);
void fourth();

bool palindroma(const char stringa[]);
void fifth();

int contaParole(const char stringa[]);
void sixth();

void my_strcat (char dest[], char src[]);
void seventh();

int main() {
    int choice;
    do {
        cout << "\nInserire la propria scelta: \n"
                "1 per Massimo in vettore\n"
                "2 per Posizione minimo in vettore\n"
                "3 per Somma pari di vettore\n"
                "4 per Concatena vettori\n"
                "5 per Stringa palindroma\n"
                "6 per Conta parole in una C-stringa\n"
                "7 per Concatena stringhe\n"
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
            case 7:
                seventh();
                break;
            default:
                break;
        }
    } while (choice > 0 && choice < 8);
    return 0;
}

/**
 * Calculates the maximum value inside the array
 * @param vett pointer to the first index of the array
 * @param l length  of the array
 * @return
 */
double massimo(const double *vett, unsigned int l) {
    double max = *vett;
    for (int i = 1; i < l; ++i) {
        if (max < *(vett + i)) max = *(vett + i);
    }
    return max;
}

void first() {
    double vett[] = {1.3, 4.5, 2.4, 8.4, -3.14, -3.14};
    const unsigned int length = 6;
    cout << "Il valore massimo presente nel vettore e': " << massimo(vett, length) << " \n";
}

/**
 * Determines the position of the minimum value inside the array
 * @param vett pointer to the first index of the array
 * @param dim length  of the array
 * @return
 */
int posMinimo(const double vett[], unsigned int dim) {
    int posMin = 0;
    for (int i = 1; i < dim; ++i) {
        if (!(vett[posMin] == vett[i]) && vett[i] < vett[posMin])
            posMin = i;
    }
    return posMin;
}

void second() {
    double vett[] = {1.3, 4.5, 2.4, 8.4, -3.14, -3.14};
    const unsigned int length = 6;
    cout << "La posizione del primo minimo all'interno del vettore e': " << posMinimo(vett, length) << " \n";
}

/**
 * Determines if the sum of the array elements is odd or even
 * @param v
 * @param n
 * @return
 */
bool pari(const int v[], unsigned int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += v[i];
    }
    if (sum % 2) return true;
    return false;
}

void third() {
    const unsigned int dim = 10;
    int vett[dim];
    bool even;

    cout << "Inserire 10 elementi interi dell'array\n";

    for (int i = 0; i < dim; ++i) {
        cin >> vett[i];
    }

    even = pari(vett, dim);
    cout << "\nLa somma degli interi inseriti e' ";
    if (even) cout << "PARI\n";
    else cout << "DISPARI\n";
}

/**
 *
 * @param v1 1st array
 * @param v2 2nd array
 * @param n1 1st array size
 * @param n2 2nd array size
 * @param v3 3d array
 */
void concatena(const int *v1, const int *v2, unsigned int n1, unsigned int n2, int *v3) {
    for (int i = 0; i < n1; ++i) {
        v3[i] = v1[i];
    }
    for (int i = n1, j = 0; j < n2; ++i, j++) {
        v3[i] = v2[j];
    }
}

void fourth() {
    const unsigned int dim1 = 2, dim2 = 3, dim3 = dim1 + dim2;
    int vett1[] = {2, 6}, vett2[] = {3, 15, 4};
    int vett3[dim3];
    concatena(vett1, vett2, dim1, dim2, vett3);

    cout << "Il vettore concatenato è: \n";
    for (int i = 0; i < dim3; ++i) {
        cout << vett3[i] << endl;
    }
}
/**
 * Determine if the word is palindrome
 * @param stringa
 * @return
 */
bool palindroma(const char stringa[]){
    int l = strlen(stringa);

    for (int i = 0; i < l/2; ++i) {
        if (stringa[i] != stringa[l-1-i])
            return false;
    }
    return true;
}

void fifth(){
    const unsigned int dim = 40;
    char stringa[dim];

    cout << "Inserire parola: \n";
    cin >> stringa;

    if (palindroma(stringa)) cout << "La parola e' palindroma\n";
    else cout << "La parola non e' palindroma\n";
}

/**
 * Count of the words in the given sentence
 * @param stringa
 * @return count
 */
int contaParole(const char stringa[]){
    unsigned int count = 0;
    for (int i = 0; i < strlen(stringa); ++i) {
        if (stringa[i] != ' ') {
            while (stringa[i] != ' ') {
                i++;
            }
            count++;
        }
    }
    return count;
}

void sixth(){
    const unsigned int dim = 40;
    char stringa[dim];

    cout << "Numero di parole della prima C-stringa: " << contaParole("Lorem ipsum  dolor   sit amet  ") << endl;
    cout << "Numero di parole della seconda C-stringa: " << contaParole("  Lorem ipsum  dolor   sit amet  ") << endl;

}

/**
 * Concat two strings
 * @param dest destination array
 * @param src source array
 */
void my_strcat (char dest[], char src[]){
    for (int i = strlen(dest), j = 0; j < strlen(src); ++i, ++j) {
        dest[i] = src[j];
    }
}

void seventh(){
    char dest[40] = "Fondamenti di ", src[] = "Programmazione";
    cout << "Contenuto C-stringa dest prima della concatenazione: " << dest << endl;
    cout << "Contenuto C-stringa sorg: " << src << endl;

    my_strcat(dest, src);

    cout << "Il nuovo contenuto della C-Stringa dest, dopo la concatenazione, e': " << dest;
}