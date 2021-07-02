#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

// Exchange function
void exchange(int& a,int& b){
    int c=a;
    a=b;
    b=c;
}

// Part I
// MCD, MCD con Euclide, Setaccio di Eratostene, Stringa Palindroma

// MCD
int mcd(int x,int y){
    while (x != y)
        if (x < y)
            y = y-x;
        else
            x = x-y;
    return x;
}

// MCD con Euclide
int mcd_euclide(int x,int y){
    while (y!=0){
        int k=x;
        x=y;
        y=k%y;
    }
    return x;
}

// Setaccio di Eratostene per i numeri primi
void setaccio(int n){
    bool primi[n];

    primi[0]= false;
    primi[1]= false;

    for (int i = 2; i < n; ++i) { //inizializza
        primi[i] = true;
    }

    int i=1;
    for (i++; i*i<n ; ++i) { //scorre a partire da 2 (gli altri sono sicuramente primi)
        while (!primi[i])
            i++; //cerca il prossimo possibile primo

        for(int k = i*i; k <n ;k+=i) { //scorri i numeri successivi a partire da i*i, cancellando i multipli
            primi[k] = false;
        }

        for (int j = 2; j < n ; ++j) {
            if (primi[j])cout<<j<<endl; //stampa i numeri primi
        }
    }
}

// Stringa Palindroma
int palindroma(char* a, int i=0, int j=0){
    if (j<i)
        return 1;

    if (a[i]==a[j])
        return palindroma(a,i+1,j-1);

    return 0;
}

// Fibonacci

// Fibonacci I
// Complessità: 2^n
int fibonacci1(int n){
    if (n==0)
        return 0;
    if (n==1)
        return 1;
    return fibonacci1(n-1) + fibonacci1(n-2);
}

// Fibonacci II
// Complessità: n
int fibonacci2(int n) {
    int k;
    int j = 0;
    int f = 1;
    for (int i=1; i<=n; i++){
        k = j;
        j = f;
        f = k+j;
    }
    return j;
}

// Fibonacci Recursivo III
// Complessità: n
int fibonacci_r(int n, int a=0, int b=1){

    if(n==0)
        return a;
    return
        fibonacci_r(n-1,b,a+b);
}
