/**
 * @author Daniel Namaki Ghaneh
 * @date 11/11/2020
 */

#include <iostream>

using namespace std;

void componenti_negative(const int vett[], const unsigned int l, int *&newVect, unsigned int &lengthNewVect);

void first();

int somma_diag(const int mat[][3]);

void second();

int somma_diag(const int *mat, int n);

void third();

int *riempi_matrice(int r, int c);

void fourth();

int* trasposta(const int* matr, int n);

void fifth();

//Number of rows and columns of the matrix in the given exercises
const int DIM = 3;

int main() {
    int choice;
    do {
        cout << "\nInserire la propria scelta: \n"
                "1 per Creazione vettore sullo heap\n"
                "2 per Somma diagonali\n"
                "3 per Somma diagonali (versione 2)\n"
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

void componenti_negative(const int vett[], const unsigned int l, int *&newVect, unsigned int &lengthNewVect) {

    // Negative numbers count
    for (int i = 0; i < l; ++i)
        if (vett[i] < 0) lengthNewVect++;

    // Allocation in the heap memory of the new array
    newVect = new int[lengthNewVect];

    // Set the new array
    for (int i = 0, j = 0; i < l; ++i) {
        if (vett[i] < 0) {
            newVect[j] = vett[i];
            j++;
        }
    }
}

void first() {
    const unsigned int LENGTH = 6;
    const int v[LENGTH] = {11, -22, 4, -3, 18, -1};

    unsigned int lengthVettNeg = 0; // Length which will be passed by reference to the function and will be modified inside it
    int *vettNeg = nullptr;         // To be sure, always initialize the pointer to nullptr

    componenti_negative(v, LENGTH, vettNeg, lengthVettNeg);

    cout << "Vettore di partenza: " << endl;
    for (int i = 0; i < LENGTH; ++i) {
        cout << v[i] << " ";
    }
    cout << endl;

    cout << "Nuovo vettore con sole componenti negative: " << endl;
    for (int i = 0; i < lengthVettNeg; ++i) {
        cout << vettNeg[i] << " ";
    }
    cout << endl;
    cout << "Deallocazione del vettore creato dallo Heap \n";

    delete[] vettNeg;
    vettNeg = nullptr;
}


int somma_diag(const int mat[][DIM]) {
    int sum = 0;
    for (int i = 0; i < DIM; ++i) {
        for (int j = 0; j < DIM; ++j) {
            // Sum if it's a cell located in the principal diagonal
            // or in the secondary one (where i+j = DIM-1)
            if ((i == j) || (i + j == (DIM - 1)))
                sum += mat[i][j];
        }
    }
    return sum;
}

void second() {
    int m[DIM][DIM];

    cout << "Inserisci 9 interi: \n";
    for (int i = 0; i < DIM; ++i) {
        for (int j = 0; j < DIM; ++j) {
            cin >> m[i][j];
        }
    }

    cout << "La somma degli elementi sulla diag. princ. e sec. e': " << somma_diag(m) << "\n";
}

int somma_diag(const int *mat, const int n) {
    int sum = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // Sum if it's a cell located in the principal diagonal
            // or in the secondary one
            if ((i == j) || (i + j == (n - 1)))
                sum += mat[i * n + j];
        }
    }

    return sum;
}

void third() {
    int m[DIM][DIM];

    cout << "Inserisci 9 interi: \n";
    for (int i = 0; i < DIM; ++i) {
        for (int j = 0; j < DIM; ++j) {
            cin >> m[i][j];
        }
    }

    cout << "La somma degli elementi sulla diag. princ. e sec. e': " << somma_diag(&m[0][0], DIM) << "\n";
}

int *riempi_matrice(int r, int c) {
    int *mat = new int[r * c];
    unsigned int count = 0;

    // Fill the matrix
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            // If odd row,  print number in the reverse order
            if (i % 2) mat[i * c + ((c-1) - j)] = ++count; //prefixed increment
            // If even, print them normally in order
            else mat[i * c + j] = ++count; //prefixed increment
        }
    }

    return mat;
}

void fourth() {

    int r, c;
    int *matrix = nullptr;

    cout << "Inserire R: \n";
    do {
        cin >> r;
    } while (r < 1);

    cout << "Inserire C: \n";
    do {
        cin >> c;
    } while (c < 1);

    // Store the dynamic matrix first address in a pointer
    matrix = riempi_matrice(r, c);

    // Print the matrix
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << matrix[i * c + j] << "\t";
        }
        cout << "\n";
    }

    delete[] matrix;
    matrix = nullptr;
}

int* trasposta(const int* matr, const int n){
    int *transposed = new int [n*n]; // Create a new matrix in the heap memory

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            //Inverting indexes to transpose the matrix
            transposed[i*n+j] = matr[j*n+i];
        }
    }

    return transposed;
}

void fifth(){

    int matrix [DIM][DIM];
    int *matTransposed = nullptr;

    cout << "Inserisci 9 interi: \n";
    for (int i = 0; i < DIM; ++i) {
        for (int j = 0; j < DIM; ++j) {
            cin >> matrix[i][j];
        }
    }

    // Print the matrix
    cout << "Matrice di partenza: \n";
    for (int i = 0; i < DIM; ++i) {
        for (int j = 0; j < DIM; ++j) {
            cout << matrix[i][j]<< "\t";
        }
        cout << "\n";
    }

    //Retrieve the transposed matrix
    matTransposed = trasposta(&matrix[0][0], DIM);

    //Print the transposed matrix
    cout << "\nMatrice trasposta: \n";
    for (int i = 0; i < DIM; ++i) {
        for (int j = 0; j < DIM; ++j) {
            cout << matTransposed[i*DIM+j]<< "\t";
        }
        cout << "\n";
    }
}