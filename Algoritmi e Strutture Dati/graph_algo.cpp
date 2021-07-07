/// Grafi

// To be fixed

const int N=6;
class Graph{

    struct Node{
        int label;
        //int arcLabel;
        Node* next;
    };

    Node* list[N]; //per liste di adiacenza, int graph [N][N]; per le matrici di adiacenza
    int nodi[N]; //salvo le etichette dei nodi distinti (la posizione in questo array è legata all'array mark[N])
    int mark[N]; //quelli effettivamente marcati

    void nodeVisit(int i){
        mark[i]=1;
        cout<<' '<<nodi[i]<<':'<<i;
        Node* g;
        int j;
        for (g = list[i]->next; g ;g = g->next) { //fa prima il next perchè l'altro l'ha già visitato
            j=g->label;
            if (!mark[j])
                nodeVisit(g->label);
        }
    }
public:
    void depthVisit(){    //(n+a)
        for (int i = 0; i < N; ++i) {
            mark[i]=0;
        }
        for (int i = 0; i < N; ++i) {
            if (!mark[i]) nodeVisit(i);
        }
    }
};
