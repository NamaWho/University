
//codice di Huffman (implementabile con minheap)

//sarebbe da implementare un minheap di cui ogni cella è un possibile albero binario 
struct node{
    char lettera;
    int frequenza;
    node* left;
    node* right;
};
 node* huffman(Heap h, int dim){
    for (int i = 0; i < dim-1; ++i) {
        node* t=new node();  //probabilmente si è scordato che non ha implementato la parte default della struct (anche perchè non si è fatto a lezione stlib)
        t->left=h.extract();
        t->right=h.extract();
        t->frequency=t->left->frequency+t->right->frequency;
        h.insert(t);//inserisce il sottoalbero aggiornato nel minheap
    }
    return h.extract(); //ritorna la radice dell'albero
}

// In addition, Dijkstra algorithm is considered a greedy algorith as well
// By the way, implementation in c++ is not required yet
