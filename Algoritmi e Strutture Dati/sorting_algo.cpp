// Quelli basati sui confronti non scendono più di nlogn

// BubbleSort
// Complessità: n^2
// Scambi: n^2
void bubbleSort(int *vett, int n) {
    for (int i = 0; i < n; ++i) {
        for(int j = n-1; j > i; j--){
            if(vett[j-1] > vett[j])
                exchange(vett[j-1],vett[j]);
        }
    }
}

// Selection Sort Iterativo e Ricorsivo

// Iterativo
// Complessità: n^2
// Scambi: n
void selectionSort(int* vett, int n) {
    for (int i = 0; i < n; ++i) {
        int min = i;
        for (int j = i+1; j < n; ++j)
            if(vett[j]<vett[min]) min = j;
        exchange(vett[i],vett[min]);
    }
}

// Ricorsivo
// Iterativo
// Complessità: n^2
void r_selectionSort (int* vett, int m, int i=0){
    if (i == m - 1)
        return;
    int min = i;
    for (int j = i + 1; j < m; ++j) {
        if(vett[j] < vett[min])
            min = j;
        exchange(vett[i], vett[min]);
        r_selectionSort(vett, m, i+1);
    }

}

// InsertionSort Iterativo e Ricorsivo

// Iterativo
// Complessità: n^2 n^2 n
void insertionSort(int a[],int len){
    int mano=0;
    int occhio=0;
    for (int i = 1; i < len; ++i) {
        mano=a[i];
        occhio=i-1;
        while (occhio>=0 && a[occhio]>mano){
            a[occhio+1]=a[occhio];
            --occhio;
        }
        a[occhio+1]=mano;
    }
}

// Ricorsivo
void ins(int* a, int dim,int i=1){
    if (i<dim) {
        int mano = a[i];
        int occhio = i - 1;
        while (occhio >= 0 && a[occhio] > mano) {
            a[occhio + 1] = a[occhio];
            --occhio;
        }
        a[occhio + 1] = mano;
        ins(a, dim,++i);
    }
}


// QuickSort
// Complessità caso peggiore: n^2
// Complessità caso medio/migliore: nlogn
void quicksort(int A[], int inf, int sup){
    int perno=A[(inf+sup)/2];
    int s=inf;
    int d=sup;
    while (s<=d){
        while (A[s]<perno)s++;
        while (A[d]>perno)d--;
        if (s>d)break;
        exchange(A[s],A[d]);
        s++;
        d--;
    }
    if (inf<d)quicksort(A,inf,d);
    if (s<sup)quicksort(A,s,sup);
}


// MergeSort sulle liste (
// mergeSort: nlogn
// split e merge: n
struct Elem {
    int info;
    Elem* next;
};

void split(Elem* & s1, Elem* &s2){
    if (!s1 || !(s1->next))return; //se è vuota s1 o c'è un solo elemento, non mi serve andare avanti
    Elem* p=s1->next;
    s1->next=p->next;
    p->next=s2;
    s2=p;
    split(s1->next,s2);
}

void merge(Elem* &s1, Elem* &s2){
    if (!s2)return;
    if (!s1){
        s1=s2;
        return;}
    if (s1->info<=s2->info) merge(s1->next,s2);
    else {merge(s2->next,s1);
        s1=s2;}
}

void mergeSort(Elem* & s1){
    if (!s1 || !(s1->next))return;
    Elem* s2= nullptr;
    split(s1,s2);
    mergeSort(s1);
    mergeSort(s2);
    merge(s1,s2);
}

// MergeSort su Array
void merge(int* v, int inf, int sup) {
    int aux[++sup];

    for(int i = 0; i < sup; i++)
        aux[i] = v[i];

    int i, a, b, mean;
    i = a = inf;
    b = mean = 1 + (inf+sup-1)/2;

    while(a < mean && b < sup)
        v[i++] = (aux[a] < aux[b]) ? aux[a++] : aux[b++];

    while(a < mean)
        v[i++] = aux[a++];
    while(b < sup)
        v[i++] = aux[b++];
}

void mergeSort(int *v, int inf, int sup) {
    if(inf == sup)
        return;

    int mean = (inf+sup)/2;

    mergeSort(v, inf, mean);
    mergeSort(v,mean+1, sup);
    merge(v, inf, sup);
}

// CountingSort (n+k)
void countingsort(int A[],int k, int n){
    int C[k+1]; int i ,j;
    for (i = 0; i <=k; ++i) {
        C[i]=0;
    }
    for (j = 0; j < n;j ++) {
        C[A[j]]++;
    }
    j=0;
    for (i = 0; i<=k ; i++) {
        while (C[i]>0){
            A[j]=i;
            C[i]--;
            j++;
        }
    }
}

// RadixSort  (d(n+k))
void bucketSort(int *v, int n, int b, int t) {
    std::queue<int> bucket[b];
    for (int i = 0; i < n; ++i) {
        int c = (v[i]/t)%10;
        bucket[c].push(v[i]);
    }
    int j = 0;
    for (int i = 0; i < b; ++i) {
        while(!bucket[i].empty()){
            v[j++] = bucket[i].front();
            bucket[i].pop();
        }
    }
}
void bucket(int* v, int n, int b, int t){
    elem* bucket[b];
    for (int i = 0; i < b; i++) bucket[i] = nullptr;
    for (int i = 0; i < n; ++i) {
        int c = (v[i]/t)%10;
        if(!bucket[c]){
            bucket[c] = new elem(v[i]);
        }else {
            elem *last = bucket[c];
            while(last->next) last = last->next;
            last->next = new elem(v[i]);
        }
    }
    int j = 0;
    for (int i = 0; i < b; ++i) {
        while(bucket[i]){
            v[j++] = bucket[i]->info;
            elem* aux = bucket[i];
            bucket[i] = aux->next;
            delete aux;
        }
    }
}
void radixSort(int *v, int n) {
    int t = 1;
    while(check(v,n,t)){
        bucket(v,n,10,t);
        t*=10;
    }
}
bool check(int *v, int n, int t) {
    for (int i = 0; i < n; ++i) {
        if((v[i]/t)%10) return true;
    }
    return false;
}
