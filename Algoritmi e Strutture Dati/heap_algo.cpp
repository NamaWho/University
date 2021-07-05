//heap

class Heap{
    int* h;
    int last;
    
    void up(int i){ //logn
        if (i>0){
            if (h[i]>h[(i-1)/2]){
                exchange(h[i],h[(i-1)/2]);
                up((i-1)/2);
            }
        }
    }
    
    void down(int i){ //logn
        int son=2*i +1;
        if (son==last){ //se sono su last
            if (h[son]>h[i]) exchange(h[i],h[last]); //va bene anche h[son] poichè son==last
        }
        else if (son<last){ //se sono su last
            if (h[son]<h[son+1])son++;
            if (h[son]>h[i]){
                exchange(h[i],h[son]);
                down(son);
            }
        }
    }
    //exchange (in questo file l'ho già definita fuori, ma di norma è un campo privato in questa classe)
public:
    Heap(int n){
        h=new int[n];
        last=-1;
    }
    ~Heap(){
        delete [] h;
    }
    void insert(int x){
        h[++last]=x;
        up(last);
    }
    int extract(){
        int r=h[0];
        h[0]=h[last--];
        down(0);
        return r;
    }
};


//heapsort

void exchange(int* h, int i , int j){
    int c=h[i];
    h[i]=h[j];
    h[j]=c;
}

void down(int* h,int i, int last){ //identica all'altra ma usata su un array
    int son=2*i +1;
    if (son==last){ //esattamente su last lo scambio
        if (h[son]>h[i])
            exchange(h,i,last);
    }
    else if (son<last){ //scabio prima di last
        if (h[son]<h[son+1])son++;
        if (h[son]>h[i]){
            exchange(h,i,son);
            down(h,son,last);
        }
    }
}

void buildHeap(int* A,int n){
    for (int i = n/2; i >=0 ; i--) {
        down(A,i,n);
    }
}

void extract(int* h, int & last){
    exchange(h,0,last--);
    down(h,0,last);
}

void heapSort(int* A, int dim){  //(nlogn)
    buildHeap(A,dim-1);
    int i=dim-1;
    while (i>0){
        extract(A,i);
    }
}

