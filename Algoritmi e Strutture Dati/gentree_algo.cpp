// solo quelle che cambiano
// (findnode per esempio è la stessa del classico)

int leaves(node* tree){
    if (!tree)return 0;
    if (!tree->left)return 1+leaves(tree->right); // le foglie stanno solo qui
    else return leaves(tree->left)+ leaves(tree->right);
}

void addson(int x, node* &tree){
    if (!tree){ //aggiunge il primo figlio
        tree=new node;
        tree->right=tree->left= nullptr;
        tree->info=x;
    }
    else addson(x,tree->right); //aggiunge il fratello
}

bool insertnode(int son,int father, node* &tree){
    node* a=findnode(father,tree);
    if (!a)return false;
    addson(son,a->left);
    return true;
}
