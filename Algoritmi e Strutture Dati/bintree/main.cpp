// Libraries
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <fstream>
#include <math.h>       /* floor */
#include <stdlib.h>
#include <cmath>        /* pow  */
using namespace std;

// Binary Tree
struct Node
{
    int value;
    Node * left;
    Node * right;

    Node( int i ): value(i) , left(NULL) , right(NULL) {}
};

class BinTree
{
    Node * root_;
public:

    BinTree() { root_ = NULL ; }

    Node * getRoot() { return root_; cout << "getRoot" << endl;}

    void insert( int i )
    {
        Node * node = new Node(i);

        Node * pre = NULL;
        Node * post = root_;
        while( post != NULL)
        {
            pre = post;
            if( i <= post->value )
            {
                post = post->left;
            }
            else
            {
                post = post->right;
            }
        }

        if( pre == NULL )
            root_ = node;
        else if( i <= pre->value )
        {
            pre->left = node;
        }
        else
        {
            pre->right = node;
        }
        return;

    }
};

// --------------------------METODO ESTERNO DA AGGIUNGERE--------------------------

// Somma dei nodi concordi. Si intende concorde un nodo che ha etichetta pari (o dispari) identicamente al padre.
int sommaConcordi(Node* root, int dad = -1){
    if(!root) return 0;
    int value = 0;
    if (dad == -1 || (root->value%2 == dad%2)) value = root->value;
    return sommaConcordi(root->left, root->value) + sommaConcordi(root->right, root->value) + value;
}

// Sommatoria dei nodi con altezza dispari meno la sommatoria dei nodi con altezza pari
int diffSommeNodiDispariPari(Node* root, int level = 0){
    if (!root) return 0;
    int val = root->value;
    return (level%2==0 ? -val : val) + diffSommeNodiDispariPari(root->left, level+1) + diffSommeNodiDispariPari(root->right, level+1);
}

int sommaNodiPariNoFoglie(Node* root, int level = 0){
    if(!root || (!root->left && !root->right)) return 0;
    int val = !level ? 0 : (level%2 == 0 ? root->value : 0);
    return val + sommaNodiPariNoFoglie(root->left, level + 1) + sommaNodiPariNoFoglie(root->right, level+1);
}


int altezza(Node* root){
    if (!root) return 0;
    return 1 + max(altezza(root->left), altezza(root->right));
}
int prodottoAltezzeSottoalberi(Node* root){
    if (!root) return 0;
    return altezza(root->left) * altezza(root->right);
}

int sommaConcordi2(Node* root, int level = 0){
    if (!root) return 0;
    int val = root->value%2 == level%2 ? root->value : 0;
    return val + sommaConcordi2(root->left, level + 1) + sommaConcordi2(root->right, level + 1);
}

bool search(Node* root, int k){
    if (!root) return false;
    if (root->value == k) return true;
    return search(root->left, k) || search(root->right, k);
}

void MinMax(Node* root, int &min, int &max){
    if (!root) return;
    min = root->value < min ? root->value : min;
    max = root->value > max ? root->value : max;
    MinMax(root->left, min, max);
    MinMax(root->right, min, max);
}
int sommaMinMax(Node* root){
    int min = INT_MAX;
    int max = INT_MIN;
    MinMax(root, min, max);
    return min+max;
}

int sommaNodiCompleti(Node* root, int level = 1){
    if (!root) return 0;
    int val;
    if (root->left && root->right && level%2 != 0) val = root->value;
    else val = 0;
    return val + sommaNodiCompleti(root->left, level+1) + sommaNodiCompleti(root->right, level+1);
}
//=======================================MAIN======================================

int main()
{
    int N ;
    int x ;
    BinTree albero ;

    cin >> N ;

    // Inserimento elementi nell' albero
    for(int i=0 ; i<N ; ++i )   {
        cin >> x;
        albero.insert(x);
    }

    // --------------------------CHIAMATA AL METODO----------------------------

    cout << sommaConcordi(albero.getRoot()) << endl;
    cout << diffSommeNodiDispariPari(albero.getRoot()) << endl;
    cout << sommaNodiPariNoFoglie(albero.getRoot()) << endl;
    cout << prodottoAltezzeSottoalberi(albero.getRoot()) << endl;
    cout << sommaConcordi2(albero.getRoot()) << endl;
    cout << sommaMinMax(albero.getRoot()) << endl;
    cout << sommaNodiCompleti(albero.getRoot()) << endl;
    // ------------------------------------------------------------------------
}



